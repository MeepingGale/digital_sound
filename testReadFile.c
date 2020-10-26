#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "gensnd.h"
#include "process.h"

enum Modes {START, SAMPLERATE, WAVE, SOUND, SONG};

typedef struct wave_t {
    char *waveName;
    char *type;
    float delay;
    float attenuation;
    struct wave_t *next;
    struct wave_t *prev;
}wave;

typedef struct mySound_t{
    char *soundName;
    int *wavesIndex;
    float *w;
    int countWaves;
}mySound;

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

void addWaveData(wave** head_ref, char *waveName, char *type, float delay, float attenuation){
    /* 1. allocate node */
    wave* new_node = (wave*)malloc(sizeof(wave));
      
    wave *last = *head_ref;  /* used in step 5*/
    
    new_node->waveName = (char*)malloc(sizeof(char));
    new_node->type = (char*)malloc(sizeof(char));
    strcpy(new_node->waveName, waveName);
    strcpy(new_node->type, type);
    new_node->delay = delay;
    new_node->attenuation = attenuation;
    /* 3. This new node is going to be the last node, so
            make next of it as NULL*/
    new_node->next = NULL;
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL){
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
      
    /* 6. Change the next of last node */
    last->next = new_node;
    
    /* 7. Make last node as previous of new node */
    new_node->prev = last;
    return;
}

int searchWave(wave *start, char *waveName){
    // Declare the temp variable
        wave *temp = start;
        // Declare other control
        // variable for the searching
    int flag=0, count=0;
    
    // If start is NULL return -1
        if(temp == NULL)
            return -1;
        else{
            while(temp->next != start){
                // If it is found raise the
                // flag and break the loop
                if(strcmp(temp->waveName, trimwhitespace(waveName)) == 0){
                    flag = 1;
                    return count;
                }
                // Increment temp pointer
                temp = temp->next;
                count++;
            }
            // Check whether last element in the
            // list content the value if contain,
            // raise a flag and increment count
            if(strcmp(temp->waveName, trimwhitespace(waveName)) == 0){
                flag = 1;
                count++;
            }
            if(flag == 1)
                return count;
            else
                return -1;
        }
}

void addSound(mySound* soundArray, char *soundName, int index){
    soundArray[index].soundName = (char*)malloc(sizeof(char));
    strcpy(soundArray[index].soundName, soundName);
    soundArray[index].wavesIndex = (int*)malloc(sizeof(int));
    soundArray[index].w= (float*)malloc(sizeof(float));
    soundArray[index].countWaves=(int)malloc(sizeof(int));
}

void addSoundData(mySound* soundArray, char *soundName, wave *head, char *waveName, int countWaves, int capacity, float w){
    if (soundArray == NULL) {
        printf("Not initialize");
    }
    for (int i = 0; i < capacity; i++) {
        if(strcmp(soundArray[i].soundName, soundName) == 0){
            soundArray[i].wavesIndex = realloc(soundArray[i].wavesIndex, sizeof(int)*countWaves);
            soundArray[i].wavesIndex[countWaves - 1] = searchWave(head, waveName);
            soundArray[i].w = realloc(soundArray[i].w, sizeof(float)*countWaves);
            soundArray[i].w[countWaves - 1] = w;
            soundArray[i].countWaves = countWaves;
            break;
        }
    }
}

void printSampleRate(float samplerate){
    printf("\nSample_rate: %f\n", samplerate);
}

void printWaveList(wave *node)
{
  while (node != NULL)
  {
      wave *last;
      printf("\nWave name: %s\nWave type: %s\nDelay: %f\nAttenuation: %f\n", node->waveName, node->type, node->delay, node->attenuation);
      last = node;
    node = node->next;
  }
}

void printSoundList(mySound* soundArray, int capacity){
    for (int i = 0; i < capacity; i++) {
        printf("\nWave name: %s\n", soundArray[i].soundName);
        for (int j = 0; j<soundArray[i].countWaves; j++) {
            printf("Wave index: %d\nMix values: %f\n", soundArray[i].wavesIndex[j], soundArray[i].w[j]);
        }
        printf("Wave count: %d\n", soundArray[i].countWaves);
    }
}

void printWave(char* waveName, char* waveType, float delay, float attenuation){
    printf("\nWave name: %s\nWave type: %s\nDelay: %f\nAttenuation: %f\n", waveName, waveType, delay, attenuation);
}

void printSound(char* soundName, char** waveName,float *w){
    printf("\nSound name: %s\n", soundName);
    for (int i =0; waveName[i] != NULL; i++) {
        printf("Wave name: %s\n W: %f\n", waveName[i], w[i]);
    }
}

int main(int argc, char * argv[]){
    FILE *fp;
    char str[255];
    char* filename = "samplerate.txt";
    
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    
    float sampleRate = 0.0;
    enum Modes mode = START;
    enum Modes await;
    wave* waveHead = NULL;
    char waveName[255];
    char waveType[10];
    char * pch;
    float waveValues[2];
    char soundName[255];
    int capacity = 0;
    int index = 0;
    mySound* soundArray = malloc(sizeof(mySound));
    
    while (fgets(str, 255, fp) != NULL) {
        if(mode == 0 && (strcmp(trimwhitespace(str), "SAMPLERATE") == 0)){
            mode = SAMPLERATE;
            await = WAVE;
            sampleRate = atoi(fgets(str, 255, fp));
            printSampleRate(sampleRate); //Do Stuff
        }
        else if((await == 2 || mode == 2) && (strcmp(trimwhitespace(str), "WAVE") == 0)){
            mode = WAVE;
            await = SOUND;
            strcpy(waveName,trimwhitespace(fgets(str, 255, fp)));
            strcpy(waveType,trimwhitespace(fgets(str, 255, fp)));
            fgets(str, 255, fp);
            pch = strtok (str," ");
            int i = 0;
              while (pch != NULL)
              {
                  waveValues[i] = atof(pch);
                  i++;
                pch = strtok (NULL, " ");
              }
            addWaveData(&waveHead ,waveName, waveType, waveValues[0], waveValues[1]);
        }
        else if((await == 3 || mode == 3) && (strcmp(trimwhitespace(str), "SOUND") == 0)){
            mode = SOUND;
            await = SONG;
            capacity++;
            soundArray = realloc(soundArray, sizeof(mySound) * capacity);
            strcpy(soundName, trimwhitespace(fgets(str, 255, fp)));
            addSound(soundArray, soundName, index);
            int i,j;
            int waveCount = 0;
            char **wavesAndW = (char**)malloc(sizeof(char));
            while(fgets(str, 255, fp) != NULL && (strcmp(trimwhitespace(str), "\0") != 0)){
                i = 0;
                pch = strtok (str," ");
                while (pch != NULL)
                {
                    wavesAndW[i] = malloc(strlen(pch)+1);
                    strcpy(wavesAndW[i], trimwhitespace(pch));
                    i++;
                    pch = strtok (NULL, " ");
                }
                waveCount++;
                addSoundData(soundArray, soundName, waveHead, wavesAndW[0], waveCount, capacity, atof(wavesAndW[1]));
            }
            index++;
        }
        else if((await == 4 || mode == 4) && (strcmp(trimwhitespace(str), "SONG") == 0)){
            
        }
    }
    printWaveList(waveHead);
    printSoundList(soundArray, capacity);
            fclose(fp);
            return 0;
}
