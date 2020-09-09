#include <stdio.h>
#include "gensnd.c"

float frequency;
float sample_rate;
float duration;

int main(int agrc, char * agrv[]) {

    char temp;
    
    printf("Enter a frequency: \n");
    scanf("%f", &frequency);
    
    if(scanf("%f%c", &frequency, &temp) != 2 || temp != '\n')
        printf("failure\n");
    
    printf("Enter a sample rate: \n");
    scanf("%f", &sample_rate);
    
    printf("Enter the duration: \n");
    scanf("%f", &duration);
    
    gensine(frequency, sample_rate, duration);
  
    return 0;
}
