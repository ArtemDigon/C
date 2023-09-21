//написать шифровальщик цезаря 
#include <stdio.h>
#include <string.h>

int encryption (char string,int key) {
    char abc[26] = "abcdefghijklmnopqrstuvwxyz";
    int strlen_abc = strlen(abc);
    char a;
    
    for (int i = 0; i < strlen_abc; i++)
       {
        if (abc[i] == string)
           a = abc[(i + key) % strlen_abc];
       }
 return a;
}

int descryption (char string,int key) {
    char abc[26] = "abcdefghijklmnopqrstuvwxyz";
    int strlen_abc = strlen(abc);
    char a;
    
    for (int i = 0; i < strlen_abc; i++)
       {
        if (abc[i] == string)
           a = abc[(i - key) % strlen_abc];
       }
 return a;
}

int main() {
   char string[255];
   int key,i;
   char a;
   printf ("Введите строку для шифрования :\n");
   scanf ("%s",string);

   printf ("Введите шаг ключа :\n");
   scanf ("%i", &key);

   for (i = 0; i < strlen(string); i++) {
      if (string[i] == ' ')
	      string[i] = string[i];
      else
   	   string[i] = encryption(string[i], key);
   }

   for (i = 0; i < strlen(string); i++)
	   printf("%c",string[i]);

   printf ("\n");
   printf ("расшифровка \n");

   for ( i = 0; i < strlen(string); i++) {
      if (string[i] == ' ')
	      string[i] = string[i];
      else
   	   string[i] = descryption(string[i], key);
   }
   for (i = 0; i < strlen(string); i++)
	   printf("%c",string[i]);

    printf ("\n");
    
   return 0;
}

