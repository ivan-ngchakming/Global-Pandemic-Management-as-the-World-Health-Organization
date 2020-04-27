#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//--------------------------------txt document----------------------------------
const string store_game="storegame.txt";
//--------------------------------txt document----------------------------------

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
  //pi: performance index
  float infection_factor; // Range 0.0 - 5.0
  double infection_increase;
  float death_probability; // Range 0 - 1
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


//-----------------------data type conversion----------------------------------
int str_to_int(string s);
float str_to_float(string s);
double str_to_double(string s);
string doubletostr(double num);
void printcounrty(country c);
void printcard(card c);
//-----------------------data type conversion----------------------------------

//-----------------------for UI----------------------------------
void clearscreen();
void printruler();
void printeverything(int & day, WHO & who, string c[], int & country_size, string ac[], int & ac_size, string rec[], int & rec_size, Node * & dh, Node * & dt, Node * & th, Node * & tt, Node * & rec_h, Node * & rec_t);
//-----------------------for UI----------------------------------
#endif
