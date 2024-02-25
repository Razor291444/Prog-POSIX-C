#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"

//question1
//1
int lecture_points(float Points[N])
{
  int i=0;
  printf("entrer les Notes des etudiants au devoir de SR01  NB: Note entre [0 60]\n");
  for (i= 0; i < N; i++) {
    scanf("%4.2f",&Points[i]);
  }
  return 0;
}

//question2
//2
int afficher_note_max(float Points[N])
{
  float NoteMax = 0;
  int i = 0;
  for(i=0; i<N; i++)
  {
    if(Points[i] > NoteMax) NoteMax = Points[i];
  }
  printf("La note maximale du devoir de SR01 est %f\n",NoteMax);
  return 0;
}

//3
int afficher_note_min(float Points[N])
{
  float NoteMin = 60;
  int i = 0;
  for(i=0; i<N; i++)
  {
    if(Points[i] < NoteMin) NoteMin = Points[i];
  }
  printf("La note minimale du devoir de SR01 est %f\n",NoteMin);
  return 0;
}

//4
int moyenne_notes(float Points[N])
{
  float SommeNotes = 0;
  int i = 0;
  for(i=0; i<N; i++)
  {
    SommeNotes += Points[i];
  }
  printf("La moyenne des notes du devoir de SR01 est %f\n",SommeNotes/N);
  return 0;
}

//5
//question3
int remplir_tableau_notes(float Points[N],int Notes[7])
{
  int i=0;
    //on va faire un controle sur la valeur de Points[i] pour savoir dans quelle intervale se situé avant
    //d'incrémenté Notes[i]
    for(i=0; i<N; i++)
    {
      if(Points[i] == 60) Notes[6]++;
      if(Points[i]>=50 && Points[i]<=59) Notes[5]++;
      if(Points[i]>=40 && Points[i]<=49) Notes[4]++;
      if(Points[i]>=30 && Points[i]<=39) Notes[3]++;
      if(Points[i]>=20 && Points[i]<=29) Notes[2]++;
      if(Points[i]>=10 && Points[i]<=19) Notes[1]++;
      if(Points[i]>=0 && Points[i]<=9) Notes[0]++;
    }
    return 0;
}

//6
//question4
int affiche_notes_rond(int Notes[7])
{
  int MaxN = 0;
  int position=0;// pour garder la position dela dernière case de valeur Notes[i]
  int i=0;
  int j=0;
  int k=0;
  //int Notes[7]={7,8,4,9,7,0,7};

  //je recherche le nombre max d'etudiant ayant eu une note dans un intervale
   for(i=0; i<7;i++) if(Notes[i] > MaxN) MaxN = Notes[i];

  printf("\n");

  for(i=0; i<MaxN; i++) {

       printf("\n %d >",MaxN-i);

       for(j=0; j<7; j++){

          if(Notes[j] == MaxN-i) {

              if(MaxN-i){
 //on affiche les rond en tenant compte du fait que il pourrais avoir des identiques
                  if(Notes[j]==Notes[position]){

                      //printf("\t");
                      for(k=0;k<(6*(j-position) + 3); k++)  printf(" ");

                     } else

                          for(k=0;k<(6*j + 3); k++)  printf(" ");

                printf("o");

            }
            position = j;

          }

       }

        printf("\n");
    }

    printf("\n    ");
    //on affiche l'abscisse
    for(j=0; j<7;j++){
          printf("+---");
          if(Notes[j]==0) {
              printf("o--");
          }else
          printf("---");
       }
       printf("+ \n    ");

     //on affiche les intervalles
     printf("| 0-9  | 10-19| 20-29| 30-39| 40-49| 50-59|  60  |");
    return 0;
}

//7
//question5

int affiche_notes_baton(int Notes[7])
{
  int MaxN = 0;
  int position=0;// pour garder la position dela dernière case de valeur Notes[i]
  int i=0;
  int j=0;
  int k=0;
//  int Notes[7]={7,8,4,9,7,0,7};

  //je recherche le nombre max d'etudiant ayant eu une note dans un intervale
   for(i=0; i<7;i++) if(Notes[i] > MaxN) MaxN = Notes[i];

  printf("\n");

  for(i=0; i<MaxN; i++) {

       printf("\n %d >",MaxN-i);

       for(j=0; j<7; j++){

          if(Notes[j] == MaxN-i) {

              if(MaxN-i){
 //on affiche les rond en tenant compte du fait que il pourrais avoir des identiques
                  if(Notes[j]==Notes[position]){

                     // printf("  ");
                      for(k=0;k<(6*(j-position)); k++)  printf(" ");

                     } else

                          for(k=0;k<(6*j); k++)  printf(" ");

                printf(" ##### ");

            }
            position = j;

          }

       }

        printf("\n");
    }

    printf("\n    ");
    //on affiche l'abscisse
    for(j=0; j<7;j++){
          printf("+---");
          if(Notes[j]==0) {
              printf("o--");
          }else
          printf("---");
       }
       printf("+ \n    ");

     //on affiche les intervalles
     printf("| 0-9  | 10-19| 20-29| 30-39| 40-49| 50-59|  60  |");
    return 0;
}
