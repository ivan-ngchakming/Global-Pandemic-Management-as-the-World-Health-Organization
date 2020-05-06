#include <iostream>
#include <fstream>
using namespace std;

#include "main.h"
#include "command.h"
#include "encryptdecrypt.h"
#include "linkedlist.h"
#include "load_save.h"

int main(){
  //**************************declare variables*********************************
  //----------------deck and trash list------------------------
  Node * deck_head = new Node;
  deck_head=NULL;
  Node * deck_tail = new Node;
  deck_tail=NULL;
  //initialize deck list and it is empty

  Node * trash_head = new Node;
  trash_head=NULL;
  Node * trash_tail = new Node;
  trash_tail=NULL;
  //initialize trash list and it is empty
  //----------------deck and trash list------------------------

  //------------------game status------------------------------
  int day;
  //day stores the virtual time in the game
  //also mean the number of round the player had played
  WHO who;
  //stores what WHO has such as capital, staff and medical equipment
  //------------------game status------------------------------

  //---------load all nation, cards, randomeventcard----------
  //++++++++++coutnry++++++++
  int max_country_size = 20;
  int number_of_countries=0;
  string * countries = new string[max_country_size];

  int init_death_probability = 1;
  int init_recover_probability = 3;
  float country_pi_settings[4] = {0.4, 0.1, 0.1, 0.3};
  float infection_factor = 0.7;
  //++++++++++coutnry++++++++

  //++++++++++action_card++++++++
  int action_card_size=40;
  int number_of_action_card=0;
  string * action_card = new string[action_card_size];
  //++++++++++action_card++++++++

  //++++++++++random_event_card++++++++
  int random_event_card_size=40;
  int number_of_random_event_card=0;
  string * random_event_card = new string[random_event_card_size];
  //++++++++++random_event_card++++++++
  //---------load all nation, cards, randomeventcard----------
  //**************************declare variables*********************************

    string answer;

    cout<<"Day: ";
    getline(cin,answer);
    day=str_to_int(answer);
    cout<<answer<<endl;

    cout<<"WHO: "<<endl;
    cout<<"format: capital,staff,medical,capital_income,staff_increment,medical_increment,income_frequency\n";
    getline(cin,answer);
    if (who_command(answer,who)==false){
      cout<<"WHO error"<<endl;
    }
    cout<<answer<<endl;

    cout<<"Country:"<<endl;
    cout<<"format: name,population,infections,deaths,recovered,infected_percentage,economy,pi,infection_factor,infection_increase,death_probability,recover_probability\n";
    cout<<"Loop until you enter end"<<endl;
    while (answer!="end"){
      getline(cin,answer);
      if (answer!="end"){
        countries[number_of_countries]=answer;
        number_of_countries+=1;
      }
      cout<<answer<<endl;
    }

    cout<<"init_death_probability: ";
    getline(cin,answer);
    init_death_probability=str_to_int(answer);
    cout<<answer<<endl;

    cout<<"init_recover_probability: ";
    getline(cin,answer);
    init_recover_probability=str_to_int(answer);
    cout<<answer<<endl;

    cout<<"country_pi_settings: ";
    cout<<"format: a,b,c,d {float}\n";
    getline(cin,answer);
    if (country_pi_settings_command(answer,country_pi_settings)==false){
      cout<<"country_pi_settings error"<<endl;
    };
    cout<<answer<<endl;

    cout<<"infection_factor: ";
    getline(cin,answer);
    infection_factor=str_to_float(answer);
    cout<<answer<<endl;


    cout<<"Action cards:"<<endl;
    cout<<"format: name,target_type,target,variable,add,magnitude,cost_type,cost\n";
    cout<<"Loop until you enter end"<<endl;
    while (answer!="end"){
      getline(cin,answer);
      if (answer!="end"){
        action_card[number_of_action_card]=answer;
        number_of_action_card+=1;
      }
      cout<<answer<<endl;
    }

    answer="haha";
    cout<<"Random event cards:"<<endl;
    cout<<"format: name,target_type,target,variable,add,magnitude,cost_type,cost\n";
    cout<<"Loop until you enter end"<<endl;
    while (answer!="end"){
      getline(cin,answer);
      if (answer!="end"){
        random_event_card[number_of_random_event_card]=answer;
        number_of_random_event_card+=1;
      }
      cout<<answer<<endl;
    }

    answer="haha";
    cout<<"Deck list:"<<endl;
    cout<<"format: name,target_type,target,variable,add,magnitude,cost_type,cost\n";
    cout<<"Loop until you enter end"<<endl;
    while (answer!="end"){
      getline(cin,answer);
      if (answer!="end"){
        insertlist(deck_head,deck_tail,answer);
      }
      cout<<answer<<endl;
    }

    answer="haha";
    cout<<"Trash list:"<<endl;
    cout<<"format: name,target_type,target,variable,add,magnitude,cost_type,cost\n";
    cout<<"Loop until you enter end"<<endl;
    while (answer!="end"){
      getline(cin,answer);
      if (answer!="end"){
        insertlist(trash_head,trash_tail,answer);
      }
      cout<<answer<<endl;
    }

    //debug
    printeverything(day,who,max_country_size,number_of_countries,countries,
      init_death_probability,init_recover_probability,country_pi_settings,infection_factor,
      action_card,action_card_size,number_of_action_card,
      random_event_card,random_event_card_size,number_of_random_event_card,
      deck_head,deck_tail,trash_head,trash_tail);
    //debug

    savegame(init_game,day,who,number_of_countries,countries,
      init_death_probability,init_recover_probability,country_pi_settings,infection_factor,
      action_card,action_card_size,number_of_action_card,
      random_event_card,random_event_card_size,number_of_random_event_card,
      deck_head,deck_tail,trash_head,trash_tail);


    Node * head=new Node;
    head=NULL;

    decryption(init_game,head);
    printlist(head);

    loadgame(init_game,day,who,max_country_size,number_of_countries,countries,
      init_death_probability,init_recover_probability,country_pi_settings,infection_factor,
      action_card,action_card_size,number_of_action_card,
      random_event_card,random_event_card_size,number_of_random_event_card,
      deck_head,deck_tail,trash_head,trash_tail);

    //debug
    printeverything(day,who,max_country_size,number_of_countries,countries,
      init_death_probability,init_recover_probability,country_pi_settings,infection_factor,
      action_card,action_card_size,number_of_action_card,
      random_event_card,random_event_card_size,number_of_random_event_card,
      deck_head,deck_tail,trash_head,trash_tail);
    //debug


    return 0;
}
