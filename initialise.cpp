#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "main.h"
#include "linkedlist.h"

//deck_head,deck_tail,trash_head,trash_tail,record_head,reccord_tail,day,who,country,country_size,action_card,random_event_card

 void printall_variables(){

 }

bool (Node * & content, int & day, WHO & who, country [], int country_size){
  ifstream fin;
  if (content==NULL){

    day=0;
    //day

    who.capital=???;
    who.staff=???;
    who.medical???;
    //who

    fin.open(basic_country.c_str());
    if (fin.fail()){
      return false;
    }

//---------------------------unfinish---------------------------
    country_size=0;
    //initialize country size as 0 adn perform counting when a new country is read
    country * newcountry = new country[]
    decrypt(temp,basic_country.c_str());
    //because temp is empty, so it is fine to use for reading countries
    while (temp != NULL){
      string temp_s=spop1(temp);
      country_command(temp,);
    }
//---------------------------unfinish---------------------------

  }

  return true;
  //return true means the program runs smootly without halt the function
}
