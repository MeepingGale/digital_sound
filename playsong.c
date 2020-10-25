#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gensnd.h"
#include "process.h"

typedef struct song_t {
    char *soundName;
    int keyNumber;
    float time;
    float duration;
} song;

typedef struct wave_t {
    char *waveName;
    char *type;
    float delay;
    float attenuation;
} wave;

double pianoKeytoHertz(int keyNumber){
    return (pow(2, (keyNumber-49.0)/12.0)* 440);
}

int main(int argc, char * argv[]) {
    if (argc < 2) {
        printf("Usage: ./playsong <input.txt> <output_file.wav>\n");
        return 1;
    } else if (argc > 3) {
        printf("Too many agrument. Only 2 arguments is valid.\n");
        printf("Usage: ./playsong <input.txt> <output_file.txt>\n");
        return 1;
    }else{
        
    }
    return 0;
}
