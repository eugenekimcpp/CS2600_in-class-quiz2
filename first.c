/* 
    Program: first.c
    Programmer: Eugene Kim

    This program practices the game called "Tic-Tac-Toe"

    Two level: 
    * person vs. person 
    * person vs. random computer



    First approach: 
    1. Create a function that keep displays the template, using printf()
    2. use random() NOT suedo random () (range 1-9)
    3. use switch cases for the user input


    Function List

    void resetBoard()
    void printBorad()
    void playerMove()
    void computerMove()


*/
#include <stdio.h>
#include <time.h> 

// Global Variables
char board[3][3];
const char O = 'O';
const char X = 'X';

void printDash();
void displayBoard();
void resetBoard();


int main() {

    // create variables 
    int choice;

    // prompt the user for game they wish to play
    // read information from console
    printDash();
    printf("WELCOME TO TIC TAC TOE!\n");
    printf("1 --- person vs. person\n");
    printf("2 --- person vs. random computer\n");
    scanf("%d", &choice);
    printDash();


    resetBoard();
    if(choice == 1)
    {
        printf("You have entered 1\n");
    }
    else if(choice == 2)
    {
        printf("You have entered 2\n");
    }
    else 
    {
        printf("Invalid choice!!!\n");
        return 0;
    }


    // call display function (W no arguments, function overloading)


    // get into the loop while (1=winner, 0=progressing, -1=no_winner)
    /* 
        - get the user input
        - 

    */

    



    return 0;
    
}

void printDash()
{
    printf("==========================")
}
void displayBoard()
{
    printf("+--------+\n");
    printf("|%c|%c|%c|\n", board[0][0],board[0][1],board[0][2]);
    printf("+--------+\n");
    printf("|%c|%c|%c|\n", board[1][0],board[1][1],board[1][2]);
    printf("+--------+\n");
    printf("|%c|%c|%c|\n", board[2][0],board[2][1],board[2][2]);
    printf("+--------+\n");
}
void resetBoard()
{
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            board[i][j] = ' ';
        }
    }
}
