/*
  INF3105 -- Structures de données et algorithmes
  UQAM / Département d'informatique
  Automne 2013 / TP1
*/

#include "immeuble.h"

istream& operator >> (istream& is, Immeuble& im){
    is >> im.nom;
    // À compléter.
    
    return is;
}

