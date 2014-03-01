/*
  INF3105 - Structures de données et algorithmes
  Squelette pour Lab8 + TP2
*/


#if !defined(__ARBRE_MAP_H__)
#define __ARBRE_MAP_H__

#include "arbreavl.h"

template <class K, class V>
class ArbreMap
{
  private:
    // À compléter : voir la Section 8.11 (Arbres associatifs (Mapping Trees)) des notes de cours.


    //ArbreAVL<Entree> entrees;

  public:
    bool contient(const K&) const;

    void enlever(const K&);
    void vider();
    bool vide() const;

    const V& operator[] (const K&) const;
    V& operator[] (const K&);
};



template <class K, class V>
void ArbreMap<K,V>::vider(){
    // À compléter
}

template <class K, class V>
bool ArbreMap<K,V>::vide() const{
    // À compléter
    // return entrees.vide();
    return true;
}

template <class K, class V>
void ArbreMap<K,V>::enlever(const K& c)
{
    // À compléter
}

template <class K, class V>
bool ArbreMap<K,V>::contient(const K& c) const
{
    // À compléter
    return false;
}

template <class K, class V>
const V& ArbreMap<K,V>::operator[] (const K& c)  const
{
    // À compléter
}

template <class K, class V>
V& ArbreMap<K,V>::operator[] (const K& c) 
{
    // À compléter
}


#endif

