#Définitions et redéfinitions (des macros)

OBJS = main.o exercice3.o

CC = gcc

#Construction de l'exécutable

edit : $(OBJS)
	   $(CC) -o $@ (OBJS)


#Dépendances
main.o : exercice3.h
exercice3.o : exercice3.h

clean :
		rm edit *.o 