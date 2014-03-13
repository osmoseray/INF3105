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
#include "arbreavl.h"

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

int main(int argc, const char** args) {

    ArbreAVL<int> arbre;

    cout << "vide = " << arbre.rechercher(25) << endl;
        cout << "vide2 = " << arbre.rechercherEgalOuPrecedent(25) << endl;
            cout << "vide3 = " << arbre.rechercherEgalOuSuivant(25) << endl;

    arbre.inserer(29);
    arbre.inserer(7);
    arbre.inserer(4);
    arbre.inserer(2);
    arbre.inserer(18);
    arbre.inserer(11);
    arbre.inserer(20);
    arbre.inserer(15);
    arbre.inserer(69);
    arbre.inserer(46);
    arbre.inserer(37);
    arbre.inserer(53);
    arbre.inserer(80);
    arbre.inserer(74);
    arbre.inserer(86);
    arbre.inserer(75);

    cout << "Hauteur de l'arbre = " << arbre.hauteur() << endl;

   /* if(argc>1){
         std::ifstream entree(args[1]);
         if(entree.fail())
             std::cerr << "Erreur d'ouverture du fichier '" << args[1] << "'" << std::endl;
         else
             tp2(entree);
    }else
         tp2(std::cin); */

    return 0;
}

