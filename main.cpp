#include "main.h"


//--------------------for debug--------------------------------------------

string doubletostr(double num){
  return to_string(num);
}

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

double str_to_double(string s){
  if (is_digits(s)){
    //turn string to double
    return stod(s);
  }
  exit(1);
}

void printcounrty(country c){
  cout<<"country: "<<c.name<<endl;
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

//--------------------for debug--------------------------------------------

void printruler(){
  cout<<"--------------------------------------------------"<<endl;
  //synchronized every ruller have the same length
}

void clearscreen(){
  system("CLS");
}


//real
/*
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

  init_deck_trash_list(deck_head,trash_head);
  //initialize deck list and trash list
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
    //ask for tutorial
    //can skip tutorial
    tutorial();
    init_new_game();
  }
  else{
    //load game

  }
  //------------------------------New game? ------------------------------

  //---------------------------the game ----------------------------------

  while calculate_overall_performance_index(AllCountries[]){
    each_round(deck_head,trash_head,)
  }
  return 0;

  //---------------------------the game ----------------------------------

}
*/
