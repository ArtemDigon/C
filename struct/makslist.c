#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct list {
  char* word;
  int size;
  struct list *next;
} list;

list *createList(char* word,int size) {
  list *node = (list *)malloc(sizeof(list));
  node->size = strlen(word);
  node->word = word;
  node->next = NULL;
  return node;
}

list *addElementList(char* word,int size, list *head) {
  list *node = (list *)malloc(sizeof(list));
  node->size = strlen(word);
  node->word = word;
  node->next = head;
  return node;
}

void printList(list *node) {
  list *tmp = node;
  while (tmp != NULL) {
    printf("%s {%d}\n", tmp->word,tmp->size);
    tmp = tmp->next;
  }
}

char *readWord(const char *str, int start, int end) {
  int lenght = end - start + 2;
  if (lenght <= 1)
    return NULL;
  char *word = (char *)malloc(sizeof(char) * lenght);
  for (int i = start, k = 0; i <= end; i++, k++)
    word[k] = str[i];

  word[lenght - 1] = '\0';
  return word;
}

int main() {

  const char text[] =
      "Hello world! My name is Artem, I love havka very much, there are so "
      "many of them in my life that I have to feed my beloved snake";

  int lenght = strlen(text);
  int start = 0;
  int end = 0;
  list *head = NULL;
  int size; 

  for (int i = 0; i < lenght; i++) {
    if (text[i] == ' ' || text[i] == ',' || text[i] == '!' || text[i] == '\0') {
      end = i - 1;
      char *word = readWord(text, start, end);
      if (word != NULL) {
	      size = strlen(word);
        head = addElementList(word,size, head);
      }
      start = i + 1;
    }
  }

        printList(head);
   while (head != NULL) {
        list *tmp = head;
        head = head->next;
        free(tmp->word);
        free(tmp);
        }
  return 0;
}
