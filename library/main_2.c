#include <stdio.h>
#include <dlfcn.h>

int main(){
	int a = 5;
	int b = 4;




	void* hendle;
	int* (sum)(*int);
	hendle = dlopen("./library.so",RTLD_LAZY);
		if (hendle == NULL)
			perror ("not found file lib");
	sum = (int (*)(int)) dlsym(hendle, "sum");
		if (sum != NULL) {
			int summ = sum(a,b);
			printf("%d\n",sum);
		}
		else {
			printf("error func");
		}
	dlclose (hendle);


return 0;

}
