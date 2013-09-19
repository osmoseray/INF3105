/*
  UQAM / Département d'informatique
  INF3105
  Laboratoire 1
*/

#include <iostream>
#include "point.h"
#include<limits.h>

/*
   Allez-y étape par étape. C'est la seule façon de ne pas introduire de bogue!

  �etape 1 : Compiler ce sans modification.
   tape 2 : Enlever la fonction main() et renommer main2() ==> main()
   tape 2 : Enlever la fonction main2() et renommer main3() ==> main()
   ...

 */

int main7(int argc, const char** args)
{
 std::cout << "Bienvenue au cours INF3105 en C++ !" << std::endl;
 return 0;
}

int main2(int argc, const char** args)
{
  Point point(3, 105);
  std::cout << point;
  std::cout << std::endl; // fin de ligne
  return 0;
}

int mainn8(int argc, const char** args)
{
  Point point(1.2,5.7);
// std::cout << "point.x=" << point.x << "point.y=" << point.y << std::endl;
  return 0;
}


int main5(int argc, const char** args)
{
  Point point;
  std::cout << "Entrez un point:" << std::endl;
  std::cin >> point;
  std::cout << "Revoici votre point:" << std::endl;
  std::cout << point << std::endl;
  return 0;
}

int main4(int argc, const char** args)
{
  Point a(0,0);
  Point b(4,3);
  double d = a.distance(b);
  std::cout << "Distance("<< a << "," << b << ")=" << d << std::endl;
  return 0;
}


double obtenirDistanceLaPlusCourte(Point points[]){
 double distanceCourte=INT_MAX;
 return distanceCourte;
}
int main(int argc, const char** args)
{
  int nb;
  std::cin >> nb;


  return 0;
}



