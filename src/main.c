

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