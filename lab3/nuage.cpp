/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
  
  Squelette pour le Lab3.
*/

#include "nuage.h"


/* Retourne une référence sur point le plus proche de p dans le nuage */
const Point& Nuage::proche(const Point& p) const
{
    //TODO
    return p;
}

/* Retourne un sous-nuage à l'intérieur d'un rayon autour de p */
Nuage Nuage::proches(const Point& p, double rayon) const
{
    //TODO
    return Nuage();
}

/* Retourne le sous-nuage contenant les n points les plus près de p */
Nuage Nuage::nproches(const Point& p, int n) const
{
    //TODO
    return Nuage();
}


// Écriture d'un nuage
std::ostream& operator << (std::ostream& os, const Nuage& nuage){
  for(int i=0;i<nuage.points.taille();i++)
    os << nuage.points[i] << std::endl;
  return os;
}

// Lecture d'un nuage
std::istream& operator >> (std::istream& is, Nuage& nuage){
  nuage.points.vider();
  while(is){
    Point p;
    is >> p >> std::ws;
    if(is) // permet de détecter la fin du fichier
      nuage.points.ajouter(p);
  }
  return is;
}

