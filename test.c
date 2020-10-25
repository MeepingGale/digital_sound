#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "gensnd.h"
#include "process.h"

typedef struct song_t {
    char *soundName;
    int keyNumber;
    float time;
    float duration;
}song;

typedef struct wave_t {
    char *waveName;
    char *type;
    float delay;
    float attenuation;
    struct wave_t *next;
}wave;

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
    new_node->next = NULL;
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL){
           *head_ref = new_node;
           return;
    }
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
      
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
    
}

void printList(wave *node)
{
  while (node != NULL)
  {
      printf("\nWave name: %s\nWave type: %s\nDelay: %f\nAttenuation: %f\n", node->waveName, node->type, node->delay, node->attenuation);
     node = node->next;
  }
}

int main(int argc, char * argv[]){
    wave* head = NULL;
    char str1[12] = "mywave1";
    char str2[12] = "sine";
    float delay = 0.1;
    float attenuation = 0.2;
    addWaveData(&head, str1, str2, delay, attenuation);
    //printList(head);
    char str3[12] = "mywave2";
    char str4[12] = "sine";
    float delay1 = 0.3;
    float attenuation2 = 0.4;
    addWaveData(&head, str3, str4, delay1, attenuation2);
    printList(head);
}
