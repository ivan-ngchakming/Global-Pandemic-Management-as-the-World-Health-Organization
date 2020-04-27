#include <iostream>
using namespace std;

#include "main.h"
#include "load_save.h"
#include "linkedlist.h"


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

  //**************************declare variables*********************************

  //inputting
  cout<<"Day: ";
  cin>>day;

  cout<<"WHO (int capital, int staff, int medical): ";
  cin>>who.capital>>who.staff>>who.medical;

  cout<<"no of countries: ";
  int nation_size;
  cin>>nation_size;
  //++++++++++coutnry++++++++
  string * nation = new string[nation_size];
  //++++++++++coutnry++++++++
  for (int i=0;i<nation_size;++i){
    cout<<i<<"th nation (string name, double population, double infections, double deaths, double recovered, double economy, double pi, float infection_factor, double infection_increase, float death_probability): ";
    cin>>nation[i];
  }
  cout<<endl;

  cout<<"no of action cards: ";
  int action_card_size;
  cin>>action_card_size;
  //++++++++++action_card++++++++
  string * action_card = new string[action_card_size];
  //++++++++++action_card++++++++
  for (int i=0;i<action_card_size;++i){
    cout<<i<<"th action card (string name, string target, string variable, bool add, double magnitude): ";
    cin>>action_card[i];
  }
  cout<<endl;

  cout<<"no of random event cards: ";
  int random_event_card_size;
  cin>>random_event_card_size;
  //++++++++++random_event_card++++++++
  string * random_event_card = new string[random_event_card_size];
  //++++++++++random_event_card++++++++
  for (int i=0;i<random_event_card_size;++i){
    cout<<i<<"th random event card (string name, string target, string variable, bool add, double magnitude): ";
    cin>>random_event_card[i];
  }
  cout<<endl;

  cout<<"Enter deck list until enter exit: "<<endl;
  string s="a";
  while (s!="exit"){
    cin>>s;
    if (s!="exit"){
      insertlist(deck_head,deck_tail,s);
    }
  }

  cout<<"Enter trash list until enter exit: "<<endl;
  s="a";
  while (s!="exit"){
    cin>>s;
    if (s!="exit"){
      insertlist(trash_head,trash_tail,s);
    }
  }

  cout<<"Enter records list until enter exit: "<<endl;
  s="a";
  while (s!="exit"){
    cin>>s;
    if (s!="exit"){
      insertlist(record_head,record_tail,s);
    }
  }

  cout<<"Where to save:"<<endl;
  cin>>s;
  cout<<boolalpha<<savegame(s,day,who,nation,nation_size,action_card,action_card_size,random_event_card,random_event_card_size, deck_head, trash_head, record_head);
  cout<<endl;
  printeverything(day,who,nation,nation_size,action_card,action_card_size,random_event_card,random_event_card_size, deck_head, deck_tail, trash_head, trash_tail, record_head,record_tail);

  day=0;
  who.capital=0;
  who.staff=0;
  who.medical=0;
  for (int i=0;i<nation_size;++i){
    nation[i]="";
  }
  for (int i=0;i<action_card_size;++i){
    action_card[i]="";
  }
  for (int i=0;i<random_event_card_size;++i){
    random_event_card[i]="";
  }
  delete_list(deck_head);
  delete_list(trash_head);
  delete_list(record_head);
  cout<<boolalpha<<loadgame(s,day,who,nation,nation_size,action_card,action_card_size,random_event_card,random_event_card_size, deck_head, deck_tail, trash_head, trash_tail, record_head, record_tail);

  printeverything(day,who,nation,nation_size,action_card,action_card_size,random_event_card,random_event_card_size, deck_head, deck_tail, trash_head, trash_tail, record_head,record_tail);

  return 0;
}
