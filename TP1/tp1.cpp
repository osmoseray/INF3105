#include <iostream>
#include <fstream>
#include "immeuble.h"
#include "station.h"
#include "tableau.h"

using namespace std;

int main(int argc, const char** argv)
{
    // Pointeur vers l'entrée désirée (cin ou ifstream)
    std::istream* entree;
    // Pointeur vers un flux de lecture.
    std::ifstream* entree_fichier = NULL;

    // Sélection du flux de lecture
    if(argc>1){
         entree = entree_fichier = new std::ifstream(argv[1]);
         if(entree->fail())
             std::cerr << "Erreur d'ouverture du fichier '" << argv[1] << "'" << std::endl;
    }else
         entree = &std::cin;

    Tableau<Station> stations;
    Tableau<Immeuble> immeubles;
    
    // Lecture. Les opérateurs >> pour Immeuble et Station sont à compléter.
    int nbstations;
    (*entree) >> nbstations;
    for(int i=0;i<nbstations;i++){
        Station s;
        (*entree) >> s;
        stations.ajouter(s);
    }
    
    while(*entree)
    {
        Immeuble immeuble;
        *entree >> immeuble;
        if(!(*entree)) break;
        immeubles.ajouter(immeuble);
    }
    delete entree_fichier; // delete est sécuritaire même si entree_fichier==NULL
    
    // Lecture terminée.


    // Pour commencer, supportez une seule station.
    // Ensuite, améliorez votre programme pour 2.
    // Ensuite, généralisez à 3+.
    if(stations.taille() != 1){
        cerr << "Cette version ne supporte que les problèmes avec exactement une seule station!" << endl;
        return 1;
    }
    Station& lastation = stations[0];
    
    
    // Mettez l'algorithme ici.
   
   
    // Affichez le résultat;


    return 0;
}
