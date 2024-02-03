#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "esp_log.h"

#include "Decoder/hid_queue/hid_queue.h"
#include "Decoder/Keyboard/keyboard_decode.h"
#include "Decoder/CH9350/CH9350_decode.h"
#include "configKeylogger.h"

extern EventGroupHandle_t uart_semaphore;
extern volatile char uart_data[KEYLOGGER_UART_RX_BUFFER_SIZE];
static const char *TAG = "Logger";
hid_queue_t hid_queue_test;

void logger_task(void *pvParameters)
{
    keyboard_data_t new_key_data, old_key_data;

    hid_queue_test = hid_queue_create();
    for (;;)
    {
        if (xEventGroupWaitBits(uart_semaphore, BIT(3), pdFALSE, pdTRUE, portMAX_DELAY))
        {
            CH9350_get_key_data(uart_data, &new_key_data);
            keyboard_send_all_key_state(hid_queue_test, old_key_data, new_key_data);
            old_key_data = new_key_data;
            xEventGroupSetBits(uart_semaphore, BIT(0));
        }
    }
    vTaskDelete(NULL);
}