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
    
    int pos_x = num_col - 1;
    int pos_y = num_l - 1;

    if( pos_x < 0 || pos_x >= SIZE_COL ||
        pos_y < 0 || pos_y >= SIZE_ROW ||
         board[pos_y][pos_x] != ' ')
        return false;

    board[pos_y][pos_x] = player;
    return true;
}

bool is_winner_1(char board[SIZE_ROW][SIZE_COL], char piece){
    
    // ligne
    bool win = true;
    for(int l=0; l<SIZE_ROW; l++){
        win = false;
        for(int c=0; c<SIZE_COL; c++){
            if( board[l][c] == piece ){
                win = true;
            }
            else{
                win = false;
                break;
            }
        }
        if( win )
            return true;
    }

    return true;
}

bool is_winner_2(char board[SIZE_ROW][SIZE_COL], char piece){
    
    // ligne
    for(int l=0; l<SIZE_ROW; l++){
        for(int c=0; c<SIZE_COL; c++){
            if( board[l][c] != piece )
                break;
            else{ // c'est la bonne pièce
                if( c == SIZE_COL - 1) // dernière case
                    return true;
            }
        }
    }

    return true;
}

int main(){

    char board[SIZE_ROW][SIZE_COL] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    printf("Tic Tac Toe\n");

    // 1-3

    //    1  2  3
    // 1
    // 2        X
    // 3
    if( !add_piece(board, 1, 1, PLAYER1) )
    {
        printf("Erreur");
        return 1;
    }  // croix au centre

    print_board(board);
    add_piece(board, 2, 1, PLAYER2);
    print_board(board);
    add_piece(board, 1, 2, PLAYER1);
    print_board(board);
    add_piece(board, 2, 2, PLAYER2);
    print_board(board);
    add_piece(board, 1, 3, PLAYER1);

    print_board(board);
}