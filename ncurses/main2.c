#include <curses.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
int main() {
  char *simpleString = "Hello, world!";

  printf("Before: COLS=%x; LINES=%x; stdscr=%p\n", COLS, LINES, stdscr);
  if (NULL == initscr()) {
    return __LINE__;
  }
  printf("After: COLS=%x; LINES=%x; stdscr=%p\n", COLS, LINES, stdscr);

  curs_set(0);
  for (int i = 0; i < strlen(simpleString); i++) {
    mvaddch(0, i * 2, simpleString[i]);
    mvaddch(i, 0, simpleString[i]);
    refresh();
    sleep(1);
  }
  getch();
  endwin();
  return 0;
}
