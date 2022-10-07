/* 
    Program: first.c
    Programmer: Eugene Kim

    This program practices the game called "Tic-Tac-Toe"

    First approach: 
    1. Create a function that keep displays the template, using printf()
    2. use random() NOT suedo random () (range 1-9)
    3. use switch cases for the user input


    Function List

    void resetBoard()
    void printBorad()
    void playerMove()
    void computerMove()
    bool isFull() // if return true && No winner, its a draw
    int checkWinner(); // 1=yes 0=progressing -1=noWinner

    
   

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 


// Global Variables
char board[3][3];
char winner;
const char O = 'O'; // player2 and computer
const char X = 'X'; // player1


void printDash();
void displayBoard();
void resetBoard();
void computerMove();
int isFull();
void playerMove();
int checkWinner();


int main() {

    // create variables 
    int choice, again;
    srand(time(0)); // use current time as seed for random generator

    // prompt the user for game they wish to play
    // read information from console
    
    do{
        // Game start
        printDash();
        printf("WELCOME TO TIC TAC TOE!\n");
        printf("1 --- person vs. person\n");
        printf("2 --- person vs. random computer\n");
        scanf("%d", &choice);
        printDash();


        resetBoard();


        if(choice == 1) // vs person
        {

            printf("still working on it\n");

        }
        else if(choice == 2) // vs computer
        {
            printf("You have entered 2\n");
            int status = checkWinner();
            int who = 0; // range 0-1, 0=player, 1=computer
            int counter = 2;
            
            
            // game play loop
            do {
                // display current board
                printf("The current Status is: \n");
                displayBoard();
                who = counter % 2;
                
                if(who == 0)
                {
                    playerMove();
                }
                else
                {
                    computerMove();
                }
                ++counter;

                status = checkWinner();
            } while(status == 0);
            
            // Exit the game loop when we have winner(1) or tie (-1)
            if((status == 1) && (winner == X))
            {
                printf("Player1 win!!!\n");
            }
            else if((status == 1) && (winner == O))
            {
                printf("Computer Won...\n");
            }
            else
            {
                printf("It's a tie\n");
            }
        

        }
        else 
        {
            printf("Invalid choice!!!\n");
            return 0;
        }

        printf("Do you want to play again? 1)YES 2)NO: ");
        scanf("%d", &again);

        //Game end
    } while (again == 1);






    



    return 0;
    
}

void printDash()
{
    printf("==========================");
}
void displayBoard()
{
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", board[0][0],board[0][1],board[0][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", board[1][0],board[1][1],board[1][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", board[2][0],board[2][1],board[2][2]);
    printf("+-----------+\n");
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
void computerMove()
{
    int x,y;
    
    do{
        x = (rand() % 3); // range 0-2
        y = (rand() % 3); 

        if (board[x][y] != ' ')
        {
            // CASE: invalid input generated
            continue;
        }
        else 
        {
            // CASE: valid input generated 
            board[x][y] = O;
        }

    }while(board[x][y] != ' '); // loop until input spot is not empty

}
int isFull()
{
    int full = 1;
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j<3;++j)
        {
            if(board[i][j] == ' ')
            {
                // if encounter any open spot, then it not full
                full = 0;
            }
        }
    }

    return full; 
}
void playerMove()
{
    // this funciton get input from user, mark the move on board
    int x,y;
    printf("Player1: make your move\n");
    
    do{
        scanf("%d %d", &x, &y);
        if(board[x][y] == ' ')
        {
            // if spot is empty, mark
            board[x][y] = X;
            break;
        }
        else 
        {
            printf("Invalid move, try again!\n");
        }
    
    }while(1);


}
int checkWinner()
{
    // initially 0 = progressing
    int result = 0; 

    if((board[0][0] == board[0][1]) && (board[0][1] == board[0][2])) 
    {
        // Column check start
        winner = board[0][0]; // store winning character 
        result = 1;
    }
    else if((board[1][0] == board[1][1]) && (board[1][1] == board[1][2])) 
    {
        winner = board[1][0];
        result = 1;
    }
    else if((board[2][0] == board[2][1]) && (board[2][1] == board[2][2]))
    {
        winner = board[2][0];
        result = 1;
    } 
    else if((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]))
    {
        // ROW check start
        winner = board[0][0];
        result = 1;
    }
    else if((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]))
    {
        winner = board[0][1];
        result = 1;
    }
    else if((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]))
    {
        winner = board[0][2];
        result = 1;
    }
    else if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
    {
        // diagnal check start
        winner = board[0][0];
        result = 1;
    }
    else if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
    {
        winner = board[0][2];
        result = 1;
    }
    else
    {
        //enter here if no match found
        if(isFull())
        {
            //enter here when board is full, but no matching winner found
            result = -1; // tie
        }
        else
        {
            result = 0; //still progressing
        }

    }

    return result;
    


}