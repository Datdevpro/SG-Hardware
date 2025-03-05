#include "smartconfig_handler.h"
#include <stdio.h>
#include "mic_i2s.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
    wifi_init();
    mic_i2s_init();

    int16_t audio_buffer[READ_LEN / 4];
    mic_i2s_read(audio_buffer, sizeof(audio_buffer));
}
