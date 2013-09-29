/*
  INF3105 -- Structures de données et algorithmes
  UQAM / Département d'informatique
  Automne 2013 / TP1
*/

#include "station.h"

istream& operator >> (istream& is, Station& s){
    is >> s.nom;
    // À compléter.
    
    return is;
}

