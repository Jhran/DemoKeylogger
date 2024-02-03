#ifndef _HID_EVENT_QUEUE
#define _HID_EVENT_QUEUE

#include "freertos/queue.h"

typedef struct __attribute__((packed)) _hid_event_t
{
    enum key_type
    {
        KEY_TYPE_MODIFTER = 0x00,
        KEY_TYPE_NORMAL = 0x01
    } type;

    enum key_state
    {
        KEY_STATE_PRESSED = 0x00,
        KEY_STATE_RELEASED = 0x01
    } state;

    char key_code;

} hid_event_t;

typedef QueueHandle_t hid_queue_t;

QueueHandle_t hid_queue_create();
void hid_event_build(hid_event_t *target,int key_type,int key_state,char key_code);
BaseType_t hid_queue_send(QueueHandle_t xQueue, const hid_event_t *pvItemToQueue, TickType_t xTicksToWait);
BaseType_t hid_queue_receive(QueueHandle_t xQueue, const hid_event_t *pvItemToQueue, TickType_t xTicksToWait);

#endif