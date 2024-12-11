#include <stdio.h>


void moy(double ar[], int size, double* average, int* nbr){
   if( size == 0 ) return;
   int n=0;
   double a = 0.0;
   for(size_t pos=0; pos < size; pos++){
        if( ar[pos] > 0 ){
            a += ar[pos];
            n++;
        }
   }
   *average = a / n;
   *nbr = n;
}

int main(int argc, char* argv[]){
    double tab[] = {2.1, -3.2, 4.5, 0, 6.8};
    const int size_array = sizeof(tab) / sizeof(tab[0]);
    
    int count = 2;
    double av = 3.4;

    moy(tab, size_array, &av, &count);
    printf("adresse : %p\n\n", &av);

    printf("La moyenne : %.2lf calculée avec %d valeurs\n", av, count);
}