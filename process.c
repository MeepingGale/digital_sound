#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "process.h"

sound* mix(sound *s[],float w[], int c){
  
}

sound* modulate(sound *s1, sound *s2){
  if(s1->length != s2->length){
    return NULL;
  }
  sound *modulate = (sound*)malloc(sizeof(sound));
  modulate->rate = sample_rate;
  modulate->length = sample_rate * duration;
  modulate->samples = (float *)malloc(sizeof(float)*s1->length);
  for(int i = 0; i < s1->length; i++) {
    modulate->samples[i] = s1->samples[i] * s2->samples[i];
  }
  return modulate;
}

sound* filter(sound *s, float fir[], int c){

}

sound* reverb(sound *s, float delay, float attenuation){

}

sound* echo(sound *s, float delay, float attenuation){

}
