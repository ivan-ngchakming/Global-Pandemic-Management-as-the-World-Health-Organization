#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
using namespace std;


#include "main.h"
#include "linkedlist.h"
#include "encryptdecrypt.h"

//--------------------for debug--------------------------------------------
void printcounrty(country c){
  cout<<"nation: "<<c.name<<endl;
  cout<<"population: "<<doubletostr(c.population)<<endl;
  cout<<"infection: "<<doubletostr(c.infections)<<endl;
  cout<<"deaths: "<<doubletostr(c.deaths)<<endl;
  cout<<"recovered: "<<doubletostr(c.recovered)<<endl;
  cout<<"economy: "<<doubletostr(c.economy)<<endl;
  cout<<"pi: "<<doubletostr(c.pi)<<endl;
  cout<<"infection_factor: "<<doubletostr(c.infection_factor)<<endl;
}

void printcard(card c){
  cout<<"card: "<<c.name<<endl;
  cout<<"target: "<<c.target<<endl;
  cout<<"variable: "<<c.variable<<endl;
  cout<<"add: "<<boolalpha<<c.add<<endl;
  cout<<"magnitude: "<<doubletostr(c.magnitude)<<endl;
}

void printeverything(int & day, WHO & who, string c[], int & nation_size, string ac[], int & ac_size, string rec[], int & rec_size, Node * & dh, Node * & dt, Node * & th, Node * & tt, Node * & rec_h, Node * & rec_t){
  printruler();
  cout<<"Day: "<<day<<endl;
  printruler();
  cout<<"WHO: "<<endl;
  cout<<"capital: "<<who.capital<<endl;
  cout<<"staff: "<<who.staff<<endl;
  cout<<"medical: "<<who.medical<<endl;
  printruler();
  cout<<"nation: "<<nation_size<<endl;
  for(int i=0;i<nation_size;++i){
    cout<<i<<" : "<<c[i]<<endl;
  }
  printruler();
  cout<<"action cards: "<<ac_size<<endl;
  for(int i=0;i<ac_size;++i){
    cout<<i<<" : "<<ac[i]<<endl;
  }
  printruler();
  cout<<"random event cards: "<<rec_size<<endl;
  for(int i=0;i<rec_size;++i){
    cout<<i<<" : "<<rec[i]<<endl;
  }
  printruler();
  printlist(dh);
  printruler();
  printlist(th);
  printruler();
  printlist(rec_h);
}

//--------------------for debug-------------------------------------------

//--------------------data type conversion--------------------------------------
bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}


int str_to_int(string s){
  if (is_digits(s)){
    //turn string to float
    return stoi(s);
  }
  exit(1);
}

float str_to_float(string s){
  if (is_digits(s)){
    //turn string to float
    return stof(s);
  }
  exit(1);
}

double str_to_double(string s){
  if (is_digits(s)){
    //turn string to double
    return stod(s);
  }
  exit(1);
}

string doubletostr(double num){
  return to_string(num);
}
//--------------------data type conversion--------------------------------------

//--------------------------------- UI------------------------------------------
void printruler(){
  cout<<"--------------------------------------------------"<<endl;
  //synchronized every ruller have the same length
}

void clearscreen(){
  system("CLS");
}

//--------------------------------- UI------------------------------------------

/*
int main(){
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
  country * nation = new country[nation_size];
  //++++++++++coutnry++++++++

  //++++++++++action_card++++++++
  int action_card_size=40;
  card * action_card = new card[action_card_size];
  //++++++++++action_card++++++++

  //++++++++++random_event_card++++++++
  int random_event_card_size=40;
  card * random_event_card = new card[random_event_card_size];
  //++++++++++random_event_card++++++++
  //---------load all nation, cards, randomeventcard----------
  //**************************declare variables*********************************

  srand(time(NULL));
  //randomise

  //**************************initialization************************************
  //---------check if the user had saved game before----------
  bool saved_game_flag=false;
  ifstream fin;
  fin.open(store_game.c_str());
  if (fin.fail()){
    //which means fail to open storegame.txt
    system("touch"+store_game);
    //if there is no store game file, then create a new one
  }
  else{
    if (is_empty(fin)){
      //if the file is empty, which means the only way is to create new game
      saved_game_flag=true;
    }
  }
  //the current directory must have a txt file which is for storing file
  //if saved_game_flag is true, which means there is saved game
  //and the program will ask user if he want to continue the game

  //---------check if the user had saved game before----------

  if (saved_game_flag==true){
    string s="0";
    while ((s!="1")&&(s!="2")){
      clearscreen();
      cout<<"1. New game"<<endl;
      cout<<"2. Load game"<<endl;
      printruler();
      cin>>s;
    }
    //ask ueser load or new game
    if (s=="1"){
      saved_game_flag=false;
    }
  }
  Node * temp = new Node;
  temp=NULL;
  if (saved_game_flag==false){
    //new game
    //ask for tutorial
    //can skip tutorial
    tutorial(); //unfinish
  }
  else{
    //load game from text file which store game
    decryption(store_game.c_stry(),temp);
    //temp stores all the content in text file which store game
  }
  store_game.close();
  //close the file
  init_game(temp);  //unfinish
  //temp: this dynamic memory is free in init_game function
  //**************************initialization************************************

  //---------------------------the game ----------------------------------

  while calculate_overall_performance_index(AllCountries[]){
    each_round(deck_head,trash_head,)
  }


  //---------------------------the game ----------------------------------
  //**************************free dynamic memory*******************************

  //-------------deck, trash and record list-------------------
  delete_list(deck_head);
  deltet_list(trash_head);
  delete_list(record);
  //-------------deck, trash and record list-------------------

  //----------------------dynamic array------------------------
  delete [] nation;
  delete [] action_ card ;
  delete [] random_event_card;
  //----------------------dynamic array------------------------

  //**************************free dynamic memory*******************************

  return 0;
}
*/
