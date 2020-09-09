#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gensine(float frequency, float sampleRate, float duration) {
    float radians;
    for(int i = 0; i < sampleRate*duration;) {
        for(radians = 0; radians < 2*M_PI; radians += (2*M_PI/(sampleRate/frequency))) {
            printf("%.6lf\n", sin(radians));
            i++;
        }
    }
}

void DTMF(float freq1, float freq2){
    float radians1 = 0.0f;
    float radians2 = 0.0f;
    float duration = 0.5;
    float sampleRate = 8000;
    for(int i = 0; i < sampleRate*duration;){
        for(radians1 = 0, radians2 = 0; radians1 < 2*M_PI && radians2 < 2*M_PI; radians1 += (2*M_PI/(sampleRate/freq1)) ,radians2 += (2*M_PI/(sampleRate/freq2))){
            printf("%.6lf\n", (sin(radians1)+sin(radians2)) / 2);
            i++;
        }
    }
}

void phonePad(char ch) {
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

void makeSilence(float sampleRate, float duration) {
    for(int i = 0; i < sampleRate*duration; i++) {
        printf("%d\n", 0);
    }
}
