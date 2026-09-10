#pragma once
#include <termios.h>
#include <unistd.h>

int getch(void);
void SetCursorPos(int XPos, int YPos);
void DeactivateCursor();
void ReactivateCursor();
