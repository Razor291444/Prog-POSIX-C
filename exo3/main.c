#include "exercice3.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPECIALITES 100

int main() {
  Restaurant restaurants[RESTAURANTS_NBR];
  int nbRestaurants = lire_restaurant("restau.txt", restaurants);
  // printf("%d\n", nbRestaurants);

  // Menu principal pour l'utilisateur
  int choix;
  double x, y, rayon_recherche;
  char specialites[MAX_SPECIALITES][STR_MAX_LENGTH];
  int nbSpecialites = 0;
  Restaurant nouveauRestaurant;

  do {
    printf("Menu:\n");
    printf("1. Chercher des restaurants dans un rayon\n");
    printf("2. Chercher des restaurants par spécialité\n");
    printf("3. Ajouter un restaurant\n");
    printf("4. Afficher le nombre des restaurants\n");
    printf("5. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
    case 1:
      printf("Entrez votre position (x y) et le rayon de recherche : ");
      scanf("%lf %lf %lf", &x, &y, &rayon_recherche);
      Restaurant resultatsRayon[RESTAURANTS_NBR];
      recherche_restaurant(x, y, rayon_recherche, restaurants, resultatsRayon);
      printf("Résultats de la recherche :\n");
      for (int i = 0;
           i < RESTAURANTS_NBR && resultatsRayon[i].nom_restaurant[0] != '\0';
           i++) {
        printf("%s, %s, (%f, %f), %s\n", resultatsRayon[i].nom_restaurant,
               resultatsRayon[i].adresse_restaurant,
               resultatsRayon[i].position_restaurant[0],
               resultatsRayon[i].position_restaurant[1],
               resultatsRayon[i].specialite);
      }
      break;

    case 2:
      printf("Entrez votre position (x y) : ");
      scanf("%lf %lf", &x, &y);
      printf(
          "Entrez les spécialités recherchées (séparées par des virgules) : ");
      char specialitesStr[STR_MAX_LENGTH];
      // fgets(specialitesStr, sizeof(specialitesStr), stdin);
      scanf("%s", specialitesStr);
      /*char *spe = strtok(specialitesStr, ",");
      nbSpecialites = 0;
      while (spe != NULL && nbSpecialites < MAX_SPECIALITES) {
        strcpy(specialites[nbSpecialites], spe);
        spe = strtok(NULL, ",");
        nbSpecialites++;
      }*/
      Restaurant resultatsSpecialite[RESTAURANTS_NBR];
      cherche_par_specialite(x, y, specialites, nbSpecialites, restaurants,
                             resultatsSpecialite);
      printf("Résultats de la recherche :\n");
      for (int i = 0; i < RESTAURANTS_NBR &&
                      resultatsSpecialite[i].nom_restaurant[0] != '\0';
           i++) {
        printf("%s, %s, (%f, %f), %s\n", resultatsSpecialite[i].nom_restaurant,
               resultatsSpecialite[i].adresse_restaurant,
               resultatsSpecialite[i].position_restaurant[0],
               resultatsSpecialite[i].position_restaurant[1],
               resultatsSpecialite[i].specialite);
      }
      break;

    case 3:
      // Restaurant nouveauRestaurant;
      printf("Entrez le nom du restaurant : ");
      // fgets(nouveauRestaurant.nom_restaurant,sizeof(nouveauRestaurant.nom_restaurant),
      // stdin);
      scanf("%s", nouveauRestaurant.nom_restaurant);
      printf("Entrez l'adresse du restaurant : ");
      // fgets(nouveauRestaurant.adresse_restaurant,sizeof(nouveauRestaurant.adresse_restaurant),stdin);
      scanf("%s", nouveauRestaurant.adresse_restaurant);
      printf("Entrez la position du restaurant (x y) : ");
      scanf("%lf %lf", &nouveauRestaurant.position_restaurant[0],
            &nouveauRestaurant.position_restaurant[1]);
      printf("Entrez les spécialités du restaurant : ");
      // fgets(nouveauRestaurant.specialite,
      // sizeof(nouveauRestaurant.specialite),stdin);
      scanf("%s", nouveauRestaurant.specialite);
      inserer_restaurant(nouveauRestaurant);
      break;

    case 4:
      if (nbRestaurants >= 0) {
        printf("Le nombre de restaurants égale à : %d\n", nbRestaurants);
      } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
      }
      break;

    case 5:
      printf("Au revoir !\n");
      break;

    default:
      printf("Choix invalide. Veuillez réessayer.\n");
    }
  } while (choix != 5);

  return 0;
}