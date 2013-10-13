/*
  INF3105 -- Structures de données et algorithmes
  UQAM / Département d'informatique
  Automne 2013 / TP1
*/

#if !defined(_STATION_H_)
#define _STATION_H_

#include <iostream>
#include <string>
#include "immeuble.h"
using namespace std;

class Station {
  public:
    Station(const string nom="",const double ht=0.0,const double r=0.0);
    /* Pour être installable sur un immeuble, celui-ci
   doit être de la hauteur minimale de la station
   */
    bool peutEtreInstalleeSur(const Immeuble& im) const;
    /** utile pour évaluer l'interférence*/
    bool estCompriseEntre(const Immeuble& im1,const Immeuble& im2) const;
    bool operator <(const Station& s)const;

  private:
    string nom;
    double hauteur;
    double rayon;



  friend std::istream& operator >> (std::istream&, Station&);
  friend std::ostream& operator << (std::ostream&, const Station&);
};

#endif

