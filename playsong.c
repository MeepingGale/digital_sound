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

double pianoKeytoHertz(int keyNumber){
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
        FILE *fp;
        char str[255];
        char* filename = "samplerate.txt";
                
        enum Modes mode;
        enum Modes await;
        float sample_rate;
        char wave_name[100];
        char type_of_wave[100];
        float delay;
        float attenuation;
        char temp2[100];
             
        fp = fopen(filename, "r");
        if (fp == NULL){
            printf("Could not open file %s",filename);
            return 1;
        }
            
        while (fgets(str, 255, fp) != NULL) {
            char* temp;
            await != W_Vals ? (temp = trimwhitespace(str)) : (temp = str);
                    
            // Check if the first keyword is SAMPLERATE
            if(strcmp(temp, "SAMPLERATE") == 0) {
                mode = SampleRate;
                await = SR_Val;
                continue;
            }
                    
            // After the first keyword
            if(mode == SampleRate) {
                switch(await) {
                    case SR_Val:
                        sample_rate = atof(str);
                        await = Wave;
                        break;
                    case Wave:
                        await = W_Name;
                        break;
                    case W_Name:
                        strcpy(wave_name, str);
                        await = W_Type;
                        break;
                    case W_Type:
                        strcpy(type_of_wave, str);
                        await = W_Vals;
                        break;
                    case W_Vals:
                        strcpy(temp2, trimwhitespace(str));
                        size_t len = sizeof(temp2);
                        int det = 0;
                        int sec_idx = 0;
                        char one[100];
                        char two[100];
                                
                        for(int i = 0; i < len; i++) {
                            if(isspace(str[i]))
                                det = 1;
                            else if(det == 0)
                                strcpy(&one[i], &str[i]);
                            else if(det == 1) {
                                strcpy(&two[sec_idx], &str[i]);
                                sec_idx += 1;
                            }
                        }

                        delay = atof(one);
                        attenuation = atof(two);
                        break;
                    default:
                        break;
                }
            }
        }
                
        printf("\nSample Rate: %f\n", sample_rate);
        printf("Wave Name: %s\n", wave_name);
        printf("Wave Type: %s\n", type_of_wave);
        printf("Delay: %f\n", delay);
        printf("Attenuation: %f\n", attenuation);
                
        fclose(fp);
    }
    return 0;
}
