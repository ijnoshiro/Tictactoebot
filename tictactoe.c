#include <tictactoe.h>

// local constants
#define rowLength 3
#define colLength 3
#define oWin 111 * 3
#define xWin 120 * 3
#define filledBoard 111 * 5 + 120 * 4

/* Things to do
 - tic tac toe playable
 - draw tic tac toe
 - create bot
*/

/**
 * @returns -1: error, 0: no win, 1: o wins, 2: x wins, 3: draw
 */
int evalGrid(char *tttGridPtr)
{
    // Sanity Check
    if (tttGridPtr == NULL)
    {
        return -1;
    }
    // 'o' = 111, 'x' = 120
    // total up rows, cols, diagnals for comparison for win
    int topRow = tttGridPtr[0] + tttGridPtr[1] + tttGridPtr[2];
    int midRow = tttGridPtr[3] + tttGridPtr[4] + tttGridPtr[5];
    int botRow = tttGridPtr[6] + tttGridPtr[7] + tttGridPtr[8];

    int leftCol = tttGridPtr[0] + tttGridPtr[3] + tttGridPtr[6];
    int midCol = tttGridPtr[1] + tttGridPtr[4] + tttGridPtr[7];
    int rightCol = tttGridPtr[2] + tttGridPtr[5] + tttGridPtr[8];

    int leftDiag = tttGridPtr[0] + tttGridPtr[4] + tttGridPtr[8];
    int rightDiag = tttGridPtr[2] + tttGridPtr[4] + tttGridPtr[6];

    // o win checking
    if (topRow == oWin || midRow == oWin || botRow == oWin)
    {
        printf("Player o wins! Row Win");
        return 1;
    }
    if (leftCol == oWin || midCol == oWin || rightCol == oWin)
    {
        printf("Player o wins! Column Win");
        return 1;
    }
    if (leftDiag == oWin || rightDiag == oWin)
    {
        printf("Player o wins! Diagonal Win");
        return 1;
    }

    // x win checking
    if (topRow == xWin || midRow == xWin || botRow == xWin)
    {
        printf("Player x wins! Row Win");
        return 2;
    }
    if (leftCol == xWin || midCol == xWin || rightCol == xWin)
    {
        printf("Player x wins! Column Win");
        return 2;
    }
    if (leftDiag == xWin || rightDiag == xWin)
    {
        printf("Player x wins! Diagonal Win");
        return 2;
    }

    // draw check
    if (topRow + midRow + botRow == filledBoard)
    {
        return 3;
    }
    // no win concluded
    return 0;
}

int printGrid(char *tttGridPtr)
{
    // Sanity Check
    if (tttGridPtr == NULL)
    {
        return -1;
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
           tttGridPtr[0], tttGridPtr[1], tttGridPtr[2],
           tttGridPtr[3], tttGridPtr[4], tttGridPtr[5],
           tttGridPtr[6], tttGridPtr[7], tttGridPtr[8]);

    return 0;
}

int updateGrid(char *tttGridPtr, char rowLoc, int colLoc, bool turn)
{
    // Sanity checks, ascii for a is 97, c is 99
    if (tttGridPtr == NULL || rowLoc < 97 || rowLoc > 99 || colLoc < 1 || colLoc > 3)
    {
        return -1;
    }
    // check if filled
    if (*(tttGridPtr + (rowLoc - 97) * colLength + colLoc - 1) == 'x' || *(tttGridPtr + (rowLoc - 97) * colLength + colLoc - 1) == 'o')
    {
        return -1;
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
 * @returns: (int) 0 for player o win, 1 for player x win, 2 for draw, -1 for error, 4 for wip
 */
int tictactoe()
{
    // tttGrid, ' ' for empty, o for o, x for x
    char tttGrid[9] = {' ', ' ', ' ',
                       ' ', ' ', ' ',
                       ' ', ' ', ' '};

    int check = 1;
    bool turn = false;
    while (check)
    {
        printf("Select grid location: (a-c)(1-3) \n");
        char rowLoc;
        int colLoc;
        scanf("%c %d", &rowLoc, &colLoc);
        // printf("You entered: %c %d\n", rowLoc, colLoc);
        if (updateGrid(tttGrid, rowLoc, colLoc, turn))
        {
            return -1; // update it so if bad moves are made retry the move
        }
        if (printGrid(tttGrid))
        {
            return -1;
        }
        if (evalGrid(tttGrid))
        {
            return -1;
        }
        turn = !turn;
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

    case -1:
        printf("Error\n");
        break;

    case 4:
        printf("In inplementation\n");
        break;
    }
    return 0;
}