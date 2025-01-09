#include <stdio.h>

int main() {
    int tab[3][3] = {0};

    int matrice[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int ligne = 0;
    int colonne = 2;
    int val = tab[ligne][colonne];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    return 0;
}