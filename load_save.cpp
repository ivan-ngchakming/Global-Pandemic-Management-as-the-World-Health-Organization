#include "load_save.h"
using namespace std;

//deck_head,deck_tail,trash_head,trash_tail,record_head,reccord_tail,day,who,country,country_size,action_card,random_event_card

string gen_key(string s){
  string answer="";
  int num=random()%20;
  for (int i=0;i<num;i++){
    answer+=random()%26+'a';
  }
  return answer;
}

bool savegame(string filename, int day, WHO who, string c[], int country_size,
  string ac[], int ac_size, string rec[], int rec_size, Node * & dh, Node * & th, Node * &record)
{
   Node * head = new Node;
   head = NULL;
   Node * tail = new Node;
   tail = NULL;

 //---------------------------day---------------------------
 insertlist(head,tail,to_string(day));
  //---------------------------day---------------------------

//---------------------------WHO---------------------------
 insertlist(head,tail,(to_string(who.capital)+to_string(who.staff)+to_string(who.medical)));
 //---------------------------day---------------------------

 //-------------------------country-------------------------
 for (int i=0;i<country_size;++i){
   insertlist(head,tail,c[i]);
 }
 string random_key;
 random_key=gen_key(random_key);
 insertlist(head,tail,random_key);
 //-------------------------country-------------------------

 //-------------------------action card-------------------------
 for (int i=0;i<ac_size;++i){
   insertlist(head,tail,ac[i]);
 }
 random_key=gen_key(random_key);
 insertlist(head,tail,random_key);
 //-------------------------action card-------------------------

 //-------------------------random event card-------------------------
 for (int i=0;i<ac_size;++i){
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

 //-----------------------------record list-----------------------------
 current = record;
 while (current !=NULL){
   insertlist(head,tail,current->content);
   current=current->next;
 }
 random_key=gen_key(random_key);
 insertlist(head,tail,random_key);
 //-----------------------------record list-----------------------------

 encryption(filename,head);
 //store all the variables into the a txt file

  return true;
  //return true means the program runs smootly without halt the function
 }

bool loadgame(string filename, int & day, WHO & who, string c[], int & country_size, string ac[], int & ac_size, string rec[], int & rec_size, Node * & dh, Node * & dt, Node * & th, Node * & tt, Node * & rec_h, Node * & rec_t){
  Node * temp = new Node;
  bool flag;
  temp = NULL;
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
//---------------------------day---------------------------


//-------------------------country-------------------------
  int num=0;
  while(temp->content.find(',')!=string::npos){
    if (num>=country_size){
      grow_array(c,country_size);
    }
    c[num]=temp->content;;
    temp=temp->next;
    num+=1;
  }

  temp=temp->next;
  //skip the garbage value node which tells it is the end of the country list
//-------------------------country-------------------------

//-------------------------action card-------------------------
  num=0;
  while(temp->content.find(',')!=string::npos){
    if (num>=ac_size){
      grow_array(ac,ac_size);
      num+=1;
    }
    ac[num]=temp->content;;
    temp=temp->next;
    num+=1;
  }

  temp=temp->next;
  //skip the garbage value node which tells it is the end of the action card list
//-------------------------action card-------------------------

//-------------------------random event card-------------------------
  num=0;
  while(temp->content.find(',')!=string::npos){
    if (num>=rec_size){
      grow_array(rec,rec_size);
      num+=1;
    }
    rec[num]=temp->content;;
    temp=temp->next;
    num+=1;
  }

  temp=temp->next;
  //skip the garbage value node which tells it is the end of the random event card list
//-------------------------random event card-------------------------

//-----------------------------deck list-----------------------------
  delete_list(dh);
  while(temp->content.find(',')!=string::npos){
    Node * t = new Node;
    t->content=temp->content;
    t->next=NULL;
    if (dh==NULL){
      dh=temp;
      dt=temp;
    }
    else{
      dt->next=temp;
      dt=temp;
    }
  }
  temp=temp->next;
  //skip the garbage value node which tells it is the end of the random event card list
//-----------------------------deck list-----------------------------

//-----------------------------trash list-----------------------------
  delete_list(th);
  while(temp->content.find(',')!=string::npos){
    Node * t = new Node;
    t->content=temp->content;
    t->next=NULL;
    if (th==NULL){
      th=temp;
      tt=temp;
    }
    else{
      tt->next=temp;
      tt=temp;
    }
    temp=temp->next;
  }
//-----------------------------trash list-----------------------------

//-----------------------------record list-----------------------------
  delete_list(rec_h);
  while(temp->content.find(',')!=string::npos){
    Node * t = new Node;
    t->content=temp->content;
    t->next=NULL;
    if (th==NULL){
      rec_h=temp;
      rec_t=temp;
    }
    else{
      rec_t->next=temp;
      rec_t=temp;
    }
    temp=temp->next;
  }
//-----------------------------record list-----------------------------

  delete_list(temp);
  //free the whole temporary list dynamic memory

  return true;
  //return true means the program runs smootly without halt the function
}
