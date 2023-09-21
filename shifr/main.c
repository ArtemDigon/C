#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
int main () {
	char text[255];
	char key[10];

	printf("please input text :\n"); 
	gets (text); //scanf("%s",text);

	printf("please input key :\n");
	scanf("%s",key);
    
   	int strlen_text = strlen(text);
    	int strlen_key = strlen(key);

	for (int i=0; i<strlen_text; i++) {
		text[i] = text[i] ^ key[i % strlen_key];
	}

	for (int i = 0; i < strlen_text; i++) {
    	printf("%c",text[i]);
	}
	
	printf("\n");

	for (int i=0; i<strlen_text; i++) {
                text[i] = text[i] ^ key[i % strlen_key];
        }

	for (int i = 0; i < strlen_text; i++) {
        printf("%c",text[i]);
        }
	
	printf("\n");

	return 0;
}
	
