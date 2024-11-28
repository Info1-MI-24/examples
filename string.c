#include <stdio.h>

#define SIZE_BUFF 10

void print_nbr_char(char t[]){

    int nb = strlen(t);
    int nb1 = sizeof(t); // donne la taille de l'adresse et non du tableau
    printf("Le nombre de char est : %d", nb);

    t[0] = 'A';
}


int main()
{
    char txt[] = "Bonjour"; // tableau 8

    // on ne doit pas utiliser de variable
    char txt2[SIZE_BUFF] = "Hello"; // tableau 10

    printf("%s\n", txt);

    size_t length = sizeof(txt); // 8
    size_t length2 = sizeof(txt2); // 10 donne la taille en mémoire

    printf( "Le char 3 est : %c\n", txt[3]);

    printf("La taille : %ld\n", length); // 8

    int nbr_char = strlen(txt2); // retourne le nombre de caractère

    // parcourir une chaîne de caractères
    for( int i = 0; txt[i] != '\0' ; i++){
        printf("Char %d = %c\n", i, txt[i]);
    }

    print_nbr_char(txt); // cette fonction modifie le tableau (chaîne de caractères)
    printf("%s", txt); // Aoujour;

}