// Développer une fonction qui peremet de trouver le minimum et le maximum d'une matrice

#include <stdio.h>

#define SIZE_COL 3
#define SIZE_ROW 3

int main(){
    int matrice[SIZE_ROW][SIZE_COL] = {
        {1, 2, 3},
        {4, -5, 60},
        {7, 2, 1}
    };

    int min;
    int max;

    // appel de la fonction
 
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);

    return 0;
}