/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
  Hiver 2014
  Squelette de départ pour le TP2.
*/

#if !defined(__DATE__H__)
#define __DATE__H__

#include <iostream>

// À compléter.
class Date{
  public:
    Date();
    Date(int j,int h,int m,int s);

    bool operator <(const Date& date) const;

  private:
    int jours;
    int heures;
    int minutes;
    int secondes;
    int convertirEnSecondes(const Date& dt)const;


  friend std::ostream& operator << (std::ostream&, const Date& date);
  friend std::istream& operator >> (std::istream&, Date& date);
};

class Intervalle{
  private:
    Date debut;
    Date fin;
  public:
    Intervalle(){}

    // Il est parfois requis de briser l'abstraction
    Date getDebut() const { return debut; }
    Date getFin() const { return fin; }

    friend std::ostream& operator << (std::ostream&, const Intervalle&);
    friend std::istream& operator >> (std::istream&, Intervalle&);
};


#endif

