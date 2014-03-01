/*
  INF3105 - Structures de données et algorithmes
  Eric Beaudry (beaudry.eric@uqam.ca)
  Hiver 2014 
  Squelette de départ pour le TP2.
*/

#include "historique.h"


void Historique::trace(Date date, const string& nomlieu, const string& nompersonne)
{
}

ArbreAVL<string> Historique::localiser(const Intervalle& intervalle, const string& nompersonne) const
{
    ArbreAVL<string> resultats;
    return resultats;
}

ArbreAVL<string> Historique::presences(const Intervalle& intervalle, const string& nomlieu) const
{
    ArbreAVL<string> resultats;
    return resultats;
}

ArbreAVL<string> Historique::frequentations(const Intervalle& intervalle, const string& nompersonne) const
{
    ArbreAVL<string> resultats;
    return resultats;
}

int Historique::duree_rencontres(const Intervalle& intervalle, const string& nompersonne1, const string& nompersonne2) const
{
    int duree = 0;
    return duree;
}

