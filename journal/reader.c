#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int cheakIP (FILE *file_w, char *ip) {
	char* buffer = (char*)malloc(sizeof(char) * 40);
	fseek(file_w,0,SEEK_SET);
	while (!feof(file_w)) {
		if  (fgets(buffer,40,file_w)) {
			for (int i = 0;i<40;i++) {
                                if (ip[i] == 'x') //
                                        buffer[i] = 'x';//
				if (buffer[i] == '\n')
					buffer[i] = '\0';
			}
			if (strcmp(ip,buffer) == 0) {
				//printf("YES\n");
				free(buffer);
				return 1;
			}
		}	
	}
	free(buffer);
	return 0;
}

void tresh (char* buffer) {
        for (int i = 0;i < 256;i++) {
                if (buffer[i] == ' ') {
                        buffer[i] = '\0';
                        break;
                }

        }
}
void tire (char* buffer) {
        buffer[3] = '-';
        if (buffer[4] == ' ')
                buffer[4] = '0';
}

int main (int argc, char** argv) {
	const char* short_option = "hui:";
        const struct option long_option[] = {
                {"help",no_argument,NULL,'h'},
                {"unicode",no_argument,NULL,'u'},
		{"ip",required_argument,NULL,'i'},
                {NULL,0,NULL,0}

        };
	int countIP = 0;
	int flag_i = 0;
        int flag_u = 0;
        int option_index = 0;
        int r = 0;
	char* ip;
        char* symbol;
        while ((r = getopt_long(argc,argv,short_option,long_option,&option_index)) != -1) {
                switch(r) {
                        case 'u':
                                flag_u = 1;
                                break;
			case 'i':
				flag_i = 1;
				ip = optarg;
				break;
                }
	}

        FILE *file = fopen("journal2.txt", "r");
        char ch;
        int flag = 0;
        char  buffer[256];
	
        do {
                if (ch == '\n')
                        flag = 0;
                if (flag == 0) {
                        if (fread(buffer,sizeof(char),6,file) != 6) {
                                printf("complete\n");
                                break;
                        }
                tire(buffer);
                FILE *file_w = fopen(buffer,"a+");
                fseek(file,120,SEEK_CUR);
                fread(buffer,sizeof(char),40,file);
                tresh(buffer);
		if (flag_i == 1 ) {
                        for (int i = 0; i < 40; i++) {
                                if (ip[i] == 'x') 
                                        buffer[i] = 'x';
                        }
			if (strcmp(buffer,ip) == 0) {
				countIP++;
			}
		}
		else {
			 if (flag_u == 0 ) {
                         	fprintf (file_w, "%s\n",buffer);
               		 }
               		 else {
                        	int cursor = ftell(file_w);
                        	if (cheakIP(file_w,buffer) == 0) {
                                	//printf ("younik\n");
                                	fseek(file_w,cursor,SEEK_SET);
                                	fprintf (file_w, "%s\n",buffer);
                       		 }
               		 }

		}
		//getchar();
                flag = 1;
                for (int i = 0;i < 256; i++)
                        buffer[i] = '\0';
                fclose(file_w);
                }
        } while ((ch = getc(file)) != EOF);
        fclose(file);
	if (flag_i == 1)
		printf("count IP(%s) : %d\n",ip,countIP);
        return 0;
}
