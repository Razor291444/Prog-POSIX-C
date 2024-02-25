#ifndef EXERCICE3_H_INCLUDED
#define EXERCICE3_H_INCLUDED

typedef struct rest {
    char nom_restaurant[100];
    char adresse_restaurant[100];
    double position_restaurant[2]; //Coordonnées (x, y)
    char specialite[100];
} Restaurant;

int lire_restaurant(char* chemin, Restaurant restaurants []);

/*void inserer_restaurant(Restaurant restaurant);

void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[]);

void cherche_par_specialite(double x, double y, char* specialite[], Restaurant results[]);*/



#endif