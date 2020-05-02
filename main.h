#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

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

/*
//**************************declare variables*********************************
//----------------deck and trash list------------------------
Node * deck_head = new Node;
deck_head=NULL;
//initialize deck list and it is empty
Node * trash_tail = new Node;
trash_tail=NULL;
Node * deck_tail = new Node;
deck_tail=NULL;
Node * trash_head = new Node;
trash_head=NULL;
//initialize trash list and it is empty
//----------------deck and trash list------------------------

//-----------------record histroy----------------------------
Node * record_head = new Node;
record_head = NULL;
//stores the game history record
Node * record_tail = new Node;
record_tail = NULL;
//-----------------record histroy----------------------------

//------------------game status------------------------------
int day;
//day stores the virtual time in the game
//also mean the number of round the player had played
WHO who;
//stores what WHO has such as capital, staff and medical equipment
//------------------game status------------------------------

//---------load all nation, cards, randomeventcard----------
//++++++++++coutnry++++++++
int nation_size=20;
string * nation = new string[nation_size];
//++++++++++coutnry++++++++

//++++++++++action_card++++++++
int action_card_size=40;
string * action_card = new string[action_card_size];
//++++++++++action_card++++++++

//++++++++++random_event_card++++++++
int random_event_card_size=40;
string * random_event_card = new string[random_event_card_size];
//++++++++++random_event_card++++++++
//---------load all nation, cards, randomeventcard----------
//**************************declare variables*********************************
*/
