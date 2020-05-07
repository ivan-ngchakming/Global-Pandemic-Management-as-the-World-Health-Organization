#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "main.h"
#include "linkedlist.h"
#include "encryptdecrypt.h"
#include "command.h"
#include "dynamic_array.h"


//deck_head,deck_tail,trash_head,trash_tail,record_head,reccord_tail,day,who,country,country_size,action_card,random_event_card

string gen_key(string s){
  string answer="";
  int num=random()%20;
  for (int i=0;i<num;i++){
    answer+=random()%26+'a';
  }
  return answer;
}

bool savegame(string filename, int day, WHO who, int no_of_country, string c[],
  int init_death_probability, int init_recover_probability, float country_pi_settings[], float infection_factor,
  string ac[], int ac_size, int ac_num,
  string rec[], int rec_size, int rec_num,
  Node * & dh, Node * & dt, Node * & th, Node * & tt)
{
  Node * head = new Node;
  head = NULL;
  Node * tail = new Node;
  tail = NULL;
  string s;

  //---------------------------day---------------------------
  insertlist(head,tail,to_string(day));
  //---------------------------day---------------------------

  //---------------------------WHO---------------------------
  s=to_string(who.capital)+","+to_string(who.staff)+","
  +to_string(who.medical)+","+to_string(who.capital_income)+","
  +to_string(who.staff_increment)+","+to_string(who.medical_increment)+","
  +to_string(who.income_frequency);
  insertlist(head,tail,s);
  //---------------------------day---------------------------

  //-------------------------country-------------------------
  for (int i=0;i<no_of_country;++i){
    insertlist(head,tail,c[i]);
  }
 string random_key;
 random_key=gen_key(random_key);
 insertlist(head,tail,random_key);
 //-------------------------country-------------------------

 //-----------------------death_prob-----------------------
  insertlist(head,tail,to_string(init_death_probability));
 //-----------------------death_prob-----------------------
 //----------------init_recover_probability----------------
  insertlist(head,tail,to_string(init_recover_probability));
 //----------------init_recover_probability----------------
 //-------------------country_pi_settings-------------------
 s=to_string(country_pi_settings[0])+","+
 to_string(country_pi_settings[1])+","+
 to_string(country_pi_settings[2])+","+
 to_string(country_pi_settings[3]);
  insertlist(head,tail,s);
 //-------------------country_pi_settings-------------------
 //--------------------infection_factor--------------------
  insertlist(head,tail,to_string(infection_factor));
 //--------------------infection_factor--------------------

 //-------------------------action card-------------------------
 for (int i=0;i<ac_num;++i){
   insertlist(head,tail,ac[i]);
 }
 random_key=gen_key(random_key);
 insertlist(head,tail,random_key);
 //-------------------------action card-------------------------

 //-------------------------random event card-------------------------
 for (int i=0;i<rec_num;++i){
   insertlist(head,tail,rec[i]);
 }
 random_key=gen_key(random_key);
 insertlist(head,tail,random_key);
 //-------------------------random event card-------------------------

 //-----------------------------deck list-----------------------------
   Node * current = dh;
   while (current!=NULL){
     insertlist(head,tail,current->content);
     current=current->next;
   }
   random_key=gen_key(random_key);
   insertlist(head,tail,random_key);
 //-----------------------------deck list-----------------------------

 //-----------------------------trash list-----------------------------
   current = th;
   while (current !=NULL){
     insertlist(head,tail,current->content);
     current=current->next;
   }
   random_key=gen_key(random_key);
   insertlist(head,tail,random_key);
 //-----------------------------trash list-----------------------------

 encryption(filename,head);
 //store all the variables into the a txt file

 delete_list(head);
  return true;
  //return true means the program runs smootly without halt the function
 }

 bool savegame002(string filename, int day, WHO who, int no_of_country, country AllCountries[],
   int init_death_probability, int init_recover_probability, float country_pi_settings[], float infection_factor,
   string ac[], int ac_size, int ac_num,
   string rec[], int rec_size, int rec_num,
   Node * & dh, Node * & dt, Node * & th, Node * & tt)
 {
   string * c = new string[no_of_country];
   for (int i=0;i<no_of_country;++i){
     string s="";
     s+=AllCountries[i].name+",";
     s+=to_string(AllCountries[i].population)+",";
     s+=to_string(AllCountries[i].infections)+",";
     s+=to_string(AllCountries[i].deaths)+",";
     s+=to_string(AllCountries[i].recovered)+",";
     s+=to_string(AllCountries[i].infected_percentage)+",";
     s+=to_string(AllCountries[i].economy)+",";
     s+=to_string(AllCountries[i].pi)+",";
     s+=to_string(AllCountries[i].infection_factor)+",";
     s+=to_string(AllCountries[i].infection_increase)+",";
     s+=to_string(AllCountries[i].death_probability)+",";
     s+=to_string(AllCountries[i].recover_probability);
     c[i]=s;
   }
   savegame(filename,day,who,no_of_country,c,
     init_death_probability,init_recover_probability,country_pi_settings,infection_factor,
     ac,ac_size,ac_num,
     rec,rec_size,rec_num,
     dh,dt,th,tt);

  delete [] c;
  return true;
  //return true means the program runs smootly without halt the function
  }

 bool loadgame(string filename,int & day, WHO & who, int & max_country_size, int & no_of_country, string c[],
   int & init_death_probability, int & init_recover_probability, float country_pi_settings[], float & infection_factor,
   string ac[], int & ac_size, int & ac_num,
   string rec[], int & rec_size, int & rec_num,
   Node * & dh, Node * & dt, Node * & th, Node * & tt)
{
  Node * temp = new Node;
  temp=NULL;
  bool flag;

  decryption(filename, temp);

//---------------------------day---------------------------
day=str_to_int(pop1(temp));
//---------------------------day---------------------------

//---------------------------WHO---------------------------
flag=who_command(pop1(temp),who);
if (flag==false){
  return false;
  //error happen in reading WHO command
}
//---------------------------WHO---------------------------

//-------------------------country-------------------------
  no_of_country=0;
  while(temp->content.find(',')!=string::npos){
    if (no_of_country>=max_country_size){
      grow_array(c,max_country_size);
    }
    c[no_of_country]=temp->content;;
    temp=temp->next;
    no_of_country+=1;
  }
  temp=temp->next;
  //skip the garbage value which represent end
//-------------------------country-------------------------

//-----------------------death_prob-----------------------
  init_death_probability=str_to_int(pop1(temp));
//-----------------------death_prob-----------------------

//----------------init_recover_probability----------------
  init_recover_probability=str_to_int(pop1(temp));
//----------------init_recover_probability----------------

//----------------country_pi_settings_command----------------
  country_pi_settings_command(pop1(temp),country_pi_settings);
//----------------country_pi_settings_command----------------

//--------------------infection_factor--------------------
  infection_factor=str_to_float(pop1(temp));
//--------------------infection_factor--------------------

//-------------------------action card-------------------------
  ac_num=0;
  while(temp->content.find(',')!=string::npos){
    if (ac_num>=ac_size){
      grow_array(ac,ac_size);
    }
    ac[ac_num]=temp->content;;
    temp=temp->next;
    ac_num+=1;
  }
  temp=temp->next;
  //skip the garbage value which represent end
//-------------------------action card-------------------------

//-------------------------random event card-------------------------
  rec_num=0;
  while(temp->content.find(',')!=string::npos){
    if (rec_num>=rec_size){
      grow_array(rec,rec_size);
    }
    rec[rec_num]=temp->content;;
    temp=temp->next;
    rec_num+=1;
  }
  temp=temp->next;
  //skip the garbage value which represent end
//-------------------------random event card-------------------------

//-----------------------------deck list-----------------------------
  delete_list(dh);
  while(temp->content.find(',')!=string::npos){
    Node * t = new Node;
    t->content=temp->content;
    t->next=NULL;
    if (dh==NULL){
      dh=t;
      dt=t;
    }
    else{
      dt->next=t;
      dt=t;
    }
    temp=temp->next;
  }
  temp=temp->next;
  //skip the garbage value which represent end
//-----------------------------deck list-----------------------------

//-----------------------------trash list-----------------------------
  delete_list(th);
  while(temp->content.find(',')!=string::npos){
    Node * t = new Node;
    t->content=temp->content;
    t->next=NULL;
    if (th==NULL){
      th=t;
      tt=t;
    }
    else{
      tt->next=t;
      tt=t;
    }
    temp=temp->next;
  }
  temp=temp->next;
  //skip the garbage value which represent end
//-----------------------------trash list-----------------------------

  delete_list(temp);
  //free the whole temporary list dynamic memory

  return true;
  //return true means the program runs smootly without halt the function
}
