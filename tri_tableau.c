#include <stdio.h>
#include <stdbool.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void sort(int tab[], int n){
    int count_if = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            count_if++;
            if( tab[i] > tab[j] )
                swap(&tab[i], &tab[j]);
        }
    }
    printf("Il y a eu %d if\n", count_if);
}

void sort_2(int tab[], int n){
    int count_if = 0;
    int pass = 0; // pour l'affichage de l'évolution
    while(true){
        bool stop = true;
        for(int i=0; i<n-1; i++){
            count_if++;
            if( tab[i] > tab[i+1] ){
                swap(&tab[i], &tab[i+1]);
                stop = false;
            }
        }

        // Pour afficher le debug
        printf("Pass %d\n", pass);
        for(int i=0; i<n; i++){
            printf(" %d ", tab[i]);
        }
        printf("\n\n");

        if(stop)
            break;
        
        pass++;
    }

    printf("Il y a eu %d if\n", count_if);
}

int main(){

    int tab[] = {1,3,-3,5,0,12,-23,0,-100,-6};
    int tab_2[] = {1,3,-3,5,0,12,-23,0,-100,-6};
    const int n = sizeof(tab) / sizeof(tab[0]);

    for(int i=0; i<n; i++){
        printf(" %d ", tab[i]);
    }
    printf("\n");

    sort(tab, n);

    for(int i=0; i<n; i++){
        printf(" %d ", tab[i]);
    }

    printf("\n\nTri bulle\n");
    sort_2(tab_2, n);

    printf("\n");
    for(int i=0; i<n; i++){
        printf(" %d ", tab_2[i]);
    }
}