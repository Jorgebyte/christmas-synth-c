#ifndef MUSIC_NOTES_H
#define MUSIC_NOTES_H

#include "audio_generator.h"

typedef enum {
    NOTE_REST = 0,
    
    NOTE_C3 = 131,
    NOTE_CS3 = 139,
    NOTE_D3 = 147,
    NOTE_DS3 = 156,
    NOTE_E3 = 165,
    NOTE_F3 = 175,
    NOTE_FS3 = 185,
    NOTE_G3 = 196,
    NOTE_GS3 = 208,
    NOTE_A3 = 220,
    NOTE_AS3 = 233,
    NOTE_B3 = 247,
    
    NOTE_C4 = 262,
    NOTE_CS4 = 277,
    NOTE_D4 = 294,
    NOTE_DS4 = 311,
    NOTE_E4 = 330,
    NOTE_F4 = 349,
    NOTE_FS4 = 370,
    NOTE_G4 = 392,
    NOTE_GS4 = 415,
    NOTE_A4 = 440,
    NOTE_AS4 = 466,
    NOTE_B4 = 494,
    
    NOTE_C5 = 523,
    NOTE_CS5 = 554,
    NOTE_D5 = 587,
    NOTE_DS5 = 622,
    NOTE_E5 = 659,
    NOTE_F5 = 698,
    NOTE_FS5 = 740,
    NOTE_G5 = 784,
    NOTE_GS5 = 831,
    NOTE_A5 = 880,
    NOTE_AS5 = 932,
    NOTE_B5 = 988,
    
    NOTE_C6 = 1047
} Note;

#define DURATION_WHOLE 4.0
#define DURATION_HALF 2.0
#define DURATION_QUARTER 1.0
#define DURATION_EIGHTH 0.5
#define DURATION_SIXTEENTH 0.25

typedef struct {
    Note note;
    double duration;
} MusicNote;

uint32_t beats_to_samples(double beats, double bpm, uint32_t sample_rate) {
    return (uint32_t)((beats * 60.0 / bpm) * sample_rate);
}

void play_bell_sequence(AudioBuffer* buffer, MusicNote* sequence, int num_notes, 
                       double bpm, uint32_t start_sample) {
    uint32_t current_sample = start_sample;
    
    for (int i = 0; i < num_notes; i++) {
        uint32_t duration_samples = beats_to_samples(sequence[i].duration, bpm, buffer->sample_rate);
        
        if (sequence[i].note != NOTE_REST) {
            generate_bell_note(buffer, (double)sequence[i].note, 
                             current_sample, duration_samples);
        }
        
        current_sample += duration_samples;
    }
}

void play_clean_sequence(AudioBuffer* buffer, MusicNote* sequence, int num_notes, 
                        double bpm, uint32_t start_sample) {
    uint32_t current_sample = start_sample;
    
    for (int i = 0; i < num_notes; i++) {
        uint32_t duration_samples = beats_to_samples(sequence[i].duration, bpm, buffer->sample_rate);
        
        if (sequence[i].note != NOTE_REST) {
            generate_clean_note(buffer, (double)sequence[i].note, 
                              current_sample, duration_samples);
        }
        
        current_sample += duration_samples;
    }
}

void play_chord(AudioBuffer* buffer, Note* notes, int num_notes, 
               uint32_t start_sample, uint32_t duration_samples) {
    for (int i = 0; i < num_notes; i++) {
        if (notes[i] != NOTE_REST) {
            generate_clean_note(buffer, (double)notes[i], 
                              start_sample, duration_samples);
        }
    }
}

#endif // MUSIC_NOTES_H
