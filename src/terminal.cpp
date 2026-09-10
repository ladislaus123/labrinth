// Responsavel por controlar o estado do terminal: teclado e cursor.
#include <iostream>
#include "terminal.hpp"

int getch(void) {
  int ch;
  struct termios oldt;
  struct termios newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
}

void SetCursorPos(int XPos, int YPos) {
  printf("\033[%d;%dH", YPos + 1, XPos + 1);
}

void DeactivateCursor() {
  printf("\033[?25l");
}

void ReactivateCursor() {
  printf("\033[?25h");
}
