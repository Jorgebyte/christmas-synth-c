#ifndef AUDIO_GENERATOR_H
#define AUDIO_GENERATOR_H

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct {
    int16_t* samples;
    uint32_t num_samples;
    uint32_t sample_rate;
} AudioBuffer;

AudioBuffer* create_audio_buffer(uint32_t num_samples, uint32_t sample_rate) {
    AudioBuffer* buffer = (AudioBuffer*)malloc(sizeof(AudioBuffer));
    buffer->samples = (int16_t*)calloc(num_samples, sizeof(int16_t));
    buffer->num_samples = num_samples;
    buffer->sample_rate = sample_rate;
    return buffer;
}

void free_audio_buffer(AudioBuffer* buffer) {
    if (buffer) {
        free(buffer->samples);
        free(buffer);
    }
}

void generate_sine_wave(AudioBuffer* buffer, double frequency, double amplitude, 
                       uint32_t start_sample, uint32_t duration_samples) {
    for (uint32_t i = 0; i < duration_samples && (start_sample + i) < buffer->num_samples; i++) {
        double t = (double)i / buffer->sample_rate;
        double value = amplitude * sin(2.0 * M_PI * frequency * t);
        
        int32_t sample = (int32_t)(value * 32767.0);
        
        if (sample > 32767) sample = 32767;
        if (sample < -32767) sample = -32767;
        
        buffer->samples[start_sample + i] += (int16_t)sample;
    }
}

void generate_bell_note(AudioBuffer* buffer, double frequency, 
                       uint32_t start_sample, uint32_t duration_samples) {
    for (uint32_t i = 0; i < duration_samples && (start_sample + i) < buffer->num_samples; i++) {
        double t = (double)i / buffer->sample_rate;
        double envelope = exp(-3.0 * t);
        
        double value = 0.0;
        value += sin(2.0 * M_PI * frequency * t) * 0.4;
        value += sin(2.0 * M_PI * frequency * 2.4 * t) * 0.3;
        value += sin(2.0 * M_PI * frequency * 3.2 * t) * 0.2;
        value += sin(2.0 * M_PI * frequency * 5.1 * t) * 0.1;
        
        value *= envelope;
        
        int32_t sample = (int32_t)(value * 32767.0 * 0.4);
        
        if (sample > 32767) sample = 32767;
        if (sample < -32767) sample = -32767;
        
        buffer->samples[start_sample + i] += (int16_t)sample;
    }
}

void generate_clean_note(AudioBuffer* buffer, double frequency, 
                        uint32_t start_sample, uint32_t duration_samples) {
    uint32_t attack = (uint32_t)(0.02 * buffer->sample_rate);
    uint32_t release = (uint32_t)(0.1 * buffer->sample_rate);
    
    for (uint32_t i = 0; i < duration_samples && (start_sample + i) < buffer->num_samples; i++) {
        double t = (double)i / buffer->sample_rate;
        double envelope = 1.0;
        
        if (i < attack) {
            envelope = (double)i / attack;
            envelope = envelope * envelope;
        }
        else if (i > duration_samples - release) {
            double rel_pos = (double)(i - (duration_samples - release)) / release;
            envelope = 1.0 - rel_pos;
            envelope = envelope * envelope;
        }
        
        double value = 0.0;
        value += sin(2.0 * M_PI * frequency * t) * 0.6;
        value += sin(2.0 * M_PI * frequency * 2.0 * t) * 0.2;
        value += sin(2.0 * M_PI * frequency * 3.0 * t) * 0.1;
        value += sin(2.0 * M_PI * frequency * 4.0 * t) * 0.05;
        
        value *= envelope;
        
        int32_t sample = (int32_t)(value * 32767.0 * 0.5);
        
        if (sample > 32767) sample = 32767;
        if (sample < -32767) sample = -32767;
        
        buffer->samples[start_sample + i] += (int16_t)sample;
    }
}

void mix_audio_buffers(AudioBuffer* dest, AudioBuffer* src, float mix_level) {
    uint32_t min_samples = dest->num_samples < src->num_samples ? 
                          dest->num_samples : src->num_samples;
    
    for (uint32_t i = 0; i < min_samples; i++) {
        int32_t mixed = dest->samples[i] + (int32_t)(src->samples[i] * mix_level);
        
        if (mixed > 32767) mixed = 32767;
        if (mixed < -32767) mixed = -32767;
        
        dest->samples[i] = (int16_t)mixed;
    }
}

#endif
