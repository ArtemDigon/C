#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define N 256

void swap (unsigned char *a, unsigned char *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int KSA (char* key, unsigned char* S) {
	unsigned long len = strlen(key);
	int j = 0;

	for (int i = 0; i < N; i++) {
		S[i] = i;
	}

	for (int i = 0; i < N; i++) {
		j = (j + S[i] + key[i % len]) % N;
		swap(&S[i] , &S[j]);
	}
	return 0;
} 

int PRGA (unsigned char *S, char *plaintext, char *ciphertext,size_t sizeText) {

    int i = 0;
    int j = 0;

    for (size_t n = 0, len = strlen(plaintext); n < len; n++) {
        i = (i + 1) % N;
        j = (j + S[i]) % N;

        swap(&S[i], &S[j]);
        int rnd = S[(S[i] + S[j]) % N];

        ciphertext[n] = rnd ^ plaintext[n];

    }

    return 0;
}

int RC4 (char *key, char *plaintext, char* ciphertext, size_t sizeText) {
	unsigned char S[N];
	KSA(key,S);

	PRGA(S, plaintext, ciphertext, sizeText);
	return 0;
}

int main(){

    int sd, cd;
    struct sockaddr_in addr;
    char msg[100];
    int lenmsg = 0;
    	
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if(sd < 0){
        perror("Error call socket");
        return __LINE__;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(1234);
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");

    if(bind(sd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        perror("bind");
        return __LINE__;
    }

    if(listen(sd, 5)){
        perror("listen");
        return __LINE__;
    }

    if(0 > (cd = accept(sd, NULL, NULL))){
        perror("accept");
        return __LINE__;    
    }

    lenmsg = recv(cd, msg, 100, 0);
    int len_text = lenmsg -1;

    char* text = malloc(sizeof(char) * (len_text));
    for (int i = 0; i < len_text;i++)
        text[i] = msg[i];

    printf("%s\n", text);

    lenmsg = recv(cd, msg, 16, 0);
    int len_key = lenmsg - 1;

    char* key = malloc(sizeof(char) * (len_key));
    for (int i = 0; i < len_key; i++)
	key[i] = msg[i];
	 
    printf("text :%s\nkey :%s\n", text, key);
    char* buffer = malloc(sizeof(unsigned char) * (len_text));
    RC4(key, text, buffer,len_text);
    printf("\n");

    for (int i = 0; i < len_text; i++)
	printf ("%02hhX ", buffer[i]);
     

    close(cd);
    close(sd);

}
