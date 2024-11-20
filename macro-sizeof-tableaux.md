# Liens
La théorie pour cette partie se trouve ici :
- https://heig-tin-info.github.io/handout/content/composite-datatypes.html?highlight=tableau#types-composites
- https://heig-tin-info.github.io/handout/content/preprocessor.html?highlight=macro#preprocesseur

# Macro
Une macro en C est définie ainsi :
```c
#define NOM_MACRO valeur
```

Voici un exemple de macro et de son utilisation :
```c
#define PI 3.14159

int main() {
    double rayon = 5.0;
    double aire = PI * rayon * rayon;
    return 0;
}
```

Dans cette exemple, la macro `PI` est définie avec la valeur `3.14159`. Cette macro est ensuite utilisée pour calculer l'aire d'un cercle.
Dans ce code, le préprocesseur remplace `PI` par `3.14159` avant la compilation.

# Sizeof
L'instruction `sizeof` permet de connaître la taille en octets d'un type ou d'une variable.

```c
#include <stdio.h>

int main() {
    int a = 5;
    printf("La taille d'un entier est de %d octets\n", sizeof(int));
    printf("La taille de la variable a est de %d octets\n", sizeof(a));
    return 0;
}
```

Il est important de se rappeler que la taille d'un type peut varier en fonction de l'architecture de la machine.


# Tableaux
## Déclaration
Un tableau en C est déclaré de la manière suivante :
```c
type nom_tableau[taille];

// Exemple pour un tableau de 5 entiers
int tab[5];
```

>Il est très important que la taille d'un tableau soit connue à la compilation. Donc on ne peut
pas déclarer un tableau avec une taille variable.

Pour déclarer la taille d'un tableau, nous allons très souvent utiliser une macro :
```c
#define TAILLE 5
int tab[TAILLE];

// Utilisation de la macro
for (int i = 0; i < TAILLE; i++) {
    tab[i] = i;
}
```

## Initialisation
Un tableau peut être initialisé lors de sa déclaration :
```c
// Initialisation d'un tableau de 5 entiers à 0
int tab[5] = {0};

// Initialisation d'un tableau de 5 entiers
int tab[5] = {1, 2, 3, 4, 5};

// Initialisation d'un tableau de 5 entiers avec les deux premières valeurs connues
int tab[5] = {1, 2}; // tab = {1, 2, 0, 0, 0}
```

Il est possible d'initialiser un tableau sans donner sa taille :
```c
int tab[] = {1, 2, 3, 4, 5}; // tab = {1, 2, 3, 4, 5}
```

La taille sera automatiquement déduite du nombre d'éléments dans l'initialisation.

## Accès aux éléments
Les éléments d'un tableau sont accessibles par leur indice, qui commence à 0 :
```c
int tab[5] = {1, 2, 3, 4, 5};
int premier = tab[0]; // premier = 1
int dernier = tab[4]; // dernier = 5
```

## Parcours
Pour parcourir un tableau, on utilise une boucle `for` :
Il est préférable d'utiliser une macro pour la taille du tableau :
```c
#define TAILLE 5
int tab[TAILLE] = {1, 2, 3, 4, 5};
for (int i = 0; i < TAILLE; i++) {
    printf("%d\n", tab[i]);
}
```
## Taille d'un tableau
Si on utilise l'opérateur `sizeof` sur un tableau, on obtient la taille totale du tableau en octets :
```c
int tab[5];
printf("La taille du tableau est de %d octets\n", sizeof(tab));
```

**Cette taille n'est pas le nombre d'éléments du tableau, mais la taille totale en octets du tableau.**

Pour calculer le nombre d'éléments d'un tableau, on peut diviser la taille totale par la taille d'un élément :
```c
int tab[5];
int taille = sizeof(tab) / sizeof(tab[0]);
printf("Le tableau contient %d éléments\n", taille);
```