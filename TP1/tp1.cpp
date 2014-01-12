/* tp1.cpp
 * Par Laurent Morissette
 * MORL05058301
 * Dernière modification: 13 octobre 2013
 *
 * Ce programme lit un fichier contenant une liste de stations
 * et d'immeubles. Il calcule ensuite la position optimale des
 * stations sur les immeubles afin de couvrir le maximum de clients.
 *
 * La technique bruteforce est utilisée afin d'essayer toute les solutions possibles pour la problématique
 * avec des éléments de statistique combinatoires pour les générer.
 *
 * Les cas limites standards:
 * 1) S'il n'y a pas assez d'immeubles pour traiter t'ensemble des stations, les sperflues snt ignorées
 * 2) s'il n'y a pas  d'immeuble assez haut pour placer une station, elle est omise
 * 3) s'il n'y a pas de station à traiter, le programme termine.
 *
 * Notez que l'approche bruteforce n'est pas la seule envisageable au départ:
 * Je suis d'avis que l'approche par arbre minMax aurait pu être également considérée 
 * afin de fournir la couverture maximale 
 *
 */

#include <iostream>
#include <fstream>
#include "immeuble.h"
#include "station.h"
#include "tableau.h"
#include <limits>
#include <stdlib.h>

using namespace std;


struct Solution {
    Tableau<Immeuble> lesPlusHautImmeubles,       //Immeubles assez haut pour au moins une station
                      lesImmeubles;    //Tous les immeubles
    Tableau<Station>  lesStations;     //Toutes les stations
    int nbMaxClientPourSolution,                      //Nombre max de clients pour une solution
        nbMaxClientPourImmeubles,
        tailleMin,
        tailleMax;
    Tableau<int> positionsOptimale,
                 positionsCourante;
    bool pasAssezImm;
};


void produireCombinaisons(struct Solution &sol, int offset, int fin);

void produirePermutations(struct Solution &sol, int debut, int fin);


void verifierNombreDeClientsCouvertsParStation(struct Solution &sol);


void permuterDeuxElementsPourSolution(struct Solution &sol, int a, int b);


void afficherResultat(struct Solution &sol);


bool immeubleCouvertParUneStationDansSolution(struct Solution& sol, int i, int j);

int main(int argc, const char** argv) {

    // Pointeur vers l'entrée désirée (cin ou ifstream)
    istream* entree;
    // Pointeur vers un flux de lecture.
    ifstream* entree_fichier = NULL;

    // Sélection du flux de lecture
    if(argc>1){
         entree = entree_fichier = new ifstream(argv[1]);
         if(entree->fail())
             cerr << "Erreur d'ouverture du fichier '" << argv[1] << "'" << endl;
    }else
         entree = &cin;

    Station stationLaMoinsHaute("a",numeric_limits<double>::max());

    Immeuble immLePlusHaut;
    struct Solution sol;
    sol.nbMaxClientPourSolution = -1;
    sol.nbMaxClientPourImmeubles = 0;
    // Lecture. Les opérateurs >> pour Immeuble et Station sont à compléter.

    int nbstations;
    (*entree) >> nbstations;
    for(int i=0;i<nbstations;i++){
        Station s;
        (*entree) >> s;
        sol.lesStations.ajouter(s);
        if(sol.lesStations[i] < stationLaMoinsHaute) {
            stationLaMoinsHaute = sol.lesStations[i];
        }
    }

    while(*entree)
    {
        Immeuble immeuble;
        *entree >> immeuble;
        if(!(*entree)) break;
        sol.lesImmeubles.ajouter(immeuble);
        sol.nbMaxClientPourImmeubles = immeuble.ajouterDesClients(sol.nbMaxClientPourImmeubles);
        if(stationLaMoinsHaute.peutEtreInstalleeSur(immeuble)) {
            sol.lesPlusHautImmeubles.ajouter(immeuble);
            if(immLePlusHaut < immeuble) {
                immLePlusHaut = immeuble;
            }
        }
    }

    delete entree_fichier; // delete est sécuritaire même si entree_fichier==NULL

    // Lecture terminée.


    int i = 0, nbStationAConsiderer = sol.lesStations.taille();
    while(i < nbStationAConsiderer) {
        if(!sol.lesStations[i].peutEtreInstalleeSur(immLePlusHaut)) {
            cerr << "Grave: " << sol.lesStations[i];
            cerr << " trop haute pour tous les immeubles" << endl;
            cerr << "La station est enlevée du tableau." << endl;
            sol.lesStations.enlever(i);
            nbStationAConsiderer--;
        } else {
            i++;
        }
    }

    assert(sol.lesStations.taille() >= 1 && "Aucune station");
    assert(sol.lesPlusHautImmeubles.taille() > 0);


    if(sol.lesPlusHautImmeubles.taille() < sol.lesStations.taille()) {
        cerr << "Avertissement: plus de stations que ";
        cerr << "d'immeubles pouvant les accueillir." << endl;
        cerr << "Certaines stations ne seront pas utilisées dans ";
        cerr << "la solution trouvée." << endl;
        sol.pasAssezImm = true;
        sol.tailleMin = sol.lesPlusHautImmeubles.taille();
        sol.tailleMax = sol.lesStations.taille();
    } else {
        sol.pasAssezImm = false;
        sol.tailleMin = sol.lesStations.taille();
        sol.tailleMax = sol.lesPlusHautImmeubles.taille();
    }

    produireCombinaisons(sol, 0, sol.tailleMin);
    afficherResultat(sol);

    return 0;
}

void produireCombinaisons(struct Solution &sol, int debut, int fin) {

    if(sol.nbMaxClientPourImmeubles == sol.nbMaxClientPourSolution)
        return;     //Tous les clients couverts
    if (fin == 0) {
        produirePermutations(sol, 0, sol.tailleMin);
        return;
    }
    for (int i = debut; i <= sol.tailleMax - fin; ++i) {
        sol.positionsCourante.ajouter(i);
        produireCombinaisons(sol, i+1, fin -1);
        sol.positionsCourante.enlever(sol.positionsCourante.taille()-1);
    }
}

void permuterDeuxElementsPourSolution(struct Solution &sol, int a, int b) {
    if(a!=b) {
        int temp = sol.positionsCourante[a];
        sol.positionsCourante[a] = sol.positionsCourante[b];
        sol.positionsCourante[b] = temp;
    }
}

void verifierNombreDeClientsCouvertsParStation(struct Solution &sol) {



    for(int i = 0; i < sol.positionsCourante.taille(); i++) {
        if(!sol.lesStations[(sol.pasAssezImm?sol.positionsCourante[i]:i)].peutEtreInstalleeSur
            (sol.lesPlusHautImmeubles[(sol.pasAssezImm?i:sol.positionsCourante[i])])) {
            return;
        }
    }

    int total = 0;
    for(int i = 0; i < sol.lesImmeubles.taille(); i++) {
        for(int j = 0; j < sol.positionsCourante.taille(); j++) {
            if(immeubleCouvertParUneStationDansSolution(sol, i, j)) {
                total = sol.lesImmeubles[i].ajouterDesClients(total);
                break;
            }
        }
    }

    if(total > sol.nbMaxClientPourSolution) {
        sol.nbMaxClientPourSolution = total;
        sol.positionsOptimale = sol.positionsCourante;

    }
}

void produirePermutations(struct Solution &sol, int debut, int fin) {

    if(sol.nbMaxClientPourImmeubles == sol.nbMaxClientPourSolution)
        return;     //On couvre tous les clients: deja optimale.
    if(debut == fin) {
        verifierNombreDeClientsCouvertsParStation(sol);
    } else {
        for(int i = debut; i < fin; i++) {
            permuterDeuxElementsPourSolution(sol, debut, i);
            produirePermutations(sol, debut + 1, fin);
            permuterDeuxElementsPourSolution(sol, i, debut);
        }
    }
}

void afficherResultat(struct Solution& sol) {
    for(int i = 0; i < sol.positionsOptimale.taille(); i++) {
        cout << sol.lesStations[(sol.pasAssezImm?sol.positionsOptimale[i]:i)];
        cout << " " << sol.lesPlusHautImmeubles[(sol.pasAssezImm?i:sol.positionsOptimale[i])] << endl;
    }
    cout << sol.nbMaxClientPourSolution << endl;
}

bool immeubleCouvertParUneStationDansSolution(struct Solution& sol, int i, int j) {
    return sol.lesStations[(sol.pasAssezImm?sol.positionsCourante[j]:j)].estCompriseEntre
        (sol.lesImmeubles[i], sol.lesPlusHautImmeubles[(sol.pasAssezImm?j:sol.positionsCourante[j])]);
}
