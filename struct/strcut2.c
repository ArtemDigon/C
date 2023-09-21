#include <stdio.h>
#include <stdlib.h>

typedef struct XY {
  int x;
  int y;
  struct XY *next;
} XY;

XY *creaeteList(int x, int y) {
  XY *list = (XY *)malloc(sizeof(XY));
  list->x = x;
  list->y = y;
  list->next = NULL;

  return list;
}

XY *addElementList(int x, int y, XY *head) {
  XY *list = (XY *)malloc(sizeof(XY));
  list->x = x;
  list->y = y;
  list->next = head;

  return list;
}

void freeLists(XY *list) {
  XY *current = list;
  XY *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  list = NULL;
}

int main() {

  XY *list = creaeteList(1, 2);

  list = addElementList(4, 2, list);
  list = addElementList(2, 1, list);
  list = addElementList(6, 0, list);
  list = addElementList(-2, 5, list);
  list = addElementList(-2, 6, list);
  list = addElementList(6, 5, list);
  list = addElementList(7, 9, list);
  list = addElementList(10, 7, list);

  XY *tmp = list;
  while (list != NULL) {
    printf("x: %d\ty: %d\n", list->x, list->y);
    list = list->next;
  }
  printf("-------------------\n");
  list = tmp;
  while (list != NULL) {
    printf("x: %d\ty: %d\n", list->x, list->y);
    list = list->next;
  }
  list = tmp;

  freeLists(list);

  return 0;
}
