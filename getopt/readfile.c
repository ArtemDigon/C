#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>

int main (int argc,char* argv[]) {
	FILE* file;
	FILE* file_2;
	int flag_h = 0;
	int flag_f = 0;
	int flag_o = 0;
	int flag_s = 0;
	const char* short_option = "hf:o:S:";
	const struct option long_option[] = {
		{"help",no_argument,NULL,'h'},
		{"file",required_argument,NULL,'f'},
		{"output",required_argument,NULL,'o'},
		{"symbol",required_argument,NULL,'S'},
		{NULL,0,NULL,0}	
	
	};
	int option_index = 0;
	int r = 0;
	char* symbol;
	while ((r = getopt_long(argc,argv,short_option,long_option,&option_index)) != -1) {
		switch(r) {
			case 'h':
				printf ("use: %s -f <inputfile>\n", argv[0]);
				flag_h = 1;
				break;
			case 'f':
				file = fopen(optarg, "r");
				flag_f = 1;
				break;
			case 'o':
				file_2 = fopen(optarg, "w");
				flag_o = 1;
				break;
			case 'S':
				symbol = optarg;
				flag_s = 1;
				break;				
		}
	}
	if (flag_h == 1 || flag_f == 0 || file == NULL) 
		return 0;
	int* array = (int*)malloc(sizeof(int) * 256);
	int k = 0;
	int ch = 0; 
	while ((ch = fgetc(file)) != EOF){
    		k++;
    		array[ch]++;
	}
	if (file != NULL){
		printf(">%d\n",flag_s);
		if (flag_s != 0) {
			for (int i = 0; i < strlen(symbol); i++ )
				printf("%c =%d\n",symbol[i], array[symbol[i]]);
			fclose(file);
		}
		else if(file_2 !=NULL) {
         	       for (int i = 33;i < 127; i++) {
                	        fprintf(file_2,"%c = %d\n",i,array[i]);
               		 }
                fclose(file);
                fclose(file_2);
		}
        	else {
			for (int i = 33;i < 127; i++) {
				printf("%c = %d\n",i,array[i]);
			}
		fclose(file);
		}
	}		
return 0;
}
