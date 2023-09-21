#include <dlfcn.h>
#include <stdio.h>


int main() {
	char name[] = "Artem";
	
	void* hendle;
	char* (*func)(char*);
	hendle = dlopen("./library.so",RTLD_LAZY);
		if (hendle == NULL)
			perror ("not found file lib");

	func = (char* (*)(char*)) dlsym(hendle,"func");
		if (func != NULL) {
			char* text = func(name);
			printf("%s\n",text);
		}
		else {
			printf("error func");
		}
	dlclose (hendle);
	return 0;
}
  

