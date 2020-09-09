#include <stdio.h>
#include <string.h>
#include "gensnd.c"

// Returns 1 if it's invalid, 0 otherwise
int check_validity(char* str) {
    char* key_pad = "0123456789*#";

    for(int i = 0; i < strlen(str); i++)
        for(int j = 0; j < strlen(key_pad); j++)
            if(key_pad[j] != str[i])
                return 1;
            
    return 0;
}

int main() {
    // Allocate size of 10
    char* str = (char*)malloc(10);
    
    printf("Enter a character: \n");
    scanf("%s", str);

    // Repeat until the user inputs 10 digits & checks validity
    while(strlen(str) != 10) {
        printf("The length is not 10! Enter a character: \n");
        scanf("%s", str);
    }
    
    if(check_validity(str))
        printf("error");
    
    // Loop 
//    for(int i = 0; i < strlen(str); i++) {
//        phonePad(str[i]);
//        makeSilence(8000, 0.25);
//    }
    
	return 0;
}

