#include <stdio.h>
#include <stdlib.h>

typedef struct cord {
int x;
int y;
}cord;



int main() {
int n = 4;
cord* map = (cord*)malloc(sizeof(cord)*4);
	for (int i = 0;i < n;i++) {
		scanf("%d",&map[i].x);
		scanf("%d",&map[i].y);	
	}
	printf("i x y\n");
	for (int i = 0;i < n;i++) {
		printf("%d:%d|%d\n",i,map[i].x,map[i].y);
		
	}
return 0;
}

