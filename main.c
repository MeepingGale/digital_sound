#include <stdio.h>
#include "gensnd.c"

float frequency;
float sample_rate;
float duration;

int main(int agrc, char * agrv[]) {

	printf("Enter a frequency: \n");
    while(1){
    if(scanf("%f", &frequency) == 1)
    	break;
    }
    printf("Enter a sample rate: \n");
    scanf("%f", &sample_rate);
    
    printf("Enter the duration: \n");
    scanf("%f", &duration);
    
    gensine(frequency, sample_rate, duration);
  
    return 0;
}
