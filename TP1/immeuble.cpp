/*
  INF3105 -- Structures de données et algorithmes
  UQAM / Département d'informatique
  Automne 2013 / TP1
*/

#include "immeuble.h"
using namespace std;

	Immeuble::Immeuble(string n, Point emp, double h, int clis) 
		:nom(n), emplacement(emp), hauteur(h), nbClientPresents(clis)
	{
	}

	double distanceEntre(const Immeuble& im)const{
	 return emplacement.distance(im.emplacement);
	}
	int aujouterDesClients(int nombreAAjouter) const{
		return nbClientPresents+nombreAAjouter;
	}
	
	/** Nécessaire pour comparer facilement la hauteur*/
	bool operator < (const Immeuble im) const{
	 return hauteur < im.hauteur;
	}


ostream& operator << (ostream& os, Immeuble& im){
    os >> im.nom;
	
    
    return is;
}

istream& operator >> (istream& is, Immeuble& im){
    is >> im.nom;
	is >> im.emplacement
	is >> im.hauteur;
	is >> im.nbClientPresents
   
    
    return is;
}

