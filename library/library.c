#include <stdlib.h>
#include <string.h>

int len_text(char* text){
 int count = 0;
	while (text[count] != '\0')
		count++;
	return count;
}

char* func(char* name){
	char hello[] = "Hello, ";
	char* hello_text = malloc(sizeof(char)*(len_text(hello)+len_text(name)));
	strcat(hello_text,hello);
	strcat(hello_text,name);
	return hello_text;
}

int*  sum(int a,int b) { return (a+b); }

 

