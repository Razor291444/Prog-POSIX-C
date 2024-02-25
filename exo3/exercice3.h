#ifndef EXERCICE3_H_INCLUDED
#define EXERCICE3_H_INCLUDED

#define STR_MAX_LENGTH 100
#define RESTAURANTS_NBR 100

/*#######Déclaration de la structure Restaurant######*/
typedef struct rest {
  char nom_restaurant[STR_MAX_LENGTH];
  char adresse_restaurant[STR_MAX_LENGTH];
  double position_restaurant[2];
  char specialite[STR_MAX_LENGTH];
} Restaurant;

// On récupère dans le tableau de restaurant toutes les informations concernant
// chaque restaurant.
void setPosition(char position[], Restaurant *restau);

// Fonction pour lire les restaurants depuis le fichier
int lire_restaurant(char *chemin, Restaurant restaurants[]);

// Fonction pour insérer un restaurant à la fin du fichier
void inserer_restaurant(Restaurant restaurant);

// Fonction pour calculer la distance entre deux points (utilisée pour trier les
// résultats)
double distance(double x1, double y1, double x2, double y2);

// Fonction pour chercher les restaurants dans un rayon de recherche
void recherche_restaurant(double x, double y, double rayon_recherche,
                          const Restaurant restaurants[], Restaurant results[]);

// Fonction pour chercher les restaurants par spécialité
void cherche_par_specialite(double x, double y,
                            char specialite[][STR_MAX_LENGTH],
                            int nbr_specialite, Restaurant restaurants[],
                            Restaurant results[]);

#endif