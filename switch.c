// Le switch permet de simplifier du code if else if

// Exemple avec if else if

int value;

int main(){
    if( value == 0 ){
        printf("la valeur est : 0\n");
    }
    else if( value == 1 || value == 2 ){
        printf("la valeur est : 1 ou 2\n");
    }
    else if( value == 3 ){
        printf("la valeur est : 3\n");
    }
    else if( value == 4 || value == 5 || value == 6 ){
        printf("la valeur est : 4 ou 5 ou 6\n");
    }
    else{
        printf("la valeur est autre chose.\n", value);
    }

    // Exemple avec switch
    switch(value){
        case 0:
            printf("la valeur est : 0\n");
            break;
        case 1:
        case 2:
            printf("la valeur est : 1 ou 2\n");
            break;
        case 3:
            printf("la valeur est : 3\n");
            break;
        case 4:
        case 5:
        case 6:
            printf("la valeur est : 4 ou 5 ou 6\n");
            break;
        default:
            printf("la valeur est autre chose.\n", value);
    }


    // tous les états sont exécutés tant qu'il n'y a pas de break
    switch(value){
        case 0:
            printf("la valeur est : 0\n");
        case 1:
        case 2:
            printf("la valeur est : 1 ou 2\n");
        case 3:
            printf("la valeur est : 3\n");
            break;
        case 4:
        case 5:
        case 6:
            printf("la valeur est : 4 ou 5 ou 6\n");
        default:
            printf("la valeur est autre chose.\n", value);
    }

    // ici sans break l'affichage sera : 
    // la valeur est : 0
    // la valeur est : 1 ou 2
    // la valeur est : 3

    // on s'arrête au case 3 car il y a un break
    
    return 0;
}
