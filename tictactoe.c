#include <stdio.h>
#include <stdbool.h>

#define SIZE_COL 3
#define SIZE_ROW 3

#define PLAYER1 'X'
#define PLAYER2 'O'

void print_board(char board[SIZE_ROW][SIZE_COL]){
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

bool add_piece(char board[SIZE_ROW][SIZE_COL], 
                int num_l, int num_col, char player){

    if( board[num_l][num_col] != ' ')
        return false;

    board[num_l][num_col] = player;
    return true;
}

bool is_winner(char board[SIZE_ROW][SIZE_COL], char piece){
    return false;
}

int main(){

    char board[SIZE_ROW][SIZE_COL] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    printf("Tic Tac Toe\n");

    // 1-3
    add_piece(board, 1, 1, PLAYER1);  // croix au centre
    print_board(board);
    add_piece(board, 2, 1, PLAYER2);
    print_board(board);
    add_piece(board, 1, 2, PLAYER1);
    print_board(board);
    add_piece(board, 2, 2, PLAYER2);
    print_board(board);
    add_piece(board, 3, 1, PLAYER1);

    print_board(board);
}