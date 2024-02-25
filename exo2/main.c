#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"

int main()
{
  float Points[N];
  int Notes[7]={0,0,0,0,0,0,0};
  int choix = 0;

  do
    {
        printf("\n***************MENU*****************\n");
        printf("\n 1: Entrer les notes des etudiants au devoir de SR01\n 2: La note maximale du devoir SR01 \n 3: La note minimale du devoir SR01 \n 4: La moyenne des notes du devoir SR01 ");
        printf("\n 5: Graphique en nuage de points \n 6: Graphique en diagramme baton \n 0: quitter \n Votre choix : \n");
        scanf("%d",&choix);


        switch(choix)
        {
        case  1:
            lecture_points(Points);
            for(int i=0; i<N; i++)
                printf("\t %4.2f",Points[i]);
            break;
        case  2:
            afficher_note_max(Points);
            break;
        case  3:
            afficher_note_min(Points);
            break;
        case  4:
            moyenne_notes(Points);
            break;
        case  5:
            remplir_tableau_notes(Points, Notes);
            affiche_notes_rond(Notes);
            break;
        case  6:
            remplir_tableau_notes(Points, Notes);
            affiche_notes_baton(Notes);
            break;

        default:
            choix = 0;
            printf("vous allez sortir de l'APK");
            break;
        }
    }while(choix);
}
