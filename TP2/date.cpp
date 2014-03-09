/*
  INF3105 - Structures de données et algorithmes
  UQAM / Département d'informatique
  Hiver 2014
  Squelette de départ pour le TP2.
*/

#include "date.h"
#include <cstdio>
#include <iomanip>
#include <assert.h>
#include<iostream>

Date::Date()
{

    jours = 0;
    heures = 0;
    minutes = 0;
    secondes = 0;

}

Date::Date(int j,int h,int m,int s){

    jours = j;
    heures = h;
    minutes = m;
    secondes = s;

}

bool Date::operator <(const Date& d) const{

   if(jours < d.jours) return true;
   if(jours > d.jours) return false;

   if(heures < d.heures) return true;
   if(heures > d.heures) return false;

   if(minutes < d.minutes) return true;
   if(minutes > d.minutes) return false;

   if(secondes < d.secondes) return true;
   if(secondes > d.secondes) return false;

   return false;

}

std::ostream& operator << (std::ostream& os, const Date& d){

    int jours, heures, minutes, secondes;

    jours = d.jours;
    heures = d.heures;
    minutes = d.minutes;
    secondes = d.secondes;

    char chaine[40];

    sprintf(chaine, "%dj_%02dh%02dm%02ds", jours, heures, minutes, secondes);
    os << chaine;
    return os;

}

std::istream& operator >> (std::istream& is, Date& d){

    int jours, heures, minutes, secondes;
    char j, m, h, s, underscore;

    is >> jours >> j >> underscore >> heures >> h >> minutes >> m >> secondes >> s;
    assert(j=='j');
    assert(underscore=='_');
    assert(h=='h' && m=='m' && s=='s');

    d.jours = jours;
    d.heures = heures;
    d.minutes = minutes;
    d.secondes = secondes;

    return is;

}

std::ostream& operator << (std::ostream& os, const Intervalle& i){

    os << i.debut  << i.fin;
    return os;

}

std::istream& operator >> (std::istream& is, Intervalle& i){

    char crochetgauche, crochetdroit, virgule;
    is >> crochetgauche >> i.debut >> virgule >> i.fin >> crochetdroit;
    assert(crochetgauche=='[' && virgule==',' && crochetdroit==']');
    return is;

}

int Date::convertirEnSecondes(const Date& dt)const{

    std::cout<<"Date";
    int resultat = dt.secondes;

    resultat += dt.minutes*60;
    resultat += dt.heures*3600;
    resultat += dt.jours*86400;

    return resultat;

}

