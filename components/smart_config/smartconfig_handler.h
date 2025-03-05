#ifndef SMARTCONFIG_HANDLER_H
#define SMARTCONFIG_HANDLER_H

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_smartconfig.h"
#include <string.h>

// Event Group to signal when connected
extern EventGroupHandle_t s_wifi_event_group;

void smartconfig_start_task(void *param);
void wifi_init(void);

#endif // SMARTCONFIG_HANDLER_H
