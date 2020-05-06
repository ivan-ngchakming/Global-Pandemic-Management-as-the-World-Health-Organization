#ifndef DEBUG_MAIN_H
#define DEBUG_MAIN_H

#include <iostream>
#include <string>
using namespace std;

//--------------------------------txt document----------------------------------
const string store_game="storegame.txt";
const string init_game="initgame.txt";
//--------------------------------txt document----------------------------------

//------------------------------------struct------------------------------------
struct Node{
  string content;
  Node * next;
};
//linked list

struct country
{
  string name;
  unsigned long int population;
  unsigned long int infections;
  unsigned int deaths;
  unsigned int recovered;
  float infected_percentage;
  double economy;
  double pi; //pi: performance index
  float infection_factor; // Range 0.0 - 5.0
  unsigned long int infection_increase;
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
//------------------------------------struct------------------------------------

//-----------------------data type conversion----------------------------------
int str_to_int(string s);
float str_to_float(string s);
double str_to_double(string s);
string doubletostr(double num);
void printcounrty(country c);
void printcard(card c);
unsigned long int STRtoULI(string s);
//-----------------------data type conversion----------------------------------

//-----------------------for UI----------------------------------
void clearscreen();
void printruler();
//-----------------------for UI----------------------------------

//-----------------------debug----------------------------------
void printeverything(int day, WHO who, int max_country_size, int no_of_country, string c[],
  int init_death_probability, int init_recover_probability, float country_pi_settings[], float infection_factor,
  string ac[], int ac_size, int ac_num,
  string rec[], int rec_size, int rec_num,
  Node * & dh, Node * & dt, Node * & th, Node * & tt);
//-----------------------debug----------------------------------

#endif
