# Makefile pour TP2

OPTIONS = -Wall
# Choisir l'une des deux configurations (-g: Debug | -O3: Release)
#OPTIONS = -g -O0 -Wall
OPTIONS = -O2 -Wall

# Syntaxe : cible : dépendance1 dépendance2 ...
# Ensuite, la ou les ligne(s) débutant par une tabulation (\t) donne les commandes pour construire une cible

all : tp2 testdate

tp2: tp2.o historique.o date.o
	g++ $(OPTIONS) -o tp2 date.o historique.o tp2.o

tp2.o: tp2.cpp
	g++ $(OPTIONS) -c -o tp2.o tp2.cpp

date.o: date.h date.cpp
	g++ $(OPTIONS) -c -o date.o date.cpp

historique.o: historique.h historique.cpp
	g++ $(OPTIONS) -c -o historique.o historique.cpp

testdate : testdate.cpp date.o
	g++ $(OPTIONS) -o testdate testdate.cpp date.o

clean :
	rm -f *.o
	rm -f tp2 testdate
	rm -f *~

