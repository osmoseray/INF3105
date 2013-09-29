# INF3105 - Structures de données et algorithmes
# UQAM / Département d'informatique
#
# Fichier Makefile pour le Lab3.
# Il suffit de taper la commande make pour compiler.


#Options standard pour g++
OPTIONS = -Wall

#Option -g pour avoir les infos de débogage
#OPTIONS = -g -O0 -Wall
#Option -O2 pour le code optimisé
#OPTIONS = -O2 -Wall

# Les cibles à compiler
all : test_tableau lab3

# Syntaxe : cible : dépendance1 dépendance2 ...
# Ensuite, la ou les ligne(s) débutant par une tabulation (\t) donne les commandes pour construire une cible
test_tableau: test_tableau.cpp tableau.h
	g++ $(OPTIONS) -o test_tableau test_tableau.cpp

lab3: lab3.o point.o nuage.o
	g++ $(OPTIONS) -o lab3 lab3.o point.o nuage.o

lab3.o: lab3.cpp point.h nuage.h
	g++ $(OPTIONS) -c -o lab3.o lab3.cpp

point.o: point.cpp point.h
	g++ $(OPTIONS) -c -o point.o point.cpp

nuage.o: nuage.cpp nuage.h point.h
	g++ $(OPTIONS) -c -o nuage.o nuage.cpp

clean :
	rm -f *.o
	rm -f lab3
	rm -rf test_tableau

