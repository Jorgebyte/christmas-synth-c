#ifndef WAV_WRITER_H
#define WAV_WRITER_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char riff[4];
    uint32_t file_size;
    char wave[4];
    
    char fmt[4];
    uint32_t fmt_size;
    uint16_t audio_format;
    uint16_t num_channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
    
    char data[4];
    uint32_t data_size;
} WAVHeader;

void init_wav_header(WAVHeader* header, uint32_t sample_rate, uint16_t num_channels, 
                     uint16_t bits_per_sample, uint32_t data_size) {
    memcpy(header->riff, "RIFF", 4);
    header->file_size = 36 + data_size;
    memcpy(header->wave, "WAVE", 4);
    
    memcpy(header->fmt, "fmt ", 4);
    header->fmt_size = 16;
    header->audio_format = 1;
    header->num_channels = num_channels;
    header->sample_rate = sample_rate;
    header->bits_per_sample = bits_per_sample;
    header->byte_rate = sample_rate * num_channels * bits_per_sample / 8;
    header->block_align = num_channels * bits_per_sample / 8;
    
    memcpy(header->data, "data", 4);
    header->data_size = data_size;
}

void write_wav_header(FILE* file, WAVHeader* header) {
    fwrite(header, sizeof(WAVHeader), 1, file);
}

#endif // WAV_WRITER_H
