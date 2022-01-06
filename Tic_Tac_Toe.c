/**
 * @file Tic_Tac_Toe.c
 * @author [shreeji0312] (https://github.com/shreeji0312)
 * @brief [Tic-Tac-Toe game](https://en.wikipedia.org/wiki/Tic-tac-toe)
 * implementation in C
 * @details User can play with other human player 
 * or also can play with computer.
 * computer can also predict the next best step.
 */


#include<stdio.h>
#include<stdlib.h>
#include<math.h>


// used to intialize the board with null values set to the each box
void InitializeBoard(int m, int n , char board[][n]){
    int c =1;
    for(int i =0; i<m; i++){
        for(int j=0; j< n; j++){
            board[i][j] = c+'0';
            c++;
        }
    }
}

// used to print the board with each current values
void PrintBoard(int m, int n, char board[][n]){
    for (int i = 0; i < m; i++){
        printf("   |   |   \n");
        for (int j = 0; j < n; j++){
            printf(" %c ", board[i][j]);
            if (j != 2)
                printf("|");
        }
        if (i != 2)
            printf("\n___|___|___\n");
        else
            printf("\n   |   |   \n");
    }
}

// to creat the new board each time when called
void Creatboard(int m, int n, char board[][n]){
    int cor;
    char xo;
    do{
        do{
        printf("\nEnter the cell no. that u want print X or O or enter -1 to exit : ");
        scanf("%d", &cor);
        if(cor == -1){
            break;
        }
        }while(!(cor>=1 || cor <=9 ));
        if(cor == -1){
            break;
        }
        char cord = cor + '0';
        do{
            printf("\nenter X or O:");
            scanf("%s", &xo);
        }while(!(xo == 'X'|| xo == 'O'));
        for(int i =0; i<m; i++){
            for(int j=0; j< n; j++){
                if(board[i][j]== cord){
                    board[i][j]=xo;
                }
            }
        }
        PrintBoard(m, n, board);
    }while(1);
}

// to check if tic tac toe board has valid value or not.
// can be called anytime
int IsValidBoard(int m, int n, char board[][n]){
    int xcount = 0, ocount = 0;
    for(int i =0; i<m; i++){
        for(int j=0; j< n; j++){
            if(board[i][j]=='X')
                xcount++;
            if(board[i][j]=='O')
                ocount++;
        }
    }
            if(xcount == ocount)
                return 1;
            else if(abs(xcount-ocount) == 1)
                return 1;
            else
                return 0;
}

//to predict the winning cell
void ListWinningCells(int m, int n, char board[][n]){
        int RowX[3]={0}, ColoumnX[3]={0}, RowO[3]={0}, ColoumnO[3]={0};
        int diagonalX=0, diagonalX1=0, diagonalO=0, diagonalO1=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X')
                    RowX[i]++;
                if(board[j][i]=='X')
                    ColoumnX[i]++;
                if(i==j && board[i][j]=='X')
                    diagonalX++;
                if((i+j)==(n-1) && board[i][j]=='X')
                    diagonalX1++;
                if(board[i][j]=='O')
                    RowO[i]++;
                if(board[j][i]=='O')
                    ColoumnO[i]++;
                if(i==j && board[i][j]=='O')
                    diagonalO++;
                if((i+j)==(n-1) && board[i][j]=='O')
                    diagonalO1++;

            }
       }
        int xcount = 0, ocount = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(RowX[i]==2 && board[i][j]!='X' && board[i][j]!='O'){
                if(xcount==0){
                    printf("Cell ");
                }
                    printf("#%c and ",board[i][j]);
                    xcount++;
                }
                if(ColoumnX[i]==2 && board[j][i]!='X' && board[j][i]!='O'){
                if(xcount==0){
                    printf("Cell ");
                }
                    printf("#%c and ",board[j][i]);
                    xcount++;
                }
                if(i==j && board[i][j]!='X'&& diagonalX==2 && board[i][j]!='O'){
                if(xcount==0){
                    printf("Cell ");
                }
                    printf("#%c and ",board[i][j]);
                    xcount++;
                }
                if((i+j)==(n-1) && board[i][j]!='X' && diagonalX1==2 && board[i][j]!='O'){
                if(xcount==0){
                    printf("Cell ");
                }
                    printf("#%c and ",board[i][j]);
                    xcount++;
                }

            }
        }
        switch(xcount){
            case 0: printf("No winning cell for player X");break;
            case 1: printf("\b\b\b\bis winning cell for player X ");break;
            default: printf("are winning cells for player X");break;
        }

        printf("\n");

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(RowO[i]==2 && board[i][j]!='X' && board[i][j]!='O'){
                if(ocount==0){
                    printf("Cell ");
                }
                    printf("#%c and ",board[i][j]);
                    ocount++;
                }

                if(ColoumnO[i]==2 && board[j][i]!='X' && board[j][i]!='O'){
                if(ocount==0){
                    printf("Cell ");
                }
                    printf("#%c and ",board[j][i]);
                    ocount++;
                }
                if(i==j && board[i][j]!='X'&& diagonalO==2 && board[i][j]!='O'){
                if(ocount==0){
                    printf("Cell ");
                }
                    printf("#%c and ",board[i][j]);
                    ocount++;
                }
                if((i+j)==(n-1) && board[i][j]!='X' && diagonalO1==2 && board[i][j]!='O'){
                if(ocount==0){
                    printf("Cell ");
                }
                    printf("#%c and ",board[i][j]);
                    ocount++;
                }
            }
        }
        switch(ocount){
            case 0: printf("No winning cell for player 0");break;
            case 1: printf("\b\b\b\bis winning cell for player 0 ");break;
            default: printf("are winning cells for player 0");break;
        }
        printf("\n");
    }

// MAIN CLASS
int main(){
    int m=3,n=3;
    char option;
    char board[m][n];
    InitializeBoard(m,n, board);
    top:
    for(int i = 0;  ; i++){
        printf("press 'p' to print the tic tac toe board.\n");
        printf("press 'c' to creat tic tac toe board with some cell X or O.\n");
        printf("press 't' to test if tic tac toe board is valid or invalid board.\n");
        printf("press 'w' to predict winning cell.\n");
        printf("press 'e' to exit.\n");
        printf("Please enter your choice.");
        fflush(stdin);
        scanf("%c", &option);


        printf("\n");
        //if(option != 'e')
            switch(option){
                case 'p':
                {
                    PrintBoard(m,n,board);
                    goto top;
                    break;
                }
                case 'c':
                {
                    Creatboard(m,n,board);
                    PrintBoard(m, n, board);
                    goto top;
                    break;
                }
                case 't':
                {
                    if(IsValidBoard(m, n, board)){
                        printf("valid board\n");
                        goto top;
                        break;
                    }
                    else{
                        printf("Invalid board\n") ;
                        goto top;
                        break;
                    }
                }
                case 'w':
                {
                    if(IsValidBoard(m, n, board)){
                        ListWinningCells(m, n, board);
                        goto top;
                        break;
                    }
                    else{
                        printf("Board is not valid.");
                        goto top;
                        break;
                    }
                }
                case 'e':{
                    return 0;
                    break;
                }
            }
//
    }
    return 0;
}
