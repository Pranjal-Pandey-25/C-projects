#include<stdio.h>


int puzz[9][9]={
    {3,0,0,0,2,0,0,7,0},
    {9,0,0,5,0,0,0,1,4},
    {0,1,6,3,7,0,0,0,8},
    {2,0,0,8,0,0,0,0,1},
    {5,0,0,0,4,1,8,0,0},
    {0,8,9,0,0,0,0,5,0},
    {0,0,5,0,1,0,2,8,0},
    {0,4,0,0,0,6,0,9,3},
    {7,3,1,0,8,2,0,0,0}
};

void print(int puzz[9][9]){
    printf("\n\n+-------+-------+-------+");
    for (int row = 0; row < 9; row++)
    {
         if (row%3==0 && row!=0)
          {
            printf("\n|-------+-------+-------|");
          }
        printf("\n");
        for (int col = 0; col < 9; col++)
        {
            if (col%3==0)
            {
            printf("| ");    
            }
            if (puzz[row][col]==0)
            {
                printf("  "); // space space.
            }
            else{
            printf("%d ", puzz[row][col]);
            }
        }
        printf("|");
       
    }
    
    printf("\n+-------+-------+-------+");

}

int validmove(int puzz[9][9] , int row, int col, int val){
    //vaild row checking.
    for (int i = 0; i < 9; i++)
    {
        if (puzz[row][i]==val)
        {
            return 0;
        }
    }
    //vaild col checking.
    for (int i = 0; i < 9; i++)
    {
        if (puzz[i][col]==val)
        {
            return 0;
        }
    }
    int i=row - row%3;
    int j=col - col%3;
     //vaild square checking.
    for (int r=0; r < 3; r++)
    {
       for (int c = 0; c < 3; c++)
       {
        if (puzz[i+r][j+c]==val)
        {
           return 0;
        } 
       }
    }
     return 1;  
}

int solve_puzzle(int puzz[9][9],int row , int col){

    if (col==9)
    {
        if (row==8)
        {
            return 1;//puzzle is solved.
        }
        
        row++;
        col=0;
    }
    
    if (puzz[row][col]>0)
    {
        return solve_puzzle(puzz, row, col+1); // ye already filled sapaces ke liye execute ho rha hai.
    }
    for (int i = 1; i <=9; i++)
    {
       if (validmove(puzz, row, col, i))
       {
        puzz[row][col]=i;
        if (solve_puzzle(puzz,row,col+1))
        {
            return 1;
        }
        puzz[row][col]=0;
        
       }
       
    }
    return 0;
}

void main(){
    printf("\nWelcome to sudoku solver !");
    printf("Originalpuzzle is :");
    print(puzz);
    // printf("\n%d", validmove(puzz,0,1,3));
    // printf("\n%d", validmove(puzz,0,1,6));
    if (solve_puzzle(puzz,0,0))
    {
    printf("\nPuzzle is solved.");
    print(puzz);
    }else{
        printf("\nPuzzle is not solved yet.");
    }
}
