// Développer une fonction qui peremet de trouver le minimum et le maximum d'une matrice

// Développer une fonction de type bool qui permet de trouver la première occurence d'un caractère dans une chaîne.
// Si le caractère n'est pas trouvé, la fonction retourne false;
// Sinon, elle retourne true et met à jour la position du caractère dans la variable passée en paramètre.
// La fonction est insensitive à la casse.
// Afficher la chaîne de caractère depuis la position trouvée jusqu'à la fin de la chaîne.

#include <stdio.h>
#include <stdbool.h>

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


    char chaine[] = "Bonjour, comment allez-vous?";

    int position;
    char caractere = 'V';

    // appel de la fonction
    bool is_found = true;

    if( is_found ){
        printf("Le caractère %c a été trouvé à la position %d\n", caractere, position);
        printf("La chaîne à partir de la position %d est: %s\n", position, "");
    }
    else{
        printf("Le caractère %c n'a pas été trouvé\n", caractere);
    }

    return 0;
}