/*


  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique

  Programme pour tester la classe générique Tableau<T>.
*/

#include <iostream>
#include "tableau.h"

void test1(){
    std::cout << "test1() : ajouts simples" << std::endl;
    Tableau<int> t;
    t.ajouter(3);
    t.ajouter(4);
    bool ok = true;
    if(t[0] != 3){
        std::cout << " ==> ECHEC t[0]!=3" << std::endl;
        ok=false;
    }
    if(t[1] != 4){
        std::cout << " ==> ECHEC t[0]!=3" << std::endl;
        ok=false;
    }
    if(t.taille()!=2){
        std::cout << " ==> ECHEC Taille" << std::endl;
        ok=false;
    }
    if(ok)
        std::cout << " ==> OK" << std::endl;
}

void test2(){
    std::cout << "test2() : ajouts +" << std::endl;
    Tableau<int> t;
    int n = 256*256;
    for(int i=0;i<n;i++)
        t.ajouter(i*2);

    if(t.taille()!=n)
        std::cout << " ==> ECHEC taille()" << std::endl;

    for(int i=0;i<t.taille();i++)
        if(t[i] != i*2){
            std::cout << " ==> ECHEC : t[i]=" << t[i] << "!=" << (i*2) << std::endl;
            return;
        }
    std::cout << " ==> OK" << std::endl;
}

void test3(){
    std::cout << "test3() : operator =" << std::endl;
    Tableau<int> t1;
    for(int i=0;i<10;i++)
        t1.ajouter(i);
    Tableau<int> t2;
    t2 = t1;

    if(t2.taille()!=10)
        std::cout << " ==> ECHEC taille()" << std::endl;

    for(int i=0;i<10;i++)
        if(t2[i] != i){
            std::cout << " ==> ECHEC : t2[i]=" << t2[i] << "!=" << (i) << std::endl;
            return;
        }

    std::cout << " ==> OK" << std::endl;
}

void test4(){
    std::cout << "test4() : operator =" << std::endl;
    Tableau<int> t1;
    for(int i=0;i<10;i++)
        t1.ajouter(i);
    Tableau<int> t2;
    t2 = t1;

    for(int i=0;i<10;i++)
        t1[i] = 0;
    t1.ajouter(0);

    if(t2.taille()!=10){
        std::cout << " ==> ECHEC taille()" << std::endl;
        return;
    }

    for(int i=0;i<10;i++)
        if(t2[i] != i){
            std::cout << " ==> ECHEC : t2[i]=" << t2[i] << "!=" << (i) << std::endl;
            return;
        }

    std::cout << " ==> OK" << std::endl;
}

void test5(){
    std::cout << "test5() : operator =" << std::endl;
    Tableau<int> t1;
    for(int i=0;i<10;i++)
        t1.ajouter(i);
    Tableau<int> t2;
    t2 = t1;
    t1.vider();
    for(int i=0;i<100;i++)
        t1.ajouter(i+1);
    t2 = t1;

    if(t2.taille()!=100){
        std::cout << " ==> ECHEC taille()" << std::endl;
        return;
    }

    for(int i=0;i<t2.taille();i++)
        if(t2[i] != i+1){
            std::cout << " ==> ECHEC : t2[i]=" << t2[i] << "!=" << (i+1) << std::endl;
            return;
        }
    std::cout << " ==> OK" << std::endl;
}

void test6(){
    std::cout << "test6() : constructeur par copie" << std::endl;
    Tableau<int> t1;
    for(int i=0;i<10;i++)
        t1.ajouter(i);
    Tableau<int> t2(t1);

    if(t2.taille()!=10){
        std::cout << " ==> ECHEC taille()" << std::endl;
        return;
    }

    for(int i=0;i<t2.taille();i++)
        if(t2[i] != i){
            std::cout << " ==> ECHEC : t2[i]=" << t2[i] << "!=" << i << std::endl;
            return;
        }

    std::cout << " ==> OK" << std::endl;
}

void test7(){
    std::cout << "test7() : operator ==" << std::endl;
    Tableau<int> t1;
    Tableau<int> t2;
    for(int i=0;i<1024;i++){
        t1.ajouter(i);
        t2.ajouter(i);
    }

    t1.ajouter(3);
    bool ok = true;

    if(t1==t2){
        std::cout << " ==> ECHEC #1" << std::endl;
        ok = false;
    }
    if(t2==t1){
        std::cout << " ==> ECHEC #2" << std::endl;
        ok = false;
    }
    t2.ajouter(3);
    if(!(t1==t2)){
        std::cout << " ==> ECHEC #3" << std::endl;
        ok = false;
    }
    if(!(t2==t1)){
        std::cout << " ==> ECHEC #4" << std::endl;
        ok = false;
    }

    if(!(t1==t1)){
        std::cout << " ==> ECHEC #5" << std::endl;
        ok = false;
    }

    Tableau<int> t3;
    if(t1==t3){
        std::cout << " ==> ECHEC #6" << std::endl;
        ok = false;
    }
    t3 = t2;
    if(!(t1==t3)){
        std::cout << " ==> ECHEC #6" << std::endl;
        ok = false;
    }


    if(ok)
        std::cout << " ==> OK" << std::endl;
}

void test8(){
    std::cout << "test8() : insertion" << std::endl;
    Tableau<int> t1;
    Tableau<int> t2;
    for(int i=0;i<16;i++){
        t1.ajouter(i+1);
        t2.ajouter(i);
    }

    t1.inserer(0);
    t2.ajouter(16);

    bool ok = true;
    if(!(t1==t2)){
        std::cout << " ==> ECHEC #1" << std::endl;
        ok = false;
    }

    Tableau<int> t3;
    for(int i=4;i<17;i++){
        t3.ajouter(i);
    }
    t3.inserer(1, 0);
    t3.inserer(0, 0);
    t3.inserer(3, 2);
    t3.inserer(2, 2);

    if(!(t1==t2)){
        std::cout << " ==> ECHEC #2" << std::endl;
        ok = false;
    }
    if(ok)
        std::cout << " ==> OK" << std::endl;
}

void test9(){
    std::cout << "test9() : enlèvement" << std::endl;
    Tableau<int> t1;
    for(int i=0;i<16;i++){
        t1.ajouter(i);
    }

    t1.enlever(5);
    Tableau<int> t2;
    for(int i=0;i<5;i++){
        t2.ajouter(i);
    }
    for(int i=6;i<16;i++){
        t2.ajouter(i);
    }

    bool ok = true;
    if(!(t1==t2)){
        std::cout << " ==> ECHEC #2" << std::endl;
        ok = false;
    }
    if(ok)
        std::cout << " ==> OK" << std::endl;
}

void test10(){
    std::cout << "test10() : trouver" << std::endl;
    Tableau<int> t1;
    for(int i=0;i<100;i++){
        t1.ajouter(i*2);
    }

    bool ok = true;

    for(int i=0;i<100;i++){
        int index = t1.trouver(i*2);
        if(index != i){
            std::cout << " ==> ECHEC i=" << i << std::endl;
            ok = false;
            break;
        }
        index = t1.trouver(i*2+1);
        if(index != -1){
            std::cout << " ==> ECHEC i=" << i << std::endl;
            ok = false;
            break;
        }
    }
    if(ok)
        std::cout << " ==> OK" << std::endl;
}

class Point{
  public:
    Point(double x_=0, double y_=0) : x(x_), y(y_){}
    bool operator == (const Point& autre)const{ return x==autre.x && y==autre.y;}
  private:
    double x, y;
};

void test11(){
    std::cout << "test11() : trouver" << std::endl;
    Tableau<Point> points;
    points.ajouter(Point());
    points.ajouter(Point(2,3));
    points.ajouter(Point(4,5));
    points.ajouter(Point(3, 4));
    Tableau<Point> points2;
    points2 = points;
    int index = points.trouver(Point(4,5));
    if(index==2)
        std::cout << " ==> OK" << std::endl;
    else
        std::cout << " ==> ECHEC" << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    return 0;
}

