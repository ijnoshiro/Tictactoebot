#include <stdio.h>
#include <stdbool.h>

//ANSI ESCAPE CODES for terminal text coloring
#define BLACK "\033[38;2;0;0;0m"
#define RED "\033[38;2;255;0;0m"
#define GREEN "\033[38;2;0;255;0m"
#define BLUE "\033[38;2;0;0;255m"

//tictactoe functions
int evalGRid(char *);
int printGrid(char *);
int updateGrid(char *, char, int, bool);
int tictactoe();