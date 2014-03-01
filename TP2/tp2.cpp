/*
  INF3105 - Structures de données et algorithmes
  Eric Beaudry (beaudry.eric@uqam.ca)
  Hiver 2014 
  Squelette de départ pour le TP2.
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include "historique.h"

void tp2(std::istream& entree){   
    Historique historique;
    std::string nompersonne, nomlieu, nompersonne2;
    Date instant;
    Intervalle intervalle;
    while(entree){
         std::string cmd;
         char pv=0;
         entree >> cmd;
         if(!entree) break;
         
         if(cmd=="trace"){
             entree >> instant >> nomlieu >> nompersonne >> pv;
             historique.trace(instant, nomlieu, nompersonne);
             std::cout << "OK" << std::endl; 
         }
         else if(cmd=="localiser"){
             entree >> intervalle >> nompersonne >> pv;
             ArbreAVL<std::string> lieux = historique.localiser(intervalle, nompersonne);
             for(ArbreAVL<std::string>::Iterateur iter=lieux.debut();iter;++iter)
                 std::cout << *iter << " ";
             std::cout << std::endl;
         }
         else if(cmd=="presences"){
             entree >> intervalle >> nomlieu >> pv;
             ArbreAVL<std::string> personnes = historique.presences(intervalle, nomlieu);
             for(ArbreAVL<std::string>::Iterateur iter=personnes.debut();iter;++iter)
                 std::cout << *iter << " ";
             std::cout << std::endl;
         }
         else if(cmd=="frequentations"){
             entree >> intervalle >> nompersonne >> pv;
             ArbreAVL<std::string> personnes = historique.frequentations(intervalle, nompersonne);
             for(ArbreAVL<std::string>::Iterateur iter=personnes.debut();iter;++iter)
                 std::cout << *iter << " ";
             std::cout << std::endl;
         }
         else if(cmd=="duree_rencontres"){
             entree >> intervalle >> nompersonne >> nompersonne2 >> pv;
             int dr = historique.duree_rencontres(intervalle, nompersonne, nompersonne2);
             std::cout << dr << std::endl;
         }
         assert(pv==';');
    }
}

int main(int argc, const char** args)
{
    if(argc>1){
         std::ifstream entree(args[1]);
         if(entree.fail())
             std::cerr << "Erreur d'ouverture du fichier '" << args[1] << "'" << std::endl;
         else
             tp2(entree);
    }else
         tp2(std::cin);
    return 0;
}

