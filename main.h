#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

struct Node{
  string content;
  Node * next;
};
//linked list

struct country
{
  string name;
  double population;
  double infections;
  double deaths;
  double recovered;
  double economy;
  double pi;
  float infection_factor; // Range 0.0 - 5.0
  double infection_increase;
  double death_probability; // Range 0 - 1
  //pi: performance index
};
//for storing the data for a country

struct card{
  string name;
  string target;
  string variable;
  bool add;
  double magnitude;
};

struct WHO{
  int capital;
  //stores the capital that the WHO have
  int staff;
  //stores the no. of staff that WHO has
  int medical;
  //stores amout of medical equipment that WHO has
};

//-----------------------for debug----------------------------------
double str_to_double(string s);
void printcounrty(country c);
void printcard(card c);
void printruler();
string doubletostr(double num);
//-----------------------for debug----------------------------------

#endif
