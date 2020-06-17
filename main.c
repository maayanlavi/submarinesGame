#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "submarine.h"

int main(int argc, char* argv[])
{
    if (argc<4) 
    {
        printf ("need more argument!");
        return 0; 
    }
    int *s=(int*)calloc(sizeof(int),10);
    int *s1=(int*)calloc(sizeof(int),10);
    
    board *b1 = (board*)calloc(1, sizeof(board));
    board *b2 = (board*)calloc(1, sizeof(board));
    char *fileName1;
    char *fileName2;
    b1=loadData(argv[1],b1,s);
    b2=loadData(argv[2],b2,s1);
    fileName1=argv[3];
    //fileName2=argv[4];
    game(b1,b2,argv[3],"Result.txt",s,s1);
    puts("c");
    free (b1);
    free (b2);
    
}