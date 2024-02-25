# RAPPORT

# EXERCICE 1 
Il est question d'exécuter 6 programmes et donner une explication succincte du résultat obtenu.

#### Programme 1
Ce programme ne peut être exécuté, car il y a une erreur à la ligne 4 du programme :
? int C=!-- A /++! B; ?. L'association des opérateurs de cette manière-là ne permet pas de retourner un résultat.

#### Programme 2
A && B => 0 (Vrai en booléen)
!0 && (C++) && !(D++) => 1 ( C++=-10 différent de 0 et de 2)
Avec le OU de ces deux relations le premier printf renvoie 1.
Le deuxième printf renvoie les valeurs de C et D pas encore incrémentées d'où les valeurs -10 et 2 sont affichées.

#### Programme 3
Dans le premier printf, on a la valeur de ++ q* q ++ qui s?affiche qui est ici 4, car *++q = -2 multiplié par * q ++ = -2 donne 4.
Le deuxième printf affiche la valeur de *q qui est 3 parce que *(q++) est une opération de post-incrémentation.

#### Programme 4
*(q) & *(q++) => 1
*(q++) => -2
Or 1 OU -2 => 1 + (-2) => d = -1 (premier printf)
Le deuxième printf affiche le contenu du pointeur q qui est 3, car d implémente deux fois la position pointée par q.

#### Programme 5
On regarde si (++a) &&(--b) est vérifié ou non. Ici (++a) = -7 ET (--b) = 2 ce qui est vrai. Ainsi la condition  ?b - -? est réalisée. Donc c=2, car b - - est une opération post-incrémentation et b = 1.

#### Programme 6
Résultat obtenu : a = -4


# EXERCICE 2

# EXERCICE 3
L'objectif de cet exercice est de collecter un ensemble de données relatives à des restaurants et de les manipuler par la suite. Les informations concernant chaque restaurant sont stockées dans un fichier (restau.txt).

Le programme est constitué de 6 fonctions qui sont:

1. La fonction *int lire_restaurant (char* chemin, Restaurant restaurants [])*, qui récupère dans le tableau restaurants toutes les informations concernant chaque restaurant inséré dans le fichier nommé chemin. La fonction lire_restaurant retournera en fin de lecture le nombre de restaurants lu à partir du fichier.

2. La fonction *inserer_restaurant(Restaurant restaurant)* permettant d'insérer un restaurant à la fin du fichier (restau.txt).

3. La fonction *void cherche_restaurant(double x, double y, double rayon_recherche, Restaurant results[])* qui prend en paramètre la position actuelle d?un utilisateur et un rayon de recherche et qui remplit le tableau results par les restaurants présents dans le rayon de recherche.

4. La fonction *void cherche_par_specialite(double x, double y, char * specialite[], Restaurant results[])* qui prend en paramètre la position actuelle d?un utilisateur et une liste de spécialité et qui remplit le tableau results par les restaurants satisfaisants au moins une des spécialités passées en paramètre.
**Remarque** : pour la dernière question, les restaurants insérés dans le tableau results doivent être ordonnés du plus proche au plus loin par rapport à la position passée en paramètre.

5. La fonction outil *double distance(double x1, double y1, double x2, double y2)* permettant de calculer la distance entre deux points (utilisée pour trier les résultats).

6. La fonction *main()* permettant de proposer un menu à l'utilisateur permettant de faire appel aux différentes fonctions mentionnées ci-dessus.