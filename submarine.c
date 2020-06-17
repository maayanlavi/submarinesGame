#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "submarine.h"

letter capitel(char Z)
{
        //A function that turns a char into its ASCII value
	switch (Z)
	{
		case 'A':
			return A;
            break;
		case 'B':
			return B;
            break;
		case 'C':
			return C;
            break;
		case 'D':
			return D;
            break;
		case 'E':
			return E;
            break;
		case 'F':
			return F;
            break;
		case 'G':
			return G;
            break;
		case 'H':
			return H;
            break;
		case 'I':
			return I;
            break;
		case 'J':
			return J;
            break;
		default: // if it's an invalid input
			return error;
            break;

	}
}




void Freemark(board *Board_Game)
{
        //A function that initializes the game board
	for (int i=0; i<=10; i++)
	{
		for (int j=0; j<= 10; j++)
		{
			Board_Game->board[i][j].status = FREE;
            Board_Game->board[i][j].sigh='-';
		}
	}
	
}
void printBoard (board  *b,FILE *fp)
{
   int i, j;
   fprintf(fp,"\n  ");
   for (char c= 'A'; c <='J'; c++)
   {
       fprintf (fp, "%c ", c);
   }
   fprintf(fp,"\n");
          
    for(i = 1; i <= 10; ++i)
        {
            fprintf (fp,"%d ", i);
            for(j = 1; j < 11; ++j)
                fprintf(fp,"%c ", b->board[i][j].sigh);  
                fprintf(fp,"\n");
      
        }

    
        

}

int size(int name,int s[10])
{
    //A function that defines and changes the size of each submarine
    int c1=s[1];
    int c2=s[2];
    int c3=s[3];
    int c4=s[4];
    int c5=s[5];
    int c6=s[6]; 
    int c7=s[7];
    int c8=s[8];
    int c9=s[9];
    int c10=s[10];
    switch (name)
            {
                case 1:              
                    c1--;
                    return c1;
                    break;
                case 2:
                    c2--;
                    return c2;
                    break;
                case 3:           
                    c3--;
                    return c3;
                    break;
                case 4:             
                    c4--;
                    return c4;
                    break;
                    
                 case 5 :               
                    c5--;
                    return c5;
                    break;
                case 6 :               
                    c6--;
                    return c6;
                    break;
                case 7 :                
                    c7--;
                    return c7;
                    break;
                case 8 :             
                    c8--;
                    return c8;
                    break;
                case 9 :               
                    c9--;
                    return c9;
                    break;
                case 10 :              
                    c10--;
                    return c10;
                    break;
                default:
                    break;
            }



}





board *loadData(char *fileName,board *boardAll,int s[10])
{           
    //A function that receives data from a board file of each player and applies them to the tables
    s[9]='\0';
    Freemark(boardAll);
    FILE *fp=fopen(fileName,"r");
    char line[100];
   
    if(fp==NULL)
    {
        printf("error");
        exit(0);
    }

   int n=1;
    int j=0;
    int firstNum=0;
    int lastNum=0;
    char * space = "-";
	char * down = "\n";
	char *head;
	int c=0;
    char *tail;
    while(fgets(line,1000,fp)!=NULL)
    {
        if(line[0]!='#' && line[0]!='\n' && line[0]!='\r')
        {
			head = strdup(strtok(line, space));
			tail = strdup(strtok(NULL, down));
            int  h=capitel(head[0]);    //the first char
            int  t=capitel(tail[0]);    //the last char    
           if(head[1]==49 && head[2]==48)
           {
                firstNum=10;        //End case if line number is 10
           } 
           else
           {
                firstNum = head[1] - '0';  //changes to ASCII
           }
           if(tail[1]==49 && tail[2]==48)
           {
                lastNum=10;         //End case if line number is 10
           } 
           else
           {
                lastNum=tail[1] - '0';  //changes to ASCII
           }
            if(h==t)        //A case in which the submarine is vertical

                    //Checking that no submarine had been placed diagonally into another submarine
            {   if (boardAll->board[firstNum-1][h-1].status==OCCUPIED || boardAll->board[firstNum-1][h+1].status==OCCUPIED || boardAll->board[lastNum+1][h-1].status==OCCUPIED || boardAll->board[lastNum+1][h+1].status==OCCUPIED )
                        printf ("error- ALACHSON! \n");
                    for( j=firstNum;j<=lastNum;j++)
                    {
                        boardAll->board[j][h].num=n;  //serial number of the submarine
                        boardAll->board[j][h].size = lastNum-firstNum+1;   
                        s[n]=lastNum-firstNum+1;    //size of submarine
                        boardAll->board[j][h].status=OCCUPIED;   
                        
                    }
            }
            if(firstNum==lastNum)   //Case in which the submarine horizontally
            {
                if (boardAll->board[firstNum-1][h-1].status==OCCUPIED || boardAll->board[lastNum+1][h+1].status==OCCUPIED || boardAll->board[firstNum-1][h-1].status==OCCUPIED || boardAll->board[lastNum+1][h-1].status==OCCUPIED )
                        printf ("error- ALACHSON! \n");
               
				for(int i=h;i<=t;i++)
				{  
					if(boardAll->board[firstNum][i].status==FREE)
					{
					boardAll->board[firstNum][i].num=n;
                    boardAll->board[firstNum][i].size = t-h+1;   
					s[n]=t-h+1;
                    boardAll->board[firstNum][i].status=OCCUPIED;   
					}
				}
            
        	}
    	}

   n++;  //the next serial
    }
    fclose (fp);
    return boardAll;
    
}

void game(board *b1,board *b2,char *fileNameMoves,char *fileNameResult,int s[10],int s1[10])
{
    FILE *fp1=fopen(fileNameMoves,"r");
    FILE *fp2=fopen(fileNameResult, "w");
    int count=0;
    char line1[100];
    char lineSave[100];
    char *player;
    char *move;
    board *newB1=(board*)calloc(1, sizeof(board));
    board *newB2=(board*)calloc(1, sizeof(board));
    Freemark(newB1);
    Freemark(newB2);
    int flag=0;
    int victory1=1,victory2=1;        
    

    while(fgets(line1,1000,fp1))
    {
        if(line1[0]!='#' && line1[0]!='\n' && line1[0]!='\r')
        {
            strcpy(lineSave,line1);
            player=strdup(strtok(line1," "));
            if((player[7]=='1')&&(flag==0))         //The place where the player's number is written
            { 
                move=strdup(strtok(NULL,"\n"));
                int m1=move[1]-'0';
                int m2=move[2]-'0';
                letter m0=capitel(move[0]);

                if (move[1]==49 && move[2]==48)
                    m1=10;
                    

                if((m0>10)||(m2>0)||((m1>0)&&(move[2]==48)&&(m1!=10)))      //bad move
                {
                    fprintf(fp2,"%s" , lineSave);
                    fprintf(fp2,"error! \n");
                }
                else
                {
                if(b2->board[m1][m0].status==OCCUPIED)
                {
                    newB2->board[m1][m0].sigh='X';
                    fprintf(fp2,lineSave);
                    fprintf(fp2,"hit! \n");
                    count=size(b2->board[m1][m0].num,s1);
                    s1[b2->board[m1][m0].num]=s1[b2->board[m1][m0].num]-1;
                     if(count==0)
                     {
                         fprintf(fp2,"the submarine exploded!\n");
                         victory1++;
                     }
                     if(victory1==10)
                     {
                         fprintf(fp2,"player 1 winner!");
                         exit(0);
                     }
                
                }
                else
                {
                    newB2->board[m1][m0].sigh='O';
                    fprintf(fp2,lineSave);
                    fprintf(fp2,"miss! \n");
                }
                }
                flag=1;
            }

            if((player[7]=='2')&&(flag==1))
            {
                move=strdup(strtok(NULL,"\n"));
                int m1=move[1]-'0';
                int m2=move[2]-'0';
                letter m0=capitel(move[0]);
                if((m0>10)||(m2>0)||((m1>0)&&(move[2]==48)&&(m1!=10)))      //bad move
                {
                    fprintf(fp2,"%s" , lineSave);
                    fprintf(fp2,"error! \n");
                }
                else
                {
                if(b1->board[m1][m0].status==OCCUPIED)
                {
                    newB1->board[m1][m0].sigh='X';
                    
                    fprintf(fp2,lineSave);
                    fprintf(fp2,"hit! \n");
                    count=size(b1->board[m1][m0].num,s);
                    s[b1->board[m1][m0].num]=s[b1->board[m1][m0].num]-1;
                    if(count==0)        //no more life to the submarine
                    {
                        fprintf(fp2,"the submarine exploded!\n");
                        victory2++;
                    }
                    if(victory2==10)
                     {
                         fprintf(fp2,"player 2 winner!");
                         exit(0);
                     }
                
                }
                else
                {
                    newB1->board[m1][m0].sigh='O';
                    fprintf(fp2,lineSave);
                    fprintf(fp2,"miss! \n");
                }
                    flag=0;
                }
            }
            }


        }
    fprintf(fp2,"player 1 board:");
    printBoard(newB1,fp2);
    fprintf(fp2,"\n");
    fprintf(fp2,"player 2 board:");
    printBoard(newB2,fp2);
    fclose (fp2);
    fclose (fp1);
     
}

