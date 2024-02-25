#include "exercice3.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// On récupère dans le tableau de restaurant toutes les informations concernant
// chaque restaurant.
void setPosition(char position[], Restaurant *restau) {
  char str[STR_MAX_LENGTH];
  for (int i = 0; i < 2; i++) {
    int gap = 3 + i * (strlen(str) + 4);
    int j = gap;
    memset(&str, 0, STR_MAX_LENGTH);
    printf("%i, %c\n", j, position[j]);
    while (j < STR_MAX_LENGTH && position[j] != ',' && position[j] != ')') {
      str[j - gap] = position[j];
      j++;
    }
    restau->position_restaurant[i] = atoi(str);
  }
}

// Fonction pour lire les restaurants depuis le fichier
int lire_restaurant(char *chemin, Restaurant restaurants[]) {
  FILE *file = fopen("restau.txt", "r");
  if (file == NULL) {
    printf("Error opening file %s\n", chemin);
    return -1; // Return -1 to indicate an error
  }

  char line[STR_MAX_LENGTH];
  int restaurantCount = 0;

  while (fgets(line, sizeof(line), file) != NULL &&
         restaurantCount < RESTAURANTS_NBR) {
    // Skip the header line or lines not following the expected format
    if (strstr(line, "Restaurant; adresse; coordonee; specialite") != NULL) {
      continue;
    }

    char *token = strtok(line, ";");
    if (token != NULL) {
      strcpy(restaurants[restaurantCount].nom_restaurant, token);

      token = strtok(NULL, ";");
      if (token != NULL) {
        strcpy(restaurants[restaurantCount].adresse_restaurant, token);

        token = strtok(NULL, ";");
        if (token != NULL) {
          // Extracting x and y coordinates
          sscanf(token, "(x=%lf, y=%lf)",
                 &restaurants[restaurantCount].position_restaurant[0],
                 &restaurants[restaurantCount].position_restaurant[1]);

          token = strtok(NULL, ";");
          if (token != NULL) {
            // Removing the leading '{' and trailing '}' from specialite
            memmove(token, token + 1, strlen(token));
            token[strlen(token) - 2] = '\0';
            strcpy(restaurants[restaurantCount].specialite, token);

            restaurantCount++;
          }
        }
      }
    }
  }
  fclose(file);
  return restaurantCount;
}

// Fonction pour insérer un restaurant à la fin du fichier
void inserer_restaurant(Restaurant restaurant) {
  FILE *fichier = fopen("restau.txt", "r+");
  if (fichier == NULL) {
    printf("Erreur lors de l'ouverture du fichier.\n");
    return;
  }
  fseek(fichier, 0, SEEK_END);
  fprintf(fichier, "\n%s; %s; (x=%f, y=%f); {%s}", restaurant.nom_restaurant,
          restaurant.adresse_restaurant, restaurant.position_restaurant[0],
          restaurant.position_restaurant[1], restaurant.specialite);

  fclose(fichier);
}

// Fonction pour calculer la distance entre deux points (utilisée pour trier
// les résultats)
double distance(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

// Fonction pour chercher les restaurants dans un rayon de recherche
void recherche_restaurant(double x, double y, double rayon_recherche,
                          const Restaurant restaurants[],
                          Restaurant results[]) {
  int resultsIndice = 0;
  for (int i = 0; i < RESTAURANTS_NBR; i++) {
    double distance_restaurant =
        distance(x, y, restaurants[i].position_restaurant[0],
                 restaurants[i].position_restaurant[1]);
    if (distance_restaurant <= rayon_recherche) {
      results[resultsIndice] = restaurants[i];
      resultsIndice++;
    }
  }
}

// Fonction pour chercher les restaurants par spécialité
void cherche_par_specialite(double x, double y,
                            char specialite[][STR_MAX_LENGTH],
                            int nbr_specialite, Restaurant restaurants[],
                            Restaurant results[]) {
  int resultsIndice = 0;

  for (int i = 0; i < RESTAURANTS_NBR; i++) {
    for (int j = 0; j < nbr_specialite; j++) {
      if (strcmp(restaurants[i].specialite, specialite[j])) {
        results[resultsIndice] = restaurants[i];
        resultsIndice++;
        break;
      }
    }
  }

  for (int i = 0; i < resultsIndice; i++) {
    for (int j = i + 1; resultsIndice; j++) {
      int x_1 = results[i].position_restaurant[0];
      int y_1 = results[i].position_restaurant[1];
      int x_2 = results[j].position_restaurant[0];
      int y_2 = results[j].position_restaurant[1];
      if (distance(x, y, x_1, y_1) > distance(x, y, x_2, y_2)) {
        Restaurant temp = results[i];
        results[i] = results[j];
        results[j] = temp;
      }
    }
  }
}