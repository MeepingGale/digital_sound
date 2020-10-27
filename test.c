#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "gensnd.h"
#include "process.h"

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

typedef struct songNotes_t{
    int soundIndex;
    float hertz;
    float startTime;
    float duration;
}songNotes;

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

int findWavetype(wave *start, int index){
    wave* current = start;
    
    int count = 0;
    while(current != NULL){
        if(count == index){
            if(strcmp(current->type, "sine") == 0)
                return 0;
            if(strcmp(current->type, "square") == 0)
                return 1;
            if(strcmp(current->type, "triangle") == 0)
                return 2;
            if(strcmp(current->type, "saw") == 0)
                return 3;
        }
        count++;
        current = current->next;
    }
    return -1;
}

float findWaveDelay(wave *start, int index){
    wave* current = start;
    
    int count = 0;
    while(current != NULL){
        if(count == index){
            return (current->delay);
        }
        count++;
        current = current->next;
    }
    return -1;
}

float findWaveAtte(wave *start, int index){
    wave* current = start;
    
    int count = 0;
    while(current != NULL){
        if(count == index){
            return(current->attenuation);
        }
        count++;
        current = current->next;
    }
    return -1;
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

void printList(wave *node)
{
  while (node != NULL)
  {
      wave *last;
      printf("\nWave name: %s\nWave type: %s\nDelay: %f\nAttenuation: %f\n", node->waveName, node->type, node->delay, node->attenuation);
      last = node;
    node = node->next;
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

int searchSound(mySound* soundArray, char *soundName, int capacity){
    for (int i = 0; i < capacity; i++) {
        if(strcmp(soundArray[i].soundName, soundName) == 0)
            return i;
    }
    return -1;
}

int main(int argc, char * argv[]){
    wave* head = NULL;
    int capacity = 1;
    int index = 0;
    int waveCount = 0;
    mySound* soundArray = malloc(sizeof(mySound));
    
    char str1[12] = "mywave1";
    char str2[12] = "sine";
    float delay = 0.1;
    float attenuation = 0.2;
    addWaveData(&head, str1, str2, delay, attenuation);
    char str3[12] = "mywave2";
    char str4[12] = "saw";
    float delay1 = 0.3;
    float attenuation2 = 0.4;
    addWaveData(&head, str3, str4, delay1, attenuation2);
    char str5[12] = "mywave3";
    char str6[12] = "triangle";
    float delay2 = 0.3;
    float attenuation3 = 0.4;
    addWaveData(&head, str5, str6, delay2, attenuation3);
    
    char str7[12] = "mysound1";
    addSound(soundArray, str7, index);
    char str8[12] = "mywave1";
    float w1 = 0.4;
    waveCount++;
    addSoundData(soundArray, str7, head, str8, waveCount, capacity, w1);
    char str9[12] = "mywave2";
    float w2 = 0.3;
    waveCount++;
    addSoundData(soundArray, str7, head, str9, waveCount, capacity, w2);
    char str10[12] = "mywave3";
    float w3 = 0.7;
    waveCount++;
    addSoundData(soundArray, str7, head, str10, waveCount, capacity, w3);
    
    capacity++;
    index++;
    waveCount = 0;
    soundArray = realloc(soundArray, sizeof(mySound) * capacity);
    char str11[12] = "mysound2";
    addSound(soundArray, str11, index);
    char str12[12] = "mywave1";
    float w4 = 0.2;
    waveCount++;
    addSoundData(soundArray, str11, head, str12, waveCount, capacity, w4);
    char str13[12] = "mywave2";
    float w5 = 0.9;
    waveCount++;
    addSoundData(soundArray, str11, head, str13, waveCount, capacity, w5);
    
    capacity++;
    index++;
    waveCount = 0;
    soundArray = realloc(soundArray, sizeof(mySound) * capacity);
    char str14[12] = "mysound3";
    addSound(soundArray, str14, index);
    char str15[12] = "mywave2";
    float w6 = 0.4;
    waveCount++;
    addSoundData(soundArray, str14, head, str15, waveCount, capacity, w6);
    char str16[12] = "mywave3";
    float w7 = 0.2;
    waveCount++;
    addSoundData(soundArray, str14, head, str16, waveCount, capacity, w7);
    
    char str17[12] = "mysound3";
    printList(head);
    printSoundList(soundArray, capacity);
    
    printf("Wave type: %d Delay: %f Attenuation: %f\n", findWavetype(head, 0), findWaveDelay(head, 0),findWaveAtte(head, 0));
    printf("Wave type: %d Delay: %f Attenuation: %f\n", findWavetype(head, 1), findWaveDelay(head, 1),findWaveAtte(head, 1));
    printf("Wave type: %d Delay: %f Attenuation: %f\n", findWavetype(head, 2), findWaveDelay(head, 2),findWaveAtte(head, 2));

}
