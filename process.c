#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "process.h"

sound* mix(sound *s[],float w[], int c){
  int longestLength = 0;
  for(int i = 0; i < c; i++){
    if(s[i]->length > longestLength)
      longestLength = s[i]->length;
  }
  if(longestLength == 0){
    return NULL;
  }
  sound *mix = (sound*)malloc(sizeof(sound));
  mix->rate = sample_rate;
  mix->length = sample_rate * duration;
  mix->samples = (float *)malloc(sizeof(float)*longestLength);
  for(int i = 0; i < longestLength; i++) {
    mix->samples[i] = 0;
  }
  for(int i = 0; i < c; i++) {
    for (int j = 0; j < s[i]->length; j++) {
      mix->samples[j] += s[i]->samples[j]*w[i];
    }
  }
  return mix;
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
