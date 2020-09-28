#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gensnd.h>

void gensine(float frequency, float sampleRate, float duration) {
    // float radians;
    // for(int i = 0; i < sampleRate*duration; ) {
    //     for(radians = 0; radians < 2 * M_PI; radians += (2 * M_PI / (sampleRate / frequency))) {
    //         printf("%.6lf\n", sin(radians));
    //         i++;
    //     }
    // }
    int samplesAmount = duration * sampleRate;
    for(int i = 0; i < samplesAmount; i++){
       printf("%.6lf", sin(2.0 * M_PI * frequency * i / sampleRate));
  }
}

sound *gensine2(float hertz, float sample_rate, float duration){
    sound *gensine2 = (sound*)malloc(sizeof(sound));
    gensine2->rate = sample_rate;
    gensine2->length = sample_rate * duration;
    gensine2->samples = (float *)malloc(sizeof(float)*sample_rate*duration);
    int samplesAmount = duration * sampleRate;
    for(int i = 0; i < samplesAmount; i++){
        gensine2->samples[i] = sin(2.0 * M_PI * frequency * i / sampleRate);
}
    return gensine2;
}

void DTMF(float freq1, float freq2) {
    // float radians1 = 0.0f;
    // float radians2 = 0.0f;
    // float duration = 0.5;
    // float sampleRate = 8000;
    int samplesAmount = 0.5 * 8000;
    for(int i = 0; i < samplesAmount; i++){
    printf("%.6lf", (sin(2.0 * M_PI * freq1 * i / 8000) + sin(2.0 * M_PI * freq2 * i / 8000))/2.0);
  }
}

sound *genDTMF2(char key, float sample_rate, float duration){

}

void phone_pad(char ch) {
    switch (ch) {
        case '1':
            DTMF(697, 1209);
            break;
        case '2':
            DTMF(697, 1336);
            break;
        case '3':
            DTMF(697, 1477);
            break;
        case '4':
            DTMF(770, 1209);
            break;
        case '5':
            DTMF(770, 1336);
            break;
        case '6':
            DTMF(770, 1477);
            break;
        case '7':
            DTMF(852, 1209);
            break;
        case '8':
            DTMF(852, 1336);
            break;
        case '9':
            DTMF(852, 1477);
            break;
        case 'a':
        case 'A':
            DTMF(697, 1633);
            break;
        case 'b':
        case 'B':
            DTMF(770, 1633);
            break;
        case 'c':
        case 'C':
            DTMF(852, 1633);
            break;
        case 'd':
        case 'D':
            DTMF(941, 1633);
            break;
        case '*':
            DTMF(941, 1209);
            break;
        case '0':
            DTMF(941, 1336);
            break;
        case '#':
            DTMF(941, 1477);
            break;
        default:
            printf("Not in the phone pad\n");
    }
}

void make_silence(float sampleRate, float duration) {
    for(int i = 0; i < sampleRate * duration; i++) {
        printf("%d\n", 0);
    }
}

sound *genSilence(float sample_rate, float duration){
    sound *silence = (sound*)malloc(sizeof(sound));
    silence->rate = sample_rate;
    silence->length = sample_rate * duration;
    silence->samples = (float*)malloc(sizeof(float)*sample_rate * duration);
    for(int i = 0; i < sampleRate * duration; i++) {
        silence->samples[i] = 0;
    }
    return silence;
}

int outputSound( sound *s, FILE *f){

}
