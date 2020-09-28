#include <stdio.h>
#include "gensnd.c"

int main(int argc, char * argv[]) {
    // This is to test outputfile function
    sound *hello = gensine2(450, 9000, 2);
    FILE *file = fopen("test", "w");
    outputSound(hello, file);
    return 0;
}
