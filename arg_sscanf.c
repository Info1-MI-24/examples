#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Nombre d'arguments reçus : %d\n", argc);

    
    printf("Argument 0: %s\n", argv[0]);
    printf("Argument 1 : %s\n", argv[1]);
    
    int value;
    const int ret = sscanf(argv[1], "%d", &value);
    if (ret == 1)
        printf("La valeur est : %d", value);

    return 0;
}
