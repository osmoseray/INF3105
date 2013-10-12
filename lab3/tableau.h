/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique

  Squelette pour classe générique Tableau<T> pour le Lab3 et TP1.
*/

// Ces deux lignes permettent d'éviter d'inclure 2 fois ce .h à la compilation.
#if !defined(__TABLEAU_H__)
 #define __TABLEAU_H__


template <class T>
class Tableau
{
  public:
    Tableau(int capacite_initiale=8);
    Tableau(const Tableau&);
    ~Tableau();

    // Ajouter un element à la fin
    void           ajouter(const T& element);
    // Vider le tableau
    void           vider();
    // Retourne le nombre d'éléments dans le tableau
    int            taille() const;

    // Insère element à position index. Les éléments à partir de index sont décalés d'une position au préalable.
    void           inserer(const T& element, int index=0);
    // Enlève l'element à position index. Les éléments après index sont décalés d'une position après.
    void           enlever(int index=0);
    // Cherche et retourne la position de l'élément. Si non trouvé, retourne -1.
    // Voir la méthode "trouver" dans les notes de cours. Il suffit de l'adapter pour retourner la position au lieu d'un booléen
    int            trouver(const T& element);

    T&             operator[] (int index);
    const T&       operator[] (int index) const;


    Tableau<T>&    operator = (const Tableau<T>& autre);

    bool           operator == (const Tableau<T>& autre) const;

  private:
    T*             elements;
    int            capacite;
    int            nbElements;
};


/*
 Puisque Tableau<T> est une classe générique, toutes ses définitions doivent être
 inclues après les déclarations. On peut quand même séparer les déclarations et
 les définitions en deux fichiers (tableau.h et tableau.hcc), à condition d'inclure le
 deuxième (tableau.hcc) à la fin du premier (tableau.h). Ainsi, un fichier source
 (.cc, .cpp, c++) qui inclut tableau.h inclura indirectement aussi tableau.hcc.

*/

//#include "tableau.hcc"
/**** Début des définitions pouvant être mises dans tableau.hcc. ****/
#include <assert.h>


template <class T>
Tableau<T>::Tableau(int capacite_initiale)
{
    //TODO
    elements = new T[1000]; // cette ligne n'est peut-être pas bonne.
}


template <class T>
Tableau<T>::Tableau(const Tableau& autre)
{
    //TODO
}

template <class T>
Tableau<T>::~Tableau()
{
    //TODO
}

template <class T>
int Tableau<T>::taille() const
{
    //TODO
    return 0;
}


template <class T>
void Tableau<T>::ajouter(const T& item)
{
    //TODO
}

template <class T>
void Tableau<T>::inserer(const T& element, int index)
{
    //TODO
}

template <class T>
void Tableau<T>::enlever(int index)
{
    //TODO
}

template <class T>
int Tableau<T>::trouver(const T& element)
{
    //TODO
    return -1;
}

template <class T>
void Tableau<T>::vider()
{
    //TODO
}


template <class T>
T& Tableau<T>::operator[] (int index)
{
    //TODO
    return elements[0];
}

template <class T>
const T& Tableau<T>::operator[] (int index) const
{
    //TODO
    return elements[0];
}

template <class T>
Tableau<T>& Tableau<T>::operator = (const Tableau<T>& autre)
{
    //TODO
    return *this;
}

template <class T>
bool Tableau<T>::operator == (const Tableau<T>& autre) const
{
    //TODO
    return false;
}


#endif

