#include <tictactoe.h>

// local constants
#define rowLength 3
#define colLength 3

/* Things to do
 - tic tac toe playable
 - draw tic tac toe
 - create bot
*/

int printGrid(char *tttGridPtr)
{
    // Sanity Check
    if (tttGridPtr == NULL)
    {
        return 1;
    }
    printf("\
  %c  |  %c  |  %c  \n\
     |     |     \n\
-----+-----+-----\n\
  %c  |  %c  |  %c  \n\
     |     |     \n\
-----+-----+-----\n\
  %c  |  %c  |  %c  \n\
     |     |     \n",
           *tttGridPtr, *(tttGridPtr + 1), *(tttGridPtr + 2),
           *(tttGridPtr + 3), *(tttGridPtr + 4), *(tttGridPtr + 5),
           *(tttGridPtr + 6), *(tttGridPtr + 7), *(tttGridPtr + 8));

    return 0;
}

int updateGrid(char *tttGridPtr, char rowLoc, int colLoc, bool turn)
{
    // Sanity checks, ascii for a is 97, c is 99
    if (tttGridPtr == NULL || rowLoc < 97 || rowLoc > 99 || colLoc < 1 || colLoc > 3)
    {
        return 1;
    }
    // turn true (1) = x false (0) = o
    if (turn)
    {
        *(tttGridPtr + (rowLoc - 97) * colLength + colLoc - 1) = 'x';
    }
    else
    {
        *(tttGridPtr + (rowLoc - 97) * colLength + colLoc - 1) = 'o';
    }

    return 0;
}

/**
 * Function: tictactoe
 * @def:
 * @param:
 * @returns: (int) 0 for player o win, 1 for player x win, 2 for draw, 3 for error, 4 for wip
 */
int tictactoe()
{
    // tttGrid, ' ' for empty, o for o, x for x
    char tttGrid[9] = {' ', ' ', ' ',
                       ' ', ' ', ' ',
                       ' ', ' ', ' '};

    printf("Select grid location: (a-c)(1-3) \n");
    char rowLoc;
    int colLoc;
    scanf("%c %d", &rowLoc, &colLoc);
    // printf("You entered: %c %d\n", rowLoc, colLoc);
    if (updateGrid(tttGrid, rowLoc, colLoc, false))
    {
        return 3;
    }
    if (printGrid(tttGrid))
    {
        return 3;
    }
    return 4;
}

int main()
{
    // print winner
    switch (tictactoe())
    {
    case 0:
        printf("Player O Wins!\n");
        break;

    case 1:
        printf("Player X Wins!\n");
        break;

    case 2:
        printf("Its a Draw!\n");
        break;

    case 3:
        printf("Error\n");
        break;

    case 4:
        printf("In inplementation\n");
        break;
    }
    return 0;
}