/*
  INF3105 -- Structures de données et algorithmes
  UQAM / Département d'informatique
  Automne 2013 / TP1
*/

#include "station.h"

Station::Station(const string nom, const double ht, const double r) :
    nom(nom), hauteur(ht), rayon(r)
{
}
bool Station::peutEtreInstalleeSur(const Immeuble& im){
	return im.hauteur>=hauteur;
}

bool Station::estCompriseEntre(const Immeuble& im1,const Immeuble& im2){
	return im1.distance(im2)<=rayon;
}
bool Station::operator < (const Station& s){
	hauteur < s.hauteur;
}
istream& operator >> (istream& is, Station& s){
    is >> s.nom;
    is >> s.hauteur;
	is >> s.rayon;
    
    return is;
}
ostream& operator << (ostream& os, Station& s){
    os << s.nom;
    
    
    return os;
}

