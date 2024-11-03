#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("Nombre d'arguments reçus : %d\n", argc);

    if( argc < 2 ){
      printf("Il manque des arguments\n");
      return 1;      
    }

    // argv == -h
    if( strcmp( argv[1], "-h") == 0 ){
        // argument 1 vaut -h
        printf("Voici l'aide du programe ....\n");
        return 0;
    }

    if( argc >= 3 ){ // controle du nombre d'arguments
      int val1;
      int val2;
    
      const int ret1 = sscanf(argv[1], "%d", &val1);
      const int ret2 = sscanf(argv[2], "%d", &val2);

      if( ret1 == 1 && ret2 == 1){
        const int result = val1 + val2;
        printf("La somme de %d et %d est %d\n", val1, val2, val1 + val2);
      } 
      else {
        printf("Erreur de saisie\n");
      }
    }
    else {
      printf("Il manque des arguments\n");
    }

    return 0;
}
