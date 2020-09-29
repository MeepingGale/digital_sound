#include <stdio.h>
#include "gensnd.c"

int main(int argc, char **argv) {
    // This is to test outputfile function
    // sound *hello = gensine2(450, 9000, 2);
    // FILE *file = fopen("test", "w");
    // outputSound(hello, file);
    if (argc < 2){
			printf("%s\n", "Usage message!!");
		}
		if (argc > 3){
			printf("%s\n", "Too many agrument. Only up to 2 arguments is valid");
		}
		else{
			//print testing for each args and each char
			// for (int i = 1; i < 3; ++i)
			// {
			// 	while(*args[i]!='\0')
			// 	{
			// 		printf("%c\n", *args[i]++);
			// 	}
			// 	printf("%s\n", args[i]);
			// }
		}
    return 0;
}
