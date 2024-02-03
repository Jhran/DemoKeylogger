#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

#include "CH9350_Decode.h"

static const char *TAG = "Decode";

bool is_CH9350_key_data(const char uart_data[])
{
    if (uart_data[0] == 0x57 && uart_data[1] == 0xAB && uart_data[2]==0x01)
    {
        return true;
    }
    return false;
}

bool is_CH9350_mouse_data(const char uart_data[])
{
    if (uart_data[0] == 0x57 && uart_data[1] == 0xAB && uart_data[2]==0x02)
    {
        return true;
    }
    return false;
}

void CH9350_get_key_data(const char uart_data[], keyboard_data_t *keydata)
{
    CH9350_02_DATA *decodeData;
    decodeData = (CH9350_02_DATA *)uart_data;
    if (decodeData->opcode != OPCODE_TYPE_KEYBOARD)
    {
        return;
    }
    *keydata=decodeData->keys;
}
void CH9350_get_mouse_data(const char uart_data[], mouse_data_t *mousedata)
{
    CH9350_02_DATA *decodeData;
    decodeData = (CH9350_02_DATA *)uart_data;
    if (decodeData->opcode != OPCODE_TYPE_RELATIVE_MOUSE)
    {
        return;
    }
    *mousedata=decodeData->mouse;
}