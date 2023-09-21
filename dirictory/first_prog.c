#include <stdio.h>
#include <string.h>

typedef struct {
  int  chislo;
  char *key;
} elents_dirictionary;

typedef struct{
    elents_dirictionary unite[100];
    int size;
} slovar;


 void create_dirictory (slovar *dir) {
    dir->size = 0;
}
void remove_dirictionary(slovar *dir,char *key) {
    for (int i = 0; i < dir->size; i++) {
        if (dir->unite[i].key == key) {
            dir->unite[i].key = NULL;
            dir->unite[i].chislo = 0;
            dir->size--;
        }

    }
}

void input_dirictionary (slovar *dir, char* key,int chislo) {
    for (int i=0;i<dir->size;i++) {
        if (strcmp(dir->unite[i].key,key) == 0) {
            dir->unite[i].chislo = chislo;
            return;
        }      
    }
    dir->unite[dir->size].key= key;
    dir->unite[dir->size].chislo = chislo;
    dir->size++;
}
void output_dirictionary (slovar *dir, char* key) {
    for (int i=0; i<dir->size; i++) {
        if (strcmp(dir->unite[i].key,key) == 0) 
            printf ("%d\n",dir->unite[i].chislo);
    } 
    return;
}

int main() {
    slovar dir;
    create_dirictory(&dir);
    input_dirictionary(&dir,"key",0);
    input_dirictionary(&dir,"key1",1);
    input_dirictionary(&dir,"key2",2);
    input_dirictionary(&dir,"key3",3);
    output_dirictionary(&dir,"key");
    output_dirictionary(&dir,"key1");
    output_dirictionary(&dir,"key2");
    output_dirictionary(&dir,"key3");
    remove_dirictionary(&dir,"key1");
    remove_dirictionary(&dir,"key2");
    remove_dirictionary(&dir,"key");
    output_dirictionary(&dir,"key");
    output_dirictionary(&dir,"key1");
    output_dirictionary(&dir,"key2");
    output_dirictionary(&dir,"key3");
    return 0;
}

/*
#include <stdio.h>

int main() {
int arr[5] = {1,2,3,4,5};

for (int i=1; i<5; i++) {
    if (i == 5)
        arr[i] = 0;
    arr[i] = arr [i+1];
}
for (int i = 0;i < 5;i++)
    printf("%d\n",arr[i]);
return 0;
} */