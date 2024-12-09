#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void repeat_stars(int nbr){
    for(int i=0; i<nbr; i++)
        printf("*");
}

void print_percent(int note, int count, int total){
    double percent = 0.1;
    printf("%d : ", note);
    repeat_stars((int)percent);
    printf("%.2lf (%d)\n", percent, count);
}

bool get_option(int argc, char* argv[], int* value){

    for(size_t i=1; i<argc; i++){
        // value est déjà une adresse donc pad de &
        if(sscanf(argv[i], "-t%d", value) == 1){
            return true;
        }

    }
    return false;
}

#define NOTE_NUMBER 7

int main() {
    srand(time(NULL));

    int notes[NOTE_NUMBER] = {0};

    int nbr_number = 0;
    const bool plot_number = get_option(argc, argv, &nbr_number);

    if( plot_number ){
        // affichage de la suite de nombre
    }
    else{
        // lecture valeur n depuis argv ???
        for(int i=0; i<n; i++){
            note = get_number(6)
            notes[note]++;
        }
    }
}
