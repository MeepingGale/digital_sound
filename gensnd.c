#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gensine(float frequency, float sampleRate, float duration) {
  float radians;
  for(int i = 0; i < sampleRate*duration;){
      for(radians = 0; radians < 2*M_PI; radians += (2*M_PI/(sampleRate/frequency))){
        printf("%.6lf\n", sin(radians));
        i++;
      }
  }
}

void phonePad(char ch) {
  switch (ch) {
  case '1':
    break;
  case '2':
    break;
  case '3':
    break;
  case '4':
    break;
  case '5':
    break;
  case '6':
    break;
  case '7':
    break;
  case '8':
    break;
  case '9':
    break;
  case 'a':
  case 'A':
    break;
  case 'b':
  case 'B':
    break;
  case 'c':
  case 'C':
    break;
  case 'd':
  case 'D':
    break;
  case '*':
   break;
  case '0':
    break;
  case '#':
    break;
  default:
    printf("Not in the phone pad\n");
  }
}

void makeSilence(float sampleRate, float duration){
  for(int i = 0; i < sampleRate*duration; i++){
    printf("%d\n", 0);
  }
}
