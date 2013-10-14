/*
  INF3105 -- Structures de données et algorithmes
  UQAM / Département d'informatique
  Automne 2013 / TP1
*/

#if !defined(_IMMEUBLE_H_)
#define _IMMEUBLE_H_

#include <iostream>
#include <string>
#include "point.h"
using namespace std;

class Immeuble {
  public:
    Immeuble(string nom="", Point emp=Point(0.0,0.0),
double h=0.0, int nc=0.0);
/** calculer la dsistance entre l'immeuble courrant et un autre
(utile pour évaluer l'interférence*/
double distanceEntre(const Immeuble& im)const;
int ajouterDesClients(int nombreAAjouter) const;

/** Nécessaire pour comparer facilement la hauteur*/
bool operator < (const Immeuble im) const;

  private:
    string nom;
    Point emplacement;
    double hauteur;
    int nbClientPresents;
    //Utile pour partager les infos d'une stationet cet immeuble
    friend class Station;


  friend std::istream& operator >> (std::istream&, Immeuble&);
  friend std::ostream& operator << (std::ostream&, const Immeuble&);

};

#endif

