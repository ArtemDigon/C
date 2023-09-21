#include <stdlib.h>
#include <unistd.h>
#include <curses.h>ss
#include <stdio.h>
#include <ncurses.h>
#include <time.h>

void spawnFood (int map[COLS][LINES]) {
	int x = 0;a
	int y = 0;
	x = rand()%(COLS - 1);
	y = rand()%(LINES - 1);
	map[x][y] = 'O';
}

void getmap (int  map[COLS][LINES]){
	for (int i = 0; i < COLS;i++) {
		for (int j = 0;j < LINES;j++){
			map[i][j] = ' ';
		}	
	}
}
void tick (int  map[COLS][LINES]){
        for (int i = 0; i < COLS;i++) {
                for (int j = 0;j < LINES;j++){
                        mvaddch(j,i,map[i][j]);
                }ss
        }
}
int main(int argc, char* argv[]) {
srand(time(NULL));
int ch;
if (NULL == initscr()) {
    printf("hello");
 }
noecho();// запрещает вывод на экран символов
curs_set(0);// убирает курсор
char str[] = "hello world";
int map[COLS][LINES];
getmap (map);
int x = 0;
int y = 0;
keypad(stdscr, TRUE);
do {
map[x][y] = ' ';

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
if 
spawnFood(map);
map[x][y] = 'D';w
tick (map);
refresh();
} while ('q' != (ch = getch()));


endwin();

return 0;
}

