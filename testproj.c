#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
void setColor(int);
void ClearConsoleToColors(int,int);
int k=0;
bool chksafety(int board[][100],int i,int j,int n)
{
    int row,x,y;
    //col
    for(row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }

    //left diagonal
    x=i;
    y=j;

    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    //right diagonal
    x=i;
    y=j;

    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }

    return true;
}

bool chksafety2(int board[][10],int i,int j,int n)
{
    int row,x,y;
    //col
    for(row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }

    //left diagonal
    x=i--;
    y=j--;

    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    //right diagonal
    x=i--;
    y=j++;

    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }

    return true;
}

bool Noofsol(int board[][100],int i,int n)
{
    FILE *fpt;
    fpt = fopen("program.txt", "w");
    if(fpt == NULL)
   {
      return false;
   }
    int j;
    bool nextqueenplace;
    // base case
    if(i==n)
    {
        //print board
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(board[i][j]==1)
                    fprintf(fpt,"%c"," Q ");
                else
                    fprintf(fpt,"%c"," _ ");
            }

        }
        k++;
        return false;


    }

    //recursive case
    for(j=0;j<n;j++)
    {
        //check for safe position

        if(chksafety(board,i,j,n))
        {
            board[i][j]=1;

            nextqueenplace=Noofsol(board,i+1,n);

            if(nextqueenplace==true)
            {
                return true;
            }


            board[i][j]=0;//backtracked

        }
    }
    return false;

}

bool Allsolutions(int board[][100],int i,int n)
{
    int j;
    bool nextqueenplace;
    // base case
    if(i==n)
    {
        //print board
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(board[i][j]==1)
                    printf(" Q ");
                else
                    printf(" _ ");
            }
            printf("\n");

        }
        printf("\n \n");
        return false;

    }

    //recursive case
    for(j=0;j<n;j++)
    {
        //check for safe position

        if(chksafety(board,i,j,n))
        {
            board[i][j]=1;

            nextqueenplace=Allsolutions(board,i+1,n);

            if(nextqueenplace==true)
            {
                return true;
            }


            board[i][j]=0;//backtracked

        }
    }
    return false;


}

bool solvequeensolution(int board[][100],int i,int n)
{
    int j;
    bool nextqueenplace;
    // base case
    if(i==n)
    {
        //print board
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(board[i][j]==1)
                    printf(" Q ");
                else
                    printf(" _ ");
            }
            printf("\n");

        }
        printf("\n \n");
        return true;

    }

    //recursive case
    for(j=0;j<n;j++)
    {
        //check for safe position

        if(chksafety(board,i,j,n))
        {
            board[i][j]=1;

            nextqueenplace=solvequeensolution(board,i+1,n);

            if(nextqueenplace==true)
            {
                return true;
            }


            board[i][j]=0;//backtracked

        }
    }
    return false;


}

void graphics()
{
        char c,d;
    FILE *fptr1;

    FILE *fptr = fopen("queenimg.txt", "r");
    if (fptr == NULL)
    {
        printf("Could not open file");
        return 0;
    }

    while (c != EOF)
    {
    setColor(12);
        printf ("%c", c);
        c = fgetc(fptr);
    }

    printf("\n");
    fptr = fopen("mqueentxt.txt", "r");
    if (fptr == NULL)
    {
        printf("Could not open file");
        return 0;
    }

    while (d != EOF)
    {setColor(5);
        printf ("%c", d);
        d = fgetc(fptr);
    }

    fclose(fptr);
}

int main()
{
    ClearConsoleToColors(0,15);
int opt=0;
int n,cho;
int board[100][100]={0};
int board1[100][100]={0};
int board2[100][100]={0};
int example[4][4]={
              { 0,  1,  0,  0},
              { 0,  0,  0,  1},
              { 1,  0,  0,  0},
              { 0,  0,  1,  0}
};
int i,j;
graphics();
do{ClearConsoleToColors(0,15);
   printf("\n");
   system("CLS");
   graphics();
   printf("\t\t\t\t\t1.Know About The N-Queen Problem \n\n");
   printf("\t\t\t\t\t2.Number of N-Queen solution for a given n \n\n");
   printf("\t\t\t\t\t3.Print solution of N-queen \n\n");
   printf("\t\t\t\t\t4.Print all solutions of N-Queen problem \n\n");
   printf("\t\t\t\t\t5.Play N-Queen game\n\n");
   printf("\t\t\t\t\t6.EXIT\n\n");
   printf("\t\t\t\t\tPlease enter your choice \t");
   scanf("\t\t\t\t\t\n%d",&cho);

   if(cho==1)
   {ClearConsoleToColors(0,6);
       system("CLS");
       printf("The N Queen is the problem of placing N chess queens on an \n N*N chessboard so that no two queens attack each other.For eg. when value of n is 4\n\n");
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(example[i][j]==1)
                printf(" Q ");
                else
                    printf(" _ ");
            }
            printf("\n");
        }
       printf("\ndo you want to continue(1) or leave(0)\n");
       scanf("\n%d",&opt);

   }
   else if(cho==2)
   {ClearConsoleToColors(10,14);
       system("CLS");
       printf("enter the value of n");
       scanf("%d",&n);
       Noofsol(board,0,n);
       printf("The number of solutions of given N-Queen are %d",k);
       printf("\ndo you want to continue(1) or leave(0)\n");
       scanf("%d",&opt);
   }
   else if(cho==3)
   {ClearConsoleToColors(13,0);


        system("CLS");
        printf("enter the value of n");
        scanf("%d",&n);
        solvequeensolution(board1,0,n);
        printf("\ndo you want to continue(1) or leave(0)\n");
        scanf("%d",&opt);

   }
   else if(cho==4)
   {ClearConsoleToColors(15,4);
       system("CLS");
       printf("enter the value of n \n");
       scanf("%d",&n);
       Allsolutions(board2,0,n);
       printf("\ndo you want to continue(1) or leave(0)\n");
       scanf("%d",&opt);

   }
 else if(cho==5)
   {
       system("CLS");
       int z=0;
       int input[100];
       int index[100][100];
       printf("Welcome to N-queen Game\n");
       printf("\nEnter the value of \n");
       scanf("%d",&n);
       for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d     ",z);
                index[i][j]=z;
                z++;
            }
            printf("\n\n");
        }


       printf("\nEnter the indexes in the above matrix,where you want to place the queens\n");

       for(i=0;i<n;i++)
       {   printf("\nPlace %d:-   ",(i+1));
           scanf("%d",&input[i]);
       }

        z=0;
        int a;
        int b;
        while(z<n)
        {
          a=input[z];
          for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)
            {
                b=index[i][j];

                 if(a==b)
                {
                  board[i][j]=1;
                }
            }
         }
         z++;
        }

         for(i=0;i<n;i++)
         {
            for(j=0;j<n;j++)
            {
                printf("%d",board[i][j]);
            }
            printf("\n");
        }

        int chk[100];
        z=0;
        for(i=0;i<n;i++)
        {
         for(j=0;j<n;j++)
         {
          if(board[i][j]==1)
           {
            if(chksafety2(board,i,j,n))
            {
            chk[z]=1;
            z++;
            }
            else
            {
             chk[z]=0;
             z++;
            }
           }
         }
        }


       z=0;
       int flag=1;
       if(input[0]==1&&input[1]==7&&input[2]==8&&input[3]==14)
       {
           printf("CONGRATS FOR CORRECT SOLUTION");
       }
       else if(input[0]==2&&input[1]==4&&input[2]==11&&input[3]==13)
       {
           printf(" CONGRATS FOR CORRECT SOLUTION");
       }
else
    printf("SORRY! BETTER LUCK NEXT TIME");

       printf("\ndo you want to continue(1) or leave(0)\n");
       scanf("%d",&opt);

   }


   else if(cho==6)
   {
       exit(0);
   }

}while(opt==1);

return 0;
}


void setColor(int ForgC)
{
    WORD wcolor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
        wcolor=(csbi.wAttributes &0xF0)+(ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut,wcolor);
    }

}

void ClearConsoleToColors(int ForgC, int BackC)
 {
 WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
                                                     //Get the handle to the current output buffer...
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                                                 //This is used to reset the carat/cursor to the top left.
 COORD coord = {0, 0};

   DWORD count;                                       //A return value... indicating how many chars were written

                                                //This is a structure containing all of the console info
                                                         // it is used here to find the size of the console.
 CONSOLE_SCREEN_BUFFER_INFO csbi;
                                                                  //Here we will set the current color
 SetConsoleTextAttribute(hStdOut, wColor);
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                                                                    //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                          //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
 }
 return;
}
