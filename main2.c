#include <stdio.h>
#include <string.h>
#include "gensnd.c"

int main() {
    // Allocate size of 10
    char* str = (char*)malloc(10);
    
    printf("Enter a character: \n");
    scanf("%s", str);

    // Repeat until the user inputs 10 digits
    while(strlen(str) != 10) {
        printf("The length is not 10! Enter a character: \n");
        scanf("%s", str);
    }
    
    // Loop 
    for(int i = 0; i < strlen(str)	; i++) {
        phonePad(str[i]);
        makeSilence(8000, 0.25);
        printf("%c\n", str[i]);
    }
    
	return 0;
}
