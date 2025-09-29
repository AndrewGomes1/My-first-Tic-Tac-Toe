#include <stdio.h>
#include <stdlib.h>

#define BOARDSIZE 3

int const player1 = 1;
int const player2 = 2;
int turn = 1;

void check(char (*board)[BOARDSIZE]);

int main(void)
{
    char board[BOARDSIZE][BOARDSIZE];
    int add = 0;

    // initialize the board with numbers 0-8

    for (int i = 0; i < BOARDSIZE; i++)
    {
        for (int j = 0; j < BOARDSIZE; j++)
        {
            board[i][j] = '0' + add++;
        }
    }

    while (1)
    {
        for (int i = 0; i < BOARDSIZE; i++)
        {
            for (int j = 0; j < BOARDSIZE; j++)
            {
                printf("[%c]", board[i][j]);
            }
            printf("\n");

        }

        if (turn == player1)
        {
            printf("\n");
            printf("Player 1's turn: [X]\n");
        }
        else
        {
            printf("\n");
            printf("Player 2's turn: [O]\n");
        }

        // Get player input

        int choice;
        printf("\n");
        printf("Enter your choice 0-8: ");
        scanf("%i" , &choice);

        if (choice < 0 || choice > 8)
        {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        int row = choice / BOARDSIZE;
        int col = choice % BOARDSIZE;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            printf("\n");
            printf("Cell already taken. Try again.\n");
            continue;
        }

        if (turn == player1)
        {
            board[row][col] = 'X';
            turn = player2;
        }
        else
        {
            board[row][col] = 'O';
            turn = player1;
        }

        // Check for win condition or draw here 

        check(board);
    }
}

void check(char (*board)[BOARDSIZE])
{
    // Check rows and columns

    for (int i = 0; i < BOARDSIZE; i++)
    {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            printf("Player %c wins!\n", (board[i][0] == 'X') ? 'X' : 'O');
            exit(0);
        }

        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            printf("Player %c wins!\n", (board[0][i] == 'X') ? 'X' : 'O');
            exit(0);
        }
    }

    // Check diagonals

    char symbol = board[0][0];

    if (symbol == 'X' || symbol == 'O')
    {
        int win = 1;

        for (int i = 0; i < BOARDSIZE; i++)
        {
            if (board[i][i] != symbol)
            {
                win = 0;
                break;
            }
        }

        if (win)
        {
            printf("Player %c wins!\n", (symbol == 'X') ? 'X' : 'O');
            exit(0);
        }
    }

    symbol = board[0][BOARDSIZE - 1];

    if (symbol == 'X' || symbol == 'O')
    {

        int winOne = 1;

        for (int i = 0; i < BOARDSIZE; i++)
        {
            if (board[i][BOARDSIZE - 1 - i] != symbol)
            {
                winOne = 0;
                break;
            }
        }

        if (winOne)
        {
            printf("Player %c wins!\n", (symbol == 'X') ? 'X' : 'O');
            exit(0);
        }

    } 

    // Check for draw
    
    int filled = 0;

    for (int i = 0; i < BOARDSIZE; i++)
    {
        for (int j = 0; j < BOARDSIZE; j++)
        {
            if (board[i][j] == 'X' || board[i][j] == 'O')
            {
                filled++;    
            }
        }
    }

    if (filled == BOARDSIZE * BOARDSIZE)
    {
        printf("It's a draw!\n");
        exit(0);
    }
}