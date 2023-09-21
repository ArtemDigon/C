#include <unistd.h>
#include <curses.h>
#include <stdio.h>
#include <ncurses.h>

int main(int argc, char* argv[]) {
int ch;
if (NULL == initscr()) {
    printf("hello");
 }
noecho();// запрещает вывод на экран символов 
curs_set(0);// убирает курсор
char str[] = "hello world";

 
move (0,0);// смещение по координатом(0,0)-левый верхний угол
addch('H');// вывод одного символа
mvaddch(5,5,'H');
mvaddstr (10,10,str);
int x = 0;
int y = 0;
keypad(stdscr, TRUE);
do {
mvaddch(y,x,' ');

switch (ch) {
	case KEY_UP:
		y = (y + LINES - 1) % LINES;
		break;
	case KEY_DOWN:
		y = (y + 1) % LINES;
		break;
	case KEY_RIGHT:
		x = (x + 1) % COLS;
		break;
	case KEY_LEFT:	
	 	x = (x + COLS - 1) % COLS;
		break;
}	
mvaddch(y,x,'|');
} while ('q' != (ch = getch()));


endwin();

return 0;
}
