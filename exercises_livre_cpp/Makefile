COMPILER=g++
OPTIONS= -W -Wall -O1
CHMOD=chmod 777

all:clean execute

execute:applyRights
	./Heure_1_A_1
	 clear
	./Heure_2_A_2
	 clear
	./Heure_3_A_2

applyRights:compile
	${CHMOD} Heure_1_A_1
	${CHMOD} Heure_2_A_2
	${CHMOD} Heure_3_A_2

compile:Heure_1_A_1 Heure_2_A_2 Heure_3_A_2

Heure_1_A_1:Heure_1_A_1.h Heure_1_A_1.cpp
	${COMPILER} ${OPTIONS} Heure_1_A_1.cpp -o Heure_1_A_1
	


Heure_2_A_2:Heure_2_A_2.h Heure_2_A_2.cpp
	${COMPILER} ${OPTIONS} Heure_2_A_2.cpp -o Heure_2_A_2
	

Heure_3_A_2:Heure_3_A_2.cpp
	${COMPILER} ${OPTIONS} Heure_3_A_2.cpp -o Heure_3_A_2
	



clean:
	rm -rf *.o
