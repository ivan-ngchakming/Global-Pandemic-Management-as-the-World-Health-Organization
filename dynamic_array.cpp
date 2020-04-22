#include <string>
#include <fstream>

struct country(){
  string name;
  double population;
  double death_rate,recovery_rate;economic_impact;
  double PI;
};
//for storing the data for a country

struct card{
  string command;
  double prob;
};

struct Node{
  string content;
  Node * next;
};
//linked list

#include "linnkedlist.h"

bool load_command(card card []){
  card allcards_list= New card;
  allcards_list=NULL;
  decryption("allcards.txt", allcards_list);
  //finish inputting all cards into the allcards_list

  int no_of_cards=0;
  card current=allcards_list;
  while (current!=NULL){
    current=current->next;
    no_of_cards+=1;
  }
  //counting number of cards in the list

  current=allcards_list;
  card * all_card=new card[no_of_cards];
  //dynamic array which stores all cards from the allcards.txt
  for (int i=0;i<no_of_cards;++i){
    all_card[i]=current->content;
  }

  delete [] card;
  //remove the old card array
  card=all_card;
  //update the card array.

  delete_list (allcards_list);
  //remove the temporary list which stores all the cards

  void printlist(Node * & head);
}
