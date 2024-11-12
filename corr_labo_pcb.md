# Format 
- `Calcul_Prix_CI` pas de mélange de format dans les nom 
- Formats autorisés : snake_case, camelCase, PascalCase


# Valeurs de retour
- Utiliser des constantes pour les valeurs de retour
```c
// Mauvais exemple, pas de commentaire mais utilisation de valeur directe
return 4; // Arguments incorrects

// Bon exemple
const int error_arguments = 4;
return error_arguments;
```

# Type 
- On utilise `double` et non `float`

# Arguments
- Déclarer des constantes pour le nombre d'arguments

# Commentaires
- Les commentaires doivent expliquer le pourquoi et pas le comment
- Pas de code commenté

# Test scanf ou sscanf
- Toujours tester le retour de scanf ou sscanf
- Possible de tester directement sans déclarer de variable
```c
    if (sscanf(argv[1], "%d", &surface_cm2) != 1) {
        return 1;
    }
```

# Fonctions
- Les fonctions doivent être déclarées avant le main

# Erreur
- Il faut traiter les erreurs au début de la fonction
```c
int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    // le code sans erreur
}
```

# Variables
- Attention de jamais placer de variable en dehors des fonctions (pas de global)
- Réduire le scope des variables au maximum
- Utiliser le const


# Code
- Ne jamais doubler du code


# Code a améliorer
## Exemple 1
```c
    if (surface_cm2 < 200) {
        printf("| CI (cm2)         | %8d | %5.2f | %6.2f |\n", (int)surface_cm2, c_prix_circuit_petit, prix_circuit);
    } 
    else {
        printf("| CI (cm2)         | %8d | %5.2f | %6.2f |\n", (int)surface_cm2, c_prix_circuit_grand, prix_circuit);
    }

    printf("| COUCHE (S)       | %8d | %5.2f | %6.2f |\n", couche, c_prix_nbr_couche * surface_cm2, prix_couche_total);
    printf("| VERNIS           | %8d | %5.2f | %6.2f |\n", 2 * (int)surface_cm2, c_prix_vernis, prix_vernis_total);

    if (diode < 10) {
        printf("| DIODE            | %8d | %5.2f | %6.2f |\n", diode, c_prix_diode_petite, prix_diode_total);
    } 
    else if (diode < 20) {
        printf("| DIODE            | %8d | %5.2f | %6.2f |\n", diode, c_prix_diode_moyenne, prix_diode_total);
    } 
    else {
        printf("| DIODE            | %8d | %5.2f | %6.2f |\n", diode, c_prix_diode_grande, prix_diode_total);
    }
```

Dans cet exemple, il ne faut pas doubler les printf
```c
if (surface_cm2 < 200) {
    c_prix = c_prix_circuit_petit;
} 
else {
    c_prix = c_prix_circuit_grand;
}
printf("| CI (cm2)         | %8d | %5.2f | %6.2f |\n", (int)surface_cm2, c_prix, prix_circuit);
```


## Exemple 2
**Jamais de variables globales**

```c
double larg_ci;
double larg_ci_cm;
double long_ci;
double long_ci_cm;
double aire_circ_impr;
int couche;
int nbre_diode;
int nbre_condo;
int nbre_resistance;
// quantité (pu = prix unité) (pt = pric total)
double pu_circ_impr;
double pt_circ_impr;
double pt_couche;
double pt_vernis;
double pu_diode;
double pt_diode;
double pu_condo;
double pt_condo;
int quantite_resistance;
double pt_resistance;
int pack_10;
double prix_ht;
double prix_tva;
double prix_ttc;

int main(){
    // code
}
```

## Exemple 3
Pas de `else if` ici mais un simple `else`
```c
    if (nbre_condo < 10)
    {
        pu_condo = 1;
    }
    else if (nbre_condo >= 10)
    {
        pu_condo = 0.80;
    }
```

## Exemple 4
Non de variable explicite

```c
const int valLongeur = sscanf(argv[1],"%d",&longeurPCB);
```


## Exemple 5
Dans cet exemple, il faut tester l'erreur et non mettre le code indenté

```c 
    if (argc == 7)
    {
        // tout le code se trouve ici indenté de 4
        return 0;
    }
```

Correct :
```c 
    if (argc != 7)
    {
        return 1;
    }

    // tout le code ici sans indentation
```

## Exemple 6 
Il ne doit pas y avoir de else ici, le code doit aller à la suite
```c 
    if(argc<7){
        printf("Pas assez d'arguments\n");
        print_help();
        return 1;
    }
    else if(argc>7){
        printf("Trop d'arguments\n");
        print_help();
        return 2;
    }
    else{
        // le code ici est faux
    }

    // Le code doit être ici
```


## Exemple 7
- le test d'erreur doit aller en haut
- pourquoi le `if(argc == 7)` est inutile ?

```c 
int main(int argc, char* argv[])
{

    double prixcircuitimprime1 = 0.12;
    const double prixcircuitimprime2 = 0.10;
    // suite des variables

    int largeur, longueur, couche, diode, cond, res;
    double TOTAL_HT;
    double TOTAL_TTC;
    double PT_CI, PT_COUCHE, PT_VERNIS, PT_DIODE, PT_COND, PT_RES, PT;

    // @tmz: test d'erreur en haut
    if (argc < 7){
        printf("Erreur : pas assez d’arguments\n");
        return 1;
    }
    if (argc > 7){
        printf("Erreur : trop d’arguments\n");
        return 2;
    }

    // @tmz: inutile comme if 
    if (argc == 7){
        const int ret1 = sscanf(argv[1], "%d", &largeur);
        const int ret2 = sscanf(argv[2], "%d", &longueur);


        if (ret1 != 1 || ret2 != 1 || ret3 != 1 || ret4 != 1 || ret5 != 1 || 
        ret6 != 1){
            printf("Erreur : argument incorrect\n");
            return 4;
        }        
    }

    // @tmz: indentation
PT_COUCHE = couche*(largeur*longueur/100)*prixnbrcouche;

if (diode < 10){
    PT_DIODE = prixdiode1*diode;
}else if (diode < 20){
    PT_DIODE = prixdiode2*diode;
    prixdiode1 = prixdiode2;
}else{
    PT_DIODE = prixdiode3*diode;
    prixdiode1 = prixdiode3;
}

// @tmz: il faut écrire sur une ligne
//int resboite = res / 10;
int resboite;

resboite = res / 10;

if (res%10 != 0){
    resboite++;
}

// @tmz: en majuscule c'est des constantes donc ne peuvent pas être modifiées
PT_RES = resboite*prixres;

PT = PT_CI+PT_COND+PT_COUCHE+PT_DIODE+PT_RES+PT_VERNIS;
TOTAL_TTC = PT*TVA+PT;
TOTAL_HT = PT*TVA;
    
// @tmz: indentation
    printf("Largeur du CI (cm)   : %d\n",(largeur/10));

// @tmz: la surface est calculée deux fois
// @tmz: il faut faire les calculs en dehors de la zone d'affichage
    printf("| CI (cm2)         |%10d |%7.2lf |%8.2lf |\n", 
    (largeur*longueur/100),prixcircuitimprime1, PT_CI);
    printf("| COUCHE (S)       |%10d |%7.2lf |%8.2lf |\n", 
    couche, prixnbrcouche, PT_COUCHE);
    printf("| VERNIS           |%10d |%7.2lf |%8.2lf |\n", 
    2*(largeur*longueur/100), prixvernis, PT_VERNIS);
    printf("| DIODE            |%10d |%7.2lf |%8.2lf |\n", 
    

    return 0;
}
```


# Solution
```c
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    const int expected_arguments = 7;
    const int error_bad_argument = 4;

    if (argc < expected_arguments) {
        printf("Error, not enough arguments!");
        // pas besoin de définir des constantes pour les codes d'erreurs car utilisé une seule fois
        return 1; 
    }

    if (argc > expected_arguments) {
        printf("Error, too much arguments!");
        // pas besoin de définir des constantes pour les codes d'erreurs car utilisé une seule fois
        return 2;
    }

    // Fetch PCB size
    const double cm2mm = 10.;    
    double width;
    double height;
    if( sscanf(argv[1], "%lf", &width) != 1 || width <= 0 ) {
        puts("Error, invalid PCB dimensions!");
        return error_bad_argument;
    }
    width /= cm2mm;

    // on pourrait regrouper les deux if en un seul
    if( sscanf(argv[2], "%lf", &height) != 1 || height <= 0 ) {
        puts("Error, invalid PCB dimensions!");
        return error_bad_argument;
    }
    height /= cm2mm;

    // Fetch number of layers
    int layers;
    if (sscanf(argv[3], "%d", &layers) != 1 || layers <= 0) {
        puts("Error, invalid number of layers!");
        return error_bad_argument;
    }

    // Fetch diodes
    int diodes;
    if (sscanf(argv[4], "%d", &diodes) != 1 || diodes < 0) {
        puts("Error, invalid number of diodes!");
        return error_bad_argument;
    }

    // Fetch capacitors
    int capacitors;
    if (sscanf(argv[5], "%d", &capacitors) != 1 || capacitors < 0) {
        puts("Error, invalid number of capacitors!");
        return error_bad_argument;
    }

    // Fetch resistors
    int resistors;
    if (sscanf(argv[6], "%d", &resistors) != 1 || resistors < 0) {
        puts("Error, invalid number of resistors!");
        return error_bad_argument;
    }

    // Displays retrieved values
    printf(
        "Devis pour réalisation de PCB\n"
        "-----------------------------\n\n");

    printf("Largeur du PCB en cm  : %5g\n", width);
    printf("Longueur du PCB en cm : %5g\n", height);
    printf("Couche(s) :             %5d\n", layers);
    printf("Nombre de diodes :      %5d\n", diodes);
    printf("Nombre condensateurs :  %5d\n", capacitors);
    printf("Nombre de résistances : %5d\n\n", resistors);

    // Compute PCB price and area
    const double area = width * height;
    const double cost_pcb = area < 200 ? 0.12 : 0.10;
    const double total_cost_pcb = area * cost_pcb;

    // Compute the cost of layers
    const double cost_layer = area * 0.05;
    const double cost_layers = cost_layer * layers;

    // Compute the cost of price of solder mask
    const double solder_mask = 0.01;
    const double cost_solder_mask = area * 2 * solder_mask; // 2 for TOP + BOTTOM

    // Diodes price
    double cost_diode = 0.60;
    if (diodes < 10)
        cost_diode =  0.75;
    else if (diodes < 20)
        cost_diode = 0.70;
    double cost_diodes = diodes * cost_diode;

    // Capacitors
    double cost_capacitor = capacitors < 10 ? 1.00 : 0.80;
    double cost_capacitors = capacitors * cost_capacitor;

    // Resistors
    const double cost_resistor = 1.0;
    resistors = resistors ? (resistors - 1) / 10 + 1 : 0;
    double cost_resistors = cost_resistor * resistors;

    // Total price
    double total_price =
        total_cost_pcb +
        cost_layers +
        cost_solder_mask +
        cost_diodes +
        cost_capacitors +
        cost_resistors;

    // VAT
    double total_vat = total_price * 0.08;
    double total_price_vat = total_vat + total_price;

    printf("+------------------+------+-------+--------+\n");
    printf("| ÉLEMENT          | QTÉ. |   PU  |   PT   |\n");
    printf("|------------------+------+-------+--------|\n");
    printf("| CI (cm2)         |%5.0f | %5.2f | %6.2f |\n", area, cost_pcb, total_cost_pcb);
    printf("| COUCHE(S)        |  %3d | %5.2f | %6.2f |\n", layers, cost_layer, cost_layers);
    printf("| VERNIS           |%5.0f | %5.2f | %6.2f |\n", 2 * area, solder_mask, cost_solder_mask);
    printf("| DIODE            |  %3d | %5.2f | %6.2f |\n", diodes, cost_diode, cost_diodes);
    printf("| CONDENSATEUR     |  %3d | %5.2f | %6.2f |\n", capacitors, cost_capacitor, cost_capacitors);
    printf("| RESISTANCE (x10) |  %3d | %5.2f | %6.2f |\n", resistors, cost_resistor, cost_resistors);
    printf("|------------------+------+-------+--------|\n");
    printf("|                        TOTAL HT | %6.2f |\n", total_price);
    printf("|                             TVA | %6.2f |\n", total_vat);
    printf("|                       TOTAL TTC | %6.2f |\n", total_price_vat);
    printf("+---------------------------------+--------+\n");
}
```