#include <stdio.h>
#include <stdlib.h>
#include "wav_writer.h"
#include "audio_generator.h"
#include "music_notes.h"

#define SAMPLE_RATE 44100
#define BPM 140.0

void generate_jingle_bells(AudioBuffer* buffer, uint32_t start_pos) {
    MusicNote melody[] = {
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_HALF},
        
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_HALF},
        
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_G5, DURATION_QUARTER},
        {NOTE_C5, DURATION_QUARTER},
        {NOTE_D5, DURATION_QUARTER},
        {NOTE_E5, DURATION_WHOLE},
        
        {NOTE_F5, DURATION_QUARTER},
        {NOTE_F5, DURATION_QUARTER},
        {NOTE_F5, DURATION_QUARTER},
        {NOTE_F5, DURATION_QUARTER},
        
        {NOTE_F5, DURATION_QUARTER},
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_EIGHTH},
        {NOTE_E5, DURATION_EIGHTH},
        
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_D5, DURATION_QUARTER},
        {NOTE_D5, DURATION_QUARTER},
        {NOTE_E5, DURATION_QUARTER},
        
        {NOTE_D5, DURATION_HALF},
        {NOTE_G5, DURATION_HALF},
        
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_HALF},
        
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_HALF},
        
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_G5, DURATION_QUARTER},
        {NOTE_C5, DURATION_QUARTER},
        {NOTE_D5, DURATION_QUARTER},
        {NOTE_E5, DURATION_WHOLE},
        
        {NOTE_F5, DURATION_QUARTER},
        {NOTE_F5, DURATION_QUARTER},
        {NOTE_F5, DURATION_QUARTER},
        {NOTE_F5, DURATION_QUARTER},
        
        {NOTE_F5, DURATION_QUARTER},
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_QUARTER},
        {NOTE_E5, DURATION_EIGHTH},
        {NOTE_E5, DURATION_EIGHTH},
        
        {NOTE_G5, DURATION_QUARTER},
        {NOTE_G5, DURATION_QUARTER},
        {NOTE_F5, DURATION_QUARTER},
        {NOTE_D5, DURATION_QUARTER},
        
        {NOTE_C5, DURATION_WHOLE},
        {NOTE_REST, DURATION_HALF},
    };
    
    play_clean_sequence(buffer, melody, sizeof(melody)/sizeof(MusicNote), BPM, start_pos);
}

void generate_merry_christmas(AudioBuffer* buffer, uint32_t start_pos) {
    MusicNote melody[] = {
        {NOTE_C4, DURATION_QUARTER},
        {NOTE_F4, DURATION_QUARTER},
        {NOTE_F4, DURATION_EIGHTH},
        {NOTE_G4, DURATION_EIGHTH},
        {NOTE_F4, DURATION_EIGHTH},
        {NOTE_E4, DURATION_EIGHTH},
        
        {NOTE_D4, DURATION_QUARTER},
        {NOTE_D4, DURATION_QUARTER},
        {NOTE_D4, DURATION_QUARTER},
        
        {NOTE_G4, DURATION_QUARTER},
        {NOTE_G4, DURATION_EIGHTH},
        {NOTE_A4, DURATION_EIGHTH},
        {NOTE_G4, DURATION_EIGHTH},
        {NOTE_F4, DURATION_EIGHTH},
        
        {NOTE_E4, DURATION_QUARTER},
        {NOTE_C4, DURATION_QUARTER},
        {NOTE_C4, DURATION_QUARTER},
        
        {NOTE_A4, DURATION_QUARTER},
        {NOTE_A4, DURATION_EIGHTH},
        {NOTE_AS4, DURATION_EIGHTH},
        {NOTE_A4, DURATION_EIGHTH},
        {NOTE_G4, DURATION_EIGHTH},
        
        {NOTE_F4, DURATION_QUARTER},
        {NOTE_D4, DURATION_QUARTER},
        {NOTE_C4, DURATION_EIGHTH},
        {NOTE_C4, DURATION_EIGHTH},
        
        {NOTE_D4, DURATION_QUARTER},
        {NOTE_G4, DURATION_QUARTER},
        {NOTE_E4, DURATION_QUARTER},
        
        {NOTE_F4, DURATION_HALF},
        {NOTE_REST, DURATION_QUARTER},
        
        {NOTE_C4, DURATION_QUARTER},
        {NOTE_F4, DURATION_QUARTER},
        {NOTE_F4, DURATION_EIGHTH},
        {NOTE_G4, DURATION_EIGHTH},
        {NOTE_F4, DURATION_EIGHTH},
        {NOTE_E4, DURATION_EIGHTH},
        
        {NOTE_D4, DURATION_QUARTER},
        {NOTE_D4, DURATION_QUARTER},
        {NOTE_D4, DURATION_QUARTER},
        
        {NOTE_G4, DURATION_QUARTER},
        {NOTE_G4, DURATION_EIGHTH},
        {NOTE_A4, DURATION_EIGHTH},
        {NOTE_G4, DURATION_EIGHTH},
        {NOTE_F4, DURATION_EIGHTH},
        
        {NOTE_E4, DURATION_QUARTER},
        {NOTE_C4, DURATION_QUARTER},
        {NOTE_C4, DURATION_QUARTER},
        
        {NOTE_A4, DURATION_QUARTER},
        {NOTE_A4, DURATION_EIGHTH},
        {NOTE_AS4, DURATION_EIGHTH},
        {NOTE_A4, DURATION_EIGHTH},
        {NOTE_G4, DURATION_EIGHTH},
        
        {NOTE_F4, DURATION_QUARTER},
        {NOTE_D4, DURATION_QUARTER},
        {NOTE_C4, DURATION_EIGHTH},
        {NOTE_C4, DURATION_EIGHTH},
        
        {NOTE_D4, DURATION_QUARTER},
        {NOTE_G4, DURATION_QUARTER},
        {NOTE_E4, DURATION_QUARTER},
        
        {NOTE_F4, DURATION_WHOLE},
        {NOTE_REST, DURATION_WHOLE},
    };
    
    play_clean_sequence(buffer, melody, sizeof(melody)/sizeof(MusicNote), BPM, start_pos);
}

int main() {
    printf("Generating classic songs...\n");
    
    uint32_t total_samples = SAMPLE_RATE * 60;
    AudioBuffer* buffer = create_audio_buffer(total_samples, SAMPLE_RATE);
    
    if (!buffer) {
        fprintf(stderr, "Error creating audio buffer\n");
        return 1;
    }
    
    uint32_t pos = 0;
    generate_jingle_bells(buffer, pos);
    pos += SAMPLE_RATE * 28;
    
    generate_merry_christmas(buffer, pos);
    
    FILE* file = fopen("output.wav", "wb");
    if (!file) {
        fprintf(stderr, "Error creating file\n");
        free_audio_buffer(buffer);
        return 1;
    }
    
    uint32_t data_size = total_samples * sizeof(int16_t);
    WAVHeader header;
    init_wav_header(&header, SAMPLE_RATE, 1, 16, data_size);
    write_wav_header(file, &header);
    fwrite(buffer->samples, sizeof(int16_t), total_samples, file);
    fclose(file);
    
    printf("Audio file saved as output.wav\n");
    free_audio_buffer(buffer);
    
    return 0;
}
