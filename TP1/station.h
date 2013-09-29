/*
  INF3105 -- Structures de données et algorithmes
  UQAM / Département d'informatique
  Automne 2013 / TP1
*/

#if !defined(_STATION_H_)
#define _STATION_H_

#include <iostream>
#include <string>

using namespace std;

class Station {
  public:
    // À compléter.

  private:
    // À compléter.
    string nom;


  friend std::istream& operator >> (std::istream&, Station&);
  friend std::ostream& operator << (std::ostream&, const Station&);
};

#endif

