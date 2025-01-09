/*
    Simulation d'une fusée partant à la verticale
    La fusée décolle verticalement et accélère tant qu'il lui reste du carburant. Une fois le carburant épuisé, elle monte encore sous l'effet de son inertie avant de retomber sous l'effet de la gravité.
    Le programme calcule la hauteur maximale atteinte et la vitesse maximale de la fusée.
*/


#include <stdio.h>

int main() {
    
    // Données initialisées
    double m = 1000.0;            // Masse à vide de la fusée (kg)
    double m_carburant = 500.0;   // Masse initiale de carburant (kg)
    double f_mot = 15000.0;       // Poussée du moteur (N)
    double debit = 5.0;           // Débit de carburant (kg/s)
    double g = 9.81;              // Accélération gravitationnelle (m/s^2)
    double dt = 0.01;             // Pas de temps (s)
    
    double h_max = 0.0;
    double v_max = 0.0;
    double t = 0.0;

    

    // Affichage des résultats
    printf("Hauteur maximale atteinte : %.2f m\n", h_max);
    printf("Vitesse maximale atteinte : %.2f m/s\n", v_max);
    printf("Durée totale du vol : %.2f s\n", t);
    return 0;
}
