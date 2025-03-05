#include "esp_log.h"
#include "driver/i2s_std.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "mic_i2s";
static i2s_chan_handle_t rx_handle = NULL;

void mic_i2s_init(void) {
    ESP_LOGI(TAG, "Initializing I2S...");

    // Request only RX channel
    i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_0, I2S_ROLE_MASTER);
    esp_err_t err = i2s_new_channel(&chan_cfg, NULL, &rx_handle);  // Create RX-only channel

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to create I2S RX channel: %s", esp_err_to_name(err));
        return;
    }

    ESP_LOGI(TAG, "I2S RX channel created successfully.");

    // Configure I2S standard mode (Philips 16-bit Mono, 16kHz)
    i2s_std_config_t std_cfg = {
        .clk_cfg = I2S_STD_CLK_DEFAULT_CONFIG(16000),
        .slot_cfg = I2S_STD_PHILIPS_SLOT_DEFAULT_CONFIG(16, I2S_SLOT_MODE_MONO),
        .gpio_cfg = {
            .mclk = I2S_GPIO_UNUSED,  
            .bclk = GPIO_NUM_7,       // Bit Clock
            .ws   = GPIO_NUM_8,       // Word Select (LRCLK)
            .dout = I2S_GPIO_UNUSED,  // No output (mic input only)
            .din  = GPIO_NUM_6        // Data Input from microphone
        }
    };

    err = i2s_channel_init_std_mode(rx_handle, &std_cfg);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize I2S standard mode: %s", esp_err_to_name(err));
        return;
    }

    ESP_LOGI(TAG, "I2S standard mode initialized.");

    // Enable the RX channel
    err = i2s_channel_enable(rx_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to enable I2S RX channel: %s", esp_err_to_name(err));
        return;
    }

    ESP_LOGI(TAG, "I2S initialized successfully.");
}

void mic_i2s_read(int16_t *buffer, size_t buffer_len) {
    if (rx_handle == NULL) {
        ESP_LOGE(TAG, "I2S handle is NULL! Ensure mic_i2s_init() was successful.");
        return;
    }

    size_t bytes_read = 0;
    esp_err_t err = i2s_channel_read(rx_handle, buffer, buffer_len, &bytes_read, pdMS_TO_TICKS(1000));
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Error reading I2S data: %s", esp_err_to_name(err));
    } else {
        ESP_LOGI(TAG, "I2S read successful. Bytes read: %d", (int)bytes_read);
    }
}
