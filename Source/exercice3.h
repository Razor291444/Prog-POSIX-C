#ifndef EXERCICE3_H_INCLUDED
#define EXERCICE3_H_INCLUDED

/*#######Déclaration de la structure position######*/
typedef struct pos {
  double x;
  double y;
} Position;

/*#######Déclaration de la structure Restaurant######*/
typedef struct rest {
  char nom_restaurant[100];
  char adresse_restaurant[100];
  Position position_restaurant;
  char specialite[100];
} Restaurant;

// Fonction pour lire les restaurants depuis le fichier
int lire_restaurant(char *chemin, Restaurant restaurants[]);

// Fonction pour insérer un restaurant à la fin du fichier
void inserer_restaurant(Restaurant restaurant);

// Fonction pour calculer la distance entre deux points (utilisée pour trier les
// résultats)
double distance(double x1, double y1, double x2, double y2);

// Fonction pour chercher les restaurants dans un rayon de recherche
void cherche_restaurant(double x, double y, double rayon_recherche,
                        Restaurant results[]);

// Fonction pour chercher les restaurants par spécialité
void cherche_par_specialite(double x, double y, char *specialite[],
                            Restaurant results[]);

#endif