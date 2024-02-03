#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "configKeylogger.h"
#include "hid_queue.h"

hid_queue_t hid_queue_create(){
    return xQueueCreate(KEYLOGGER_KEY_QUEUE_LENGTH,sizeof(hid_event_t));
}

void hid_event_build(hid_event_t *target,int key_type,int key_state,char key_code){
    target->type=key_type;
    target->state=key_state;
    target->key_code=key_code;
}

BaseType_t hid_queue_send(QueueHandle_t xQueue,const hid_event_t *pvItemToQueue,TickType_t xTicksToWait){
    return xQueueSend(xQueue,pvItemToQueue,xTicksToWait);
}

BaseType_t hid_queue_receive(QueueHandle_t xQueue,const hid_event_t *pvItemToQueue,TickType_t xTicksToWait){
    return xQueueReceive(xQueue,pvItemToQueue,xTicksToWait);
}

