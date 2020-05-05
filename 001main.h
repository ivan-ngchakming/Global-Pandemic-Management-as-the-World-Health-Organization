#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

//--------------------------functions header files------------------------------
#include "performance_index.h"
#include "load_init_countries_statistics.h"
#include "tutorial.h"
#include "load_save.h"
#include "linkedlist.h"
#include "encryptdecrypt.h"
//--------------------------functions header files------------------------------

//--------------------------------txt document----------------------------------
const string store_game="storegame.txt";
const string init_game="initgame.txt";
//--------------------------------txt document----------------------------------

struct Node{
  string content;
  Node * next;
};
//linked list

struct country
{
  string name;
  unsigned long population;
  unsigned long infections;
  unsigned long deaths;
  unsigned long recovered;
  float infected_percentage;
  double economy;
  double pi; //pi: performance index
  float infection_factor; // Range 0.0 - 5.0
  unsigned long infection_increase;
  int death_probability; // Range 0 - 100
  int recover_probability; // Range 0 - 100
};
//for storing the data for a country

struct card{
  string name;
  string target_type; // country, resources,
  string target;
  string variable;
  bool add;
  double magnitude;
  string cost_type;
  int cost;
};

struct WHO{
  int capital;
  //stores the capital that the WHO have in thousands
  int staff;
  //stores the no. of staff that WHO has
  int medical;
  //stores amout of medical equipment that WHO has
  int capital_income;
  int staff_increment;
  int medical_increment;
  int income_frequency; // # of days until the next income received
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
