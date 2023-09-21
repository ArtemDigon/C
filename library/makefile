all: makeMain

makeMain: makeLib
	gcc main_2.c -o main_2

makeLib: compyleLib
	gcc library.o -shared -o library.so

compyleLib: 
	gcc -c -fPIC library.c -o library.o
 
clean:
	@rm -f *.o *.so main	
	@echo "files clean"
clear:
	clear
