#include <iostream>
#include <string>
#include <conio.h>
//for clear screen
using namespace std;

struct Node{
  string content;
  Node * next;
};
//linked list

struct country
{
  string name;
  double population;
  double infections;
  double deaths;
  double recovered;
  double economy;
  double pi;
  //pi: performance index
};
//for storing the data for a country

struct WHO{
  int capital;
  //stores the capital that the WHO have
  int staff;
  //stores the no. of staff that WHO has
  int medical;
  //stores amout of medical equipment that WHO has
}

void printruler(){
  cout<<"--------------------------------------------------"<<endl;
  //synchronized every ruller have the same length
}

int main()
{
  //------------------initialization-----------------------------

  Node * deck_head = new Node;
  deck_head=NULL;
  //initialize deck list and it is empty
  Node * trash_head = new Node;
  trash_head=NULL;
  //initialize trash list and it is empty
  int day=0;
  //day stores the virtual time in the game
  //also mean the number of round the player had played

  //------------------initialization-----------------------------

  //------------------New game? ----------------------------
  string s="0";
  while ((s!="1")&&(s!="2")){
    cout<<"1. New game"<<endl;
    cout<<"2. Load game"<<endl;
    printruller();
    cin>>s;
  }
  if (s=="1"){
    //new game
  }
  else{
    //load game
  }
  //------------------------------New game? ------------------------------

  //---------------------------the game ----------------------------------

  while calculate_overall_performance_index(AllCountries[]);

  //---------------------------the game ----------------------------------

}
