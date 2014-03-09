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
    ArbreAVL<int> arbre2;

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

    arbre2 = arbre;

    cout << "trouver 1 " << arbre2.contient(1) << endl;
    cout << "trouver 29 " << arbre2.contient(29) << endl;
    cout << "trouver 7 " << arbre2.contient(7) << endl;
    cout << "trouver 4 " << arbre2.contient(4) << endl;
    cout << "trouver 2 " << arbre2.contient(2) << endl;
    cout << "trouver 18 " << arbre2.contient(18) << endl;
    cout << "trouver 11 " << arbre2.contient(11) << endl;
    cout << "trouver 20 " << arbre2.contient(20) << endl;
    cout << "trouver 15 " << arbre2.contient(15) << endl;
    cout << "trouver 69 " << arbre2.contient(69) << endl;
    cout << "trouver 46 " << arbre2.contient(46) << endl;
    cout << "trouver 37 " << arbre2.contient(37) << endl;
    cout << "trouver 53 " << arbre2.contient(53) << endl;
    cout << "trouver 80 " << arbre2.contient(80) << endl;
    cout << "trouver 74 " << arbre2.contient(74) << endl;
    cout << "trouver 86 " << arbre2.contient(86) << endl;
    cout << "trouver 75 " << arbre2.contient(75) << endl;
    cout << "trouver 90 " << arbre2.contient(90) << endl;

    /*arbre.vider();*/

    /*cout << "trouver 1 " << arbre.contient(1) << endl;
    cout << "trouver 29 " << arbre.contient(29) << endl;
    cout << "trouver 7 " << arbre.contient(7) << endl;
    cout << "trouver 4 " << arbre.contient(4) << endl;
    cout << "trouver 2 " << arbre.contient(2) << endl;
    cout << "trouver 18 " << arbre.contient(18) << endl;
    cout << "trouver 11 " << arbre.contient(11) << endl;
    cout << "trouver 20 " << arbre.contient(20) << endl;
    cout << "trouver 15 " << arbre.contient(15) << endl;
    cout << "trouver 69 " << arbre.contient(69) << endl;
    cout << "trouver 46 " << arbre.contient(46) << endl;
    cout << "trouver 37 " << arbre.contient(37) << endl;
    cout << "trouver 53 " << arbre.contient(53) << endl;
    cout << "trouver 80 " << arbre.contient(80) << endl;
    cout << "trouver 74 " << arbre.contient(74) << endl;
    cout << "trouver 86 " << arbre.contient(86) << endl;
    cout << "trouver 75 " << arbre.contient(75) << endl;
    cout << "trouver 90 " << arbre.contient(90) << endl;*/


    //arbre.rechercherEgalOuPrecedent(90);
    //arbre.rechercherEgalOuSuivant(90);


    //cout << "trouver 8 ? " << arbre.contient(8) << endl;
    //cout << "trouver 7 ? " << arbre.contient(7) << endl;
    //cout << "trouver 0 ? " << arbre.contient(0) << endl;

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

