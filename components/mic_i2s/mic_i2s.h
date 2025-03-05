#ifndef MIC_I2S_H
#define MIC_I2S_H

#include <stdint.h>
#include <stddef.h>
#include "driver/i2s_std.h"

#define SAMPLE_RATE     16000
#define I2S_CHANNEL_NUM 1
#define I2S_BUFFER_SIZE 1024
#define READ_LEN 1024

void mic_i2s_init(void);
void mic_i2s_read(int16_t *buffer, size_t buffer_size);

#endif
