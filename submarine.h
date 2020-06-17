#ifndef SUBMARINE_H
#define SUBMARINE_H

typedef enum {FREE, OCCUPIED, MISS, HIT} status; 
typedef enum { A=1 , B, C, D, E, F, G, H, I , J, error } letter;  

typedef struct submarine
{
    int size;
    char sigh;
    int num;        //serial numer of the submarine
    status status;
}submarine;

typedef struct board 
{
    submarine board[11][11];
}board;

letter capitel(char Z); //A function that turns a char into its ASCII value

void Freemark(board *Board_Game); //A function that initializes the game board

void printBoard (board  *b,FILE *fp); //A function that print the board to the file

int size(int name,int s[10]); //A function that defines and changes the size of each submarine

board *loadData(char *fileName,board *boardAll,int s[10]); //A function that receives data from a board file of each player and applies them to the tables

void game(board *b1,board *b2,char *fileNameMoves,char *fileNameResult,int s[10],int s1[10]); //The submarine game

#endif