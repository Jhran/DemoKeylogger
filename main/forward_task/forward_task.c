#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "tinyusb.h"
#include "class/hid/hid_device.h"

#include "Decoder/CH9350/CH9350_decode.h"
#include "configKeylogger.h"

extern EventGroupHandle_t uart_semaphore;
extern volatile char uart_data[KEYLOGGER_UART_RX_BUFFER_SIZE];

static const char *TAG = "Forward";

/************* TinyUSB descriptors ****************/

#define TUSB_DESC_TOTAL_LEN (TUD_CONFIG_DESC_LEN + CFG_TUD_HID * TUD_HID_DESC_LEN)

/**
 * @brief HID report descriptor
 *
 * In this example we implement Keyboard + Mouse HID device,
 * so we must define both report descriptors
 */
const uint8_t hid_report_descriptor[] = {
    TUD_HID_REPORT_DESC_KEYBOARD(HID_REPORT_ID(HID_ITF_PROTOCOL_KEYBOARD)),
    TUD_HID_REPORT_DESC_MOUSE(HID_REPORT_ID(HID_ITF_PROTOCOL_MOUSE))
};

/**
 * @brief String descriptor
 */
const char *hid_string_descriptor[5] = {
    // array of pointer to string descriptors
    (char[]){0x09, 0x04},    // 0: is supported language is English (0x0409)
    "TinyUSB",               // 1: Manufacturer
    "TinyUSB Device",        // 2: Product
    "123456",                // 3: Serials, should use chip ID
    "Example HID interface", // 4: HID
};

/**
 * @brief Configuration descriptor
 *
 * This is a simple configuration descriptor that defines 1 configuration and 1 HID interface
 */
static const uint8_t hid_configuration_descriptor[] = {
    // Configuration number, interface count, string index, total length, attribute, power in mA
    TUD_CONFIG_DESCRIPTOR(1, 1, 0, TUSB_DESC_TOTAL_LEN, TUSB_DESC_CONFIG_ATT_REMOTE_WAKEUP, 100),

    // Interface number, string index, boot protocol, report descriptor len, EP In address, size & polling interval
    TUD_HID_DESCRIPTOR(0, 4, false, sizeof(hid_report_descriptor), 0x81, 16, 10),
};

/********* TinyUSB HID callbacks ***************/

// Invoked when received GET HID REPORT DESCRIPTOR request
// Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
uint8_t const *tud_hid_descriptor_report_cb(uint8_t instance)
{
    // We use only one interface and one HID report descriptor, so we can ignore parameter 'instance'
    return hid_report_descriptor;
}

// Invoked when received GET_REPORT control request
// Application must fill buffer report's content and return its length.
// Return zero will cause the stack to STALL request
uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t *buffer, uint16_t reqlen)
{
    (void)instance;
    (void)report_id;
    (void)report_type;
    (void)buffer;
    (void)reqlen;

    return 0;
}

// Invoked when received SET_REPORT control request or
// received data on OUT endpoint ( Report ID = 0, Type = 0 )
void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const *buffer, uint16_t bufsize)
{
}

void usb_device_init()
{
    const tinyusb_config_t tusb_cfg = {
        .device_descriptor = NULL,
        .string_descriptor = hid_string_descriptor,
        .string_descriptor_count = sizeof(hid_string_descriptor) / sizeof(hid_string_descriptor[0]),
        .external_phy = false,
        .configuration_descriptor = hid_configuration_descriptor,
    };

    ESP_ERROR_CHECK(tinyusb_driver_install(&tusb_cfg));
}

void forward_task(void *pvParameters)
{
    keyboard_data_t keydata;
    mouse_data_t mousedata; 
    for (;;)
    {
        if (xEventGroupWaitBits(uart_semaphore, BIT(3), pdFALSE, pdTRUE, portMAX_DELAY))
        {       
            if(is_CH9350_key_data(uart_data)){
                CH9350_get_key_data(uart_data, &keydata);
                tud_hid_keyboard_report(HID_ITF_PROTOCOL_KEYBOARD, keydata.modifier[0], keydata.key);
            }
            if(is_CH9350_mouse_data(uart_data)){
                CH9350_get_mouse_data(uart_data, &mousedata);
                tud_hid_mouse_report(HID_ITF_PROTOCOL_MOUSE, mousedata.button, mousedata.x,mousedata.y,mousedata.wheel,0);
            }
            
            //ESP_DRAM_LOGI(TAG,"%u",xTaskGetTickCount()-temptick);
            xEventGroupSetBits(uart_semaphore, BIT(1));
        }
        //vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}