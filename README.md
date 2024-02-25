# RAPPORT

# EXERCICE 1 
Il est question d'ex�cuter 6 programmes et donner une explication succincte du r�sultat obtenu.

#### Programme 1
Ce programme ne peut �tre ex�cut�, car il y a une erreur � la ligne 4 du programme :
? int C=!-- A /++! B; ?. L'association des op�rateurs de cette mani�re-l� ne permet pas de retourner un r�sultat.

#### Programme 2
A && B => 0 (Vrai en bool�en)
!0 && (C++) && !(D++) => 1 ( C++=-10 diff�rent de 0 et de 2)
Avec le OU de ces deux relations le premier printf renvoie 1.
Le deuxi�me printf renvoie les valeurs de C et D pas encore incr�ment�es d'o� les valeurs -10 et 2 sont affich�es.

#### Programme 3
Dans le premier printf, on a la valeur de ++ q* q ++ qui s?affiche qui est ici 4, car *++q = -2 multipli� par * q ++ = -2 donne 4.
Le deuxi�me printf affiche la valeur de *q qui est 3 parce que *(q++) est une op�ration de post-incr�mentation.

#### Programme 4
*(q) & *(q++) => 1
*(q++) => -2
Or 1 OU -2 => 1 + (-2) => d = -1 (premier printf)
Le deuxi�me printf affiche le contenu du pointeur q qui est 3, car d impl�mente deux fois la position point�e par q.

#### Programme 5
On regarde si (++a) &&(--b) est v�rifi� ou non. Ici (++a) = -7 ET (--b) = 2 ce qui est vrai. Ainsi la condition  ?b - -? est r�alis�e. Donc c=2, car b - - est une op�ration post-incr�mentation et b = 1.

#### Programme 6
R�sultat obtenu : a = -4


# EXERCICE 2

# EXERCICE 3
L'objectif de cet exercice est de collecter un ensemble de donn�es relatives � des restaurants et de les manipuler par la suite. Les informations concernant chaque restaurant sont stock�es dans un fichier (restau.txt).

Le programme est constitu� de 6 fonctions qui sont:

1. La fonction *int lire_restaurant (char* chemin, Restaurant restaurants [])*, qui r�cup�re dans le tableau restaurants toutes les informations concernant chaque restaurant ins�r� dans le fichier nomm� chemin. La fonction lire_restaurant retournera en fin de lecture le nombre de restaurants lu � partir du fichier.

2. La fonction *inserer_restaurant(Restaurant restaurant)* permettant d'ins�rer un restaurant � la fin du fichier (restau.txt).

3. La fonction *void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[])* qui prend en param�tre la position actuelle d?un utilisateur et un rayon de recherche et qui remplit le tableau results par les restaurants pr�sents dans le rayon de recherche.

4. La fonction *void cherche_par_specialite(double x, double y, char * specialite[], Restaurant results[])* qui prend en param�tre la position actuelle d?un utilisateur et une liste de sp�cialit� et qui remplit le tableau results par les restaurants satisfaisants au moins une des sp�cialit�s pass�es en param�tre.
**Remarque** : pour la derni�re question, les restaurants ins�r�s dans le tableau results doivent �tre ordonn�s du plus proche au plus loin par rapport � la position pass�e en param�tre.

5. La fonction outil *double distance(double x1, double y1, double x2, double y2)* permettant de calculer la distance entre deux points (utilis�e pour trier les r�sultats).

6. La fonction *main()* permettant de proposer un menu � l'utilisateur permettant de faire appel aux diff�rentes fonctions mentionn�es ci-dessus.