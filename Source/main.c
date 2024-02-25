#include "exercice3.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Restaurant restaurants[100];
  int nbRestaurants = lire_restaurant("restau.txt", restaurants);

  // Menu principal pour l'utilisateur
  int choix;
  double x, y, rayon_recherche;
  char *specialites[100];
  int nbSpecialites = 0;
  Restaurant nouveauRestaurant;

  do {
    printf("Menu:\n");
    printf("1. Chercher des restaurants dans un rayon\n");
    printf("2. Chercher des restaurants par spécialité\n");
    printf("3. Ajouter un restaurant\n");
    printf("4. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
    case 1:
      printf("Entrez votre position (x y) et le rayon de recherche : ");
      scanf("%lf %lf %lf", &x, &y, &rayon_recherche);
      Restaurant resultatsRayon[100];
      cherche_restaurant(x, y, rayon_recherche, resultatsRayon);
      printf("Résultats de la recherche :\n");
      for (int i = 0;
           i < 100 && !isnan(resultatsRayon[i].position_restaurant.x); i++) {
        printf("%s, %s, %s\n", resultatsRayon[i].nom_restaurant,
               resultatsRayon[i].adresse_restaurant,
               resultatsRayon[i].specialite);
      }
      break;

    case 2:
      printf("Entrez votre position (x y) : ");
      //fgets(specialitesStr, sizeof(specialitesStr), stdin)
      scanf("%lf %lf", &x, &y);
      printf(
          "Entrez les spécialités recherchées (séparées par des virgules) : ");
      char specialitesStr[100];
      fgets(specialitesStr, sizeof(specialitesStr), stdin);
      //scanf("%s", specialitesStr);
      char *spe = strtok(specialitesStr, ",");
      nbSpecialites = 0;
      while (spe != NULL) {
        strcpy(specialites[nbSpecialites], spe);
        spe = strtok(NULL, ",");
        nbSpecialites++;
      }
      Restaurant resultatsSpecialite[100];
      cherche_par_specialite(x, y, specialites, resultatsSpecialite);
      printf("Résultats de la recherche :\n");
      for (int i = 0;
           i < 100 && !isnan(resultatsSpecialite[i].position_restaurant.x);
           i++) {
        printf("%s, %s, %s\n", resultatsSpecialite[i].nom_restaurant,
               resultatsSpecialite[i].adresse_restaurant,
               resultatsSpecialite[i].specialite);
      }
      break;

    case 3:
      //Restaurant nouveauRestaurant;
      printf("Entrez le nom du restaurant : ");
      scanf("%s", nouveauRestaurant.nom_restaurant);
      printf("Entrez l'adresse du restaurant : ");
      scanf("%s", nouveauRestaurant.adresse_restaurant);
      printf("Entrez la position du restaurant (x y) : ");
      scanf("%lf %lf", &nouveauRestaurant.position_restaurant.x,
            &nouveauRestaurant.position_restaurant.y);
      printf("Entrez les spécialités du restaurant (séparées par des virgules) "
             ": ");
      fgets(nouveauRestaurant.specialite, sizeof(nouveauRestaurant.specialite), stdin);
      inserer_restaurant(nouveauRestaurant);
      break;

    case 4:
      printf("Au revoir !\n");
      break;

    default:
      printf("Choix invalide. Veuillez réessayer.\n");
    }
  } while (choix != 4);

  return 0;
}