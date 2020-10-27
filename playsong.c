#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "gensnd.h"
#include "process.h"

enum Modes { SampleRate, SR_Val, Wave, W_Name, W_Type, W_Vals, Sound };

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

float pianoKeytoHertz(int keyNumber){
    return (pow(2, (keyNumber-49.0)/12.0)* 440);
}


char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

int main(int argc, char * argv[]) {
    if (argc < 2) {
        printf("Usage: ./playsong <input.txt> <output_file.wav>\n");
        return 1;
    } else if (argc > 3) {
        printf("Too many agrument. Only 2 arguments is valid.\n");
        printf("Usage: ./playsong <input.txt> <output_file.txt>\n");
        return 1;
    } else{
        
    }
    return 0;
}
