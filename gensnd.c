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
  float frequency1 = 697;
  float frequency2 = 1209;
  DTMF(frequency1, frequency2);
    break;
  case '2':
  float frequency1 = 697;
  float frequency2 = 1336;
  DTMF(frequency1, frequency2);
    break;
  case '3':
  float frequency1 = 697;
  float frequency2 = 1477;
  DTMF(frequency1, frequency2);
    break;
  case '4':
  float frequency1 = 770;
  float frequency2 = 1209;
  DTMF(frequency1, frequency2);
    break;
  case '5':
  float frequency1 = 770;
  float frequency2 = 1336;
  DTMF(frequency1, frequency2);
    break;
  case '6':
  float frequency1 = 770;
  float frequency2 = 1477;
  DTMF(frequency1, frequency2);
    break;
  case '7':
  float frequency1 = 852;
  float frequency2 = 1209;
  DTMF(frequency1, frequency2);
    break;
  case '8':
  float frequency1 = 852;
  float frequency2 = 1336;
  DTMF(frequency1, frequency2);
    break;
  case '9':
  float frequency1 = 852;
  float frequency2 = 1477;
  DTMF(frequency1, frequency2);
    break;
  case 'a':
  case 'A':
  float frequency1 = 697;
  float frequency2 = 1633;
  DTMF(frequency1, frequency2);
    break;
  case 'b':
  case 'B':
  float frequency1 = 770;
  float frequency2 = 1633;
  DTMF(frequency1, frequency2);
    break;
  case 'c':
  case 'C':
  float frequency1 = 852;
  float frequency2 = 1633;
  DTMF(frequency1, frequency2);
    break;
  case 'd':
  case 'D':
  float frequency1 = 941;
  float frequency2 = 1633;
  DTMF(frequency1, frequency2);
    break;
  case '*':
  float frequency1 = 941;
  float frequency2 = 1209;
  DTMF(frequency1, frequency2);
   break;
  case '0':
  float frequency1 = 941;
  float frequency2 = 1336;
  DTMF(frequency1, frequency2);
    break;
  case '#':
  float frequency1 = 941;
  float frequency2 = 1477;
  DTMF(frequency1, frequency2);
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

void DTMF(float freq1, float freq2){
  float radians1;
  float radians2;
  float duration = 0.5;
  float sampleRate = 8000;
  for(int i = 0; i < sampleRate*duration;){
      for(radians1 = 0, radians2 = 0,; radians1 < 2*M_PI && radians2 < 2*M_PI; 
        radians1 += (2*M_PI/(sampleRate/frequency)) ,radian2 += (2*M_PI/(sampleRate/frequency))){
        printf("%.6lf\n", (sin(radians1)+sin(radians2))/2);
        i++;
      }
  }
}
