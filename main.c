#include <stdio.h>
#include "gensnd.c"

int frequency;
int sample_rate;
int duration;

int main(int agrc, char * agrv[]) {

  printf("Enter a frequency: \n");
  scanf("%d", &frequency);
  printf("Enter a sample rate: \n");
  scanf("%d", &sample_rate);
  printf("Enter the duration: \n");
  scanf("%d", &duration);

  printf("Enter a character: \n");
  char ch;
  scanf("%s", &ch);
  getChar(ch);
  
  return 0;
}
