#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct words {
  char *word;
  struct words *next;
} words;

words *creaeteList(char *word) {
  words *list = (words*)malloc(sizeof(words));
  list->word = word;
  list->next = NULL;

  return list;
}

words *addElementList(char *word, words *head) {
  words *list = (words *)malloc(sizeof(words));
  list->word = word;
  list->next = head;
  return list;
}

void freeLists(words *list) {
  words *current = list;
  words *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  list = NULL;
}

int main() {
  char string[] = "Hello world! My name is Maxim, I love havka very much, there are so many of them in my life that I have to feed my beloved snake";
  char sep[] = " ";
  words *list = creaeteList(NULL);
  char *istr = strtok(string,sep);
  while (istr != NULL){ 
   words *list = addElementList(strtok(NULL,sep),list);
  }
  words *tmp = list;
  while (list != NULL) {
    printf("%s\n", list->word);
    list = list->next;
  }
  list = tmp;

  freeLists(list);

return 0;
}


