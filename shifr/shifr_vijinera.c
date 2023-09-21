#include <stdio.h>
#include <string.h>

char shrift (char line,char key){
	return (line >= 97 && line <=122) ? ((((line - 97) + (key - 97)) % 26) + 97) : line;
}

int main () {

	char line[256];
	char key[256];
	
	printf("введите строку\n");
	gets(line);	
	
	printf("введите ключ\n");
	scanf("%s",key);

	for (int i = 0 ;i < strlen(line) ; i++) {
		printf("%c",shrift(line[i],key[i % strlen(key)]));		
	}
	return 0;
}
