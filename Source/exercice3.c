#include "exercice3.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour lire les restaurants depuis le fichier
int lire_restaurant(char *chemin, Restaurant restaurants[]) {
  FILE *fichier = fopen("restau.txt", "r");

  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return 0;
  }

  int nbRestaurants = 0;
  while (fscanf(fichier, "%s %s %lf %lf %[^\n]",
                restaurants[nbRestaurants].nom_restaurant,
                restaurants[nbRestaurants].adresse_restaurant,
                &restaurants[nbRestaurants].position_restaurant.x,
                &restaurants[nbRestaurants].position_restaurant.y,
                restaurants[nbRestaurants].specialite) != EOF) {
    nbRestaurants++;
  }

  fclose(fichier);
  return nbRestaurants;
}

// Fonction pour insérer un restaurant à la fin du fichier
void inserer_restaurant(Restaurant restaurant) {
  FILE *fichier = fopen("restau.txt", "a");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return; // Erreur lors de l'ouverture du fichier
  }

  fprintf(fichier, "%s %s %lf %lf %s\n", restaurant.nom_restaurant,
          restaurant.adresse_restaurant, restaurant.position_restaurant.x,
          restaurant.position_restaurant.y, restaurant.specialite);

  fclose(fichier);
}

// Fonction pour calculer la distance entre deux points (utilisée pour trier les
// résultats)
double distance(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Fonction pour chercher les restaurants dans un rayon de recherche
void cherche_restaurant(double x, double y, double rayon_recherche,
                        Restaurant results[]) {
  FILE *fichier = fopen("restau.txt", "r");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return; // Le fichier n'existe pas
  }

  int nbResultats = 0;
  Restaurant restaurant;
  while (
      fscanf(fichier, "%s %s %lf %lf %[^\n]", restaurant.nom_restaurant,
             restaurant.adresse_restaurant, &restaurant.position_restaurant.x,
             &restaurant.position_restaurant.y, restaurant.specialite) != EOF) {
    double dist = distance(x, y, restaurant.position_restaurant.x,
                           restaurant.position_restaurant.y);
    if (dist <= rayon_recherche) {
      results[nbResultats] = restaurant;
      nbResultats++;
    }
  }

  fclose(fichier);
}

// Fonction pour chercher les restaurants par spécialité
void cherche_par_specialite(double x, double y, char *specialite[],
                            Restaurant results[]) {
  FILE *fichier = fopen("restau.txt", "r");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return; // Le fichier n'existe pas
  }

  int nbResultats = 0;
  Restaurant restaurant;
  while (
      fscanf(fichier, "%s %s %lf %lf %[^\n]", restaurant.nom_restaurant,
             restaurant.adresse_restaurant, &restaurant.position_restaurant.x,
             &restaurant.position_restaurant.y, restaurant.specialite) != EOF) {
    // Vérifie si la spécialité du restaurant est dans la liste
    char *spe = strtok(restaurant.specialite, ",");
    while (spe != NULL) {
      for (int i = 0; specialite[i] != NULL; i++) {
        if (strcmp(specialite[i], spe) == 0) {
          results[nbResultats] = restaurant;
          nbResultats++;
          break;
        }
      }
      spe = strtok(NULL, ",");
    }
  }

  fclose(fichier);
}
