/*
  INF3105 -- Structures de données et algorithmes
  UQAM / Département d'informatique
  Automne 2013 / TP1
*/

#if !defined(_IMMEUBLE_H_)
#define _IMMEUBLE_H_

#include <iostream>
#include <string>

using namespace std;

class Immeuble {
  public:
    // À compléter.

  private:
    // À compléter.
    string nom;


  friend std::istream& operator >> (std::istream&, Immeuble&);
  friend std::ostream& operator << (std::ostream&, const Immeuble&);

};

#endif

