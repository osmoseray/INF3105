/*
  INF3105 - Structures de données et algorithmes
  Eric Beaudry (beaudry.eric@uqam.ca)
  Hiver 2014 
  Squelette de départ pour le TP2.
*/

#if !defined(__HISTORIQUE__H__)
#define __HISTORIQUE__H__

#include <string>
#include "arbremap.h"
#include "date.h"

using namespace std;

/** Un objet Historique contient des traces et offre un interface publique
    pour ajouter des trace et exécuter des requêtes.
 */
class Historique{
  public:
   
    // Ajouter une trace
    void     trace(Date date, const string& lieu, const string& nompersonne);
    
    // Les 4 types de requête
    ArbreAVL<string> localiser(const Intervalle&, const string& nompersonne) const;
    ArbreAVL<string> presences(const Intervalle&, const string& nomlieu) const;
    ArbreAVL<string> frequentations(const Intervalle&, const string& nompersonne) const;
    int      duree_rencontres(const Intervalle&, const string& nompersonne1, const string& nompersonne2) const;
    
  private:
};

#endif
