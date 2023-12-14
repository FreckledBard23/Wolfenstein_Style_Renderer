#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
    float seconds;
    SDL_AudioDeviceID audio_device;
    Uint8 * buffer;
    clock_t start_time;
} sound_close_id;

// Function to free audio resources
void freeAudioResources(sound_close_id *audioData) {
    SDL_CloseAudioDevice(audioData->audio_device);
    SDL_FreeWAV(audioData->buffer);
}

//https://stackoverflow.com/questions/76030221/is-it-possible-to-get-length-in-seconds-of-a-loaded-wav-file-in-sdl-library
double wav_duration_in_seconds(const char *filename) {
    SDL_AudioSpec spec;
    uint32_t audioLen;
    uint8_t *audioBuf;
    double seconds = 0.0;

    if(SDL_LoadWAV(filename, &spec, &audioBuf, &audioLen) != NULL) {
        // we aren't using the actual audio in this example
        SDL_FreeWAV(audioBuf);
        uint32_t sampleSize = SDL_AUDIO_BITSIZE(spec.format) / 8;
        uint32_t sampleCount = audioLen / sampleSize;
        // could do a sanity check and make sure (audioLen % sampleSize) is 0
        uint32_t sampleLen = 0;
        if(spec.channels) {
            sampleLen = sampleCount / spec.channels;
        } else {
            // spec.channels *should* be 1 or higher, but just in case
            sampleLen = sampleCount;
        }
        seconds = (double)sampleLen / (double)spec.freq;
    } else {
        // uh-oh!
        fprintf(stderr, "ERROR: can't load: %s: %s\n", filename, SDL_GetError());
    }

    return seconds;
}

sound_close_id playSound(const char *filePath) {
    sound_close_id null;

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        // Handle initialization error
        return null;
    }

    SDL_AudioSpec wavSpec;
    Uint8 *wavBuffer;
    Uint32 wavLength;

    if (SDL_LoadWAV(filePath, &wavSpec, &wavBuffer, &wavLength) == NULL) {
        // Handle loading error
        SDL_Quit();
        return null;
    }

    SDL_AudioDeviceID audioDevice;
    audioDevice = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
    if (audioDevice == 0) {
        // Handle opening audio device error
        SDL_FreeWAV(wavBuffer);
        SDL_Quit();
        return null;
    }

    SDL_QueueAudio(audioDevice, wavBuffer, wavLength);
    SDL_PauseAudioDevice(audioDevice, 0); // Start playing

    // SDL_Delay(wav_duration_in_seconds(filePath) * 1000);

    // SDL_CloseAudioDevice(audioDevice);
    // SDL_FreeWAV(wavBuffer);

    sound_close_id sci;

    sci.seconds = wav_duration_in_seconds(filePath);
    sci.audio_device = audioDevice;
    sci.buffer = wavBuffer;

    return sci;
}