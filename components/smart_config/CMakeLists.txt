idf_component_register(
    SRCS "smartconfig_handler.c"
    INCLUDE_DIRS "."
    REQUIRES esp_wifi esp_event nvs_flash mic_i2s
)


