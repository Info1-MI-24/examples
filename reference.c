#include <stdio.h>

// il faut indiquer que les valeurs de max et min sont des pointeurs avec *
// le fait d'avoir int* indique que la valeur est une adresse mémoire

// pour accéder à la valeur de l'adresse mémoire, il faut utiliser *max et *min

// *<variable> signifie que l'on accède à la valeur de l'adresse mémoire

// Pour passer la variable par référence, il faut passer l'adresse mémoire de la variable.
// Pour cela, il faut utiliser le symbole & devant la variable.

void func(int val1, int val2, int* max, int* min)
{
    if (val1 > val2){
        *max = val1;  // on utilise la valeur à l'adresse mémoire de max
        *min = val2;
    }
    else{
        *max = val2;
        *min = val1;
    }
}

int main()
{
    int a = 10; int b = 20;
    int max = 0; int min = 0;

    func(a, b, &max, &min); // on passe l'adresse mémoire de max et min

    printf("max: %d, min: %d\n", max, min);
    return 0;
}
