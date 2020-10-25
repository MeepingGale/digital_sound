#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "process.h"

sound* mix(sound *s[],float w[], int c){
  int longestLength = 0;
  float rate = 0;
  for(int i = 0; i < c; i++){
    if(s[i]->length > longestLength)
      longestLength = s[i]->length;
      rate = s[i]->rate;
  }
  if(longestLength == 0){
    return NULL;
  }
  sound *mix = (sound*)malloc(sizeof(sound));
  mix->rate = rate;
  mix->length = longestLength;
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
  modulate->rate = s1->rate;
  modulate->length = s1->length;
  modulate->samples = (float *)malloc(sizeof(float)*s1->length);
  for(int i = 0; i < s1->length; i++) {
    modulate->samples[i] = s1->samples[i] * s2->samples[i];
  }
  return modulate;
}

sound* filter(sound *s, float fir[], int c){
  if(s->length == 0){
    return NULL;
  }
  sound *filter = (sound*)malloc(sizeof(sound));
  filter->rate = s->rate;
  filter->length = s->length;
  filter->samples = (float *)malloc(sizeof(float)*s->length);
  for(int i = 0; i < s->length; i++) {
    filter->samples[i] = 0;
  }
  for(int i = 0; i < s->length; i++){
    for (int j = 0; j < c; j++){
        if(i-j >= 0){
        filter->samples[i] += s->samples[i-j]*fir[j];
        }
    }
  }
    return filter;
}

sound* reverb(sound *s, float delay, float attenuation){
  if(attenuation >= 1 || attenuation <= 0){
    return NULL;
  }
  if(delay <= 0 || delay >= 0.1){
    return NULL;
  }
  if (s == NULL) {
    return NULL;
  }
  int firArraySize = s->rate * delay;
  float *fir = (float*)malloc(sizeof(float)*firArraySize);
  for(int i = 0; i < firArraySize; i++){
    if (i == 0) {
      fir[i] = 1;
    }
    else if(i == firArraySize - 1){
      fir[i] = attenuation;
    }
    else if(i != 0 || i != firArraySize - 1){
      fir[i] = 0;
    }
  }
  sound *reverb = filter(s, fir, firArraySize);
  return reverb;
}

sound* echo(sound *s, float delay, float attenuation){
    if(attenuation >= 1 || attenuation <= 0){
      return NULL;
    }
    if(delay < 0.1 || delay > 1){
      return NULL;
    }
    if (s == NULL) {
      return NULL;
    }
//    sound *echo = (sound*)malloc(sizeof(sound));
//    echo->rate = s->rate;
//    echo->length = s->length;
//    echo->samples = (float *)malloc(sizeof(float)*s->length);
//    for(int i = 0; i < s->length; i++) {
//      filter->samples[i] = 0;
//    }
//    for(int i = 0; i < s->length; i++){
//
//    }
    int firArraySize = s->rate * delay;
    float *fir = (float*)malloc(sizeof(float)*firArraySize);
    for(int i = 0; i < firArraySize; i++){
      if (i == 0) {
        fir[i] = 1;
      }
      else if(i == firArraySize - 1){
        fir[i] = attenuation;
      }
      else if(i != 0 || i != firArraySize - 1){
        fir[i] = 0;
      }
    }
    sound *echo = filter(s, fir, firArraySize);
    return echo;
}
