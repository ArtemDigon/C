#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256

void swap (unsigned char *a, unsigned char *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int KSA (char* key, unsigned char* S) {
	int  len = strlen(key);
	int j = 0;

	for (int i = 0; i < N; i++) {
		S[i] = i;
	}

	for (int i = 0;i < N;i++) {
		j = (j+S[i] + key[i%len]) % N;
		swap(&S[i] , &S[j]);
	}
	return 0;
} 

int PRGA(unsigned char *S, char *plaintext, unsigned char *ciphertext) {

    int i = 0;
    int j = 0;

    for(size_t n = 0, len = strlen(plaintext); n < len; n++) {
        i = (i + 1) % N;
        j = (j + S[i]) % N;

        swap(&S[i], &S[j]);
        int rnd = S[(S[i] + S[j]) % N];

        ciphertext[n] = rnd ^ plaintext[n];

    }

    return 0;
}

int RS4 (char *key, char *line, unsigned char* shifr) {
	unsigned char S[N];
	KSA(key,S);
	PRGA(S,line,shifr);
	return 0;
}

int main() {
        printf("введите строку\n");
        char line[256];
        gets(line);

        printf ("введите ключ\n");
        char key[256];
        gets(key);
	
	unsigned char* buffer = malloc(sizeof(unsigned char) * strlen(line));
	
	RS4(key,line,buffer);
	
	for (int i = 0; i < strlen(line);i++)
		printf ("0x%02X ",buffer[i]);

	unsigned char* buffer_2 = malloc(sizeof(unsigned char) * strlen(line));	
	
	RS4(key,buffer,buffer_2);
	
	printf("\n");

	for (int i = 0; i < strlen(line);i++)
                printf ("%c",buffer_2[i]);

        return 0;
}
