#include <stdio.h>
#include <stdbool.h>

#define SIZE_COL 3
#define SIZE_ROW 3


#define PLAYER1 'X'
#define PLAYER2 'O'

void print_board(char board[SIZE_COL][SIZE_ROW]){
    puts("");
    for(int i = 0; i < SIZE_COL; i++){        
        for(int j = 0; j < SIZE_ROW; j++){
            printf("%c", board[i][j]);
            if(j < SIZE_ROW - 1){
                printf(" | ");
            }
        }
        if(i < SIZE_COL - 1){
            printf("\n---------");
        }
        printf("\n");
    }
}

void add_piece(){

}

bool is_winner(char board[SIZE_COL][SIZE_ROW], char piece){
    return false;
}

int main(){
    
    char board[SIZE_COL][SIZE_ROW] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    printf("Tic Tac Toe\n");

    print_board(board);
}