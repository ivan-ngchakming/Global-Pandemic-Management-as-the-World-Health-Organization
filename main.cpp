#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <iomanip>
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
  printruller();
  cout<<"Day: "<<day<<endl;
  printruller();
  cout<<"WHO: "<<endl;
  cout<<"capital: "<<who.capital<<endl;
  cout<<"staff: "<<who.staff<<endl;
  cout<<"medical: "<<who.medical<<endl;
  printruller();
  cout<<"nation: "<<nation_size<<endl;
  for(int i=0;i<nation_size;++i){
    cout<<i<<" : "<<c[i]<<endl;
  }
  printruller();
  cout<<"action cards: "<<ac_size<<endl;
  for(int i=0;i<ac_size;++i){
    cout<<i<<" : "<<ac[i]<<endl;
  }
  printruller();
  cout<<"random event cards: "<<rec_size<<endl;
  for(int i=0;i<rec_size;++i){
    cout<<i<<" : "<<rec[i]<<endl;
  }
  printruller();
  printlist(dh);
  printruller();
  printlist(th);
  printruller();
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
void printruller(){
  cout<<"--------------------------------------------------"<<endl;
  //synchronized every ruller have the same length
}

void clearscreen(){
  system("CLS");
}

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
    if (!is_empty(fin)){
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
      cout<<"Menu:"<<endl;
      printruller();
      cout<<"1. New game"<<endl;
      cout<<"2. Load game"<<endl;
      printruller();
      cin>>s;
    }
    //ask ueser load or new game
    if (s=="1"){
      saved_game_flag=false;
    }
  }
  Node * temp = new Node;
  temp=NULL;
  string filename;
  if (saved_game_flag==false){
    //new game
    //ask for tutorial
    //can skip tutorial
    tutorial(); //unfinish
    filename=init_game;
  }
  else{
    filename=store_game;
  }
  loadgame(filename,day,who,nation,nation_size,action_card,action_card_size,random_event_card,random_event_card_size,deck_head,deck_tail,trash_head,trash_tail,record_head,record_tail);
  //for debug
  printeverything(day,who,nation,nation_size,action_card,action_card_size,random_event_card,random_event_card_size,deck_head,deck_tail,trash_head,trash_tail,record_head,record_tail);
  //for debug
  //**************************initialization************************************

  //---------------------------the game ----------------------------------
  bool exit=false;
  while ((calculate_overall_performance_index(???)<=??) || (exit==false)){
    //loop when the PI is not enough and the user not yet want to exit

    clearscreen();
    string answer;
    //storing the answer from user
    day+=1;
    //the next day
    bool action=false;
    while ((action==false)&&(exit==false)){
      clearscreen();
      //----------printing all country statistic in simple way----------
      printruller();
      cout<<left;
      cout<<setw(20)<<"Country Name"<<setw(10)<<"performance Index"<<endl;
      for (int i=0;i<nation_size;++i){
        country temp;
        country_command(c[i],temp);
        cout<<setw(20)<<temp.name;
        cout<<setw(10)<<temp.pi;
        cout<<endl;
      }
      printruller();
      //----------printing all country statistic in simple way----------
      cout<<"Day: "<<day<<endl;
      cout<<"1: See Long statistic table???"<<endl;
      cout<<"2: Purchase from the market???"<<endl;
      cout<<"3: Use Action card???"<<endl;
      cout<<"0: Exit the game???"<<endl;
      printruller();
      //*****************user input*****************
      answer="-1";
      while ((answer=="0")&&(answer=="1")&&(answer=="2")&&(answer=="3")){
        cout<<"Input: ";
        cin>>answer;
        if (!((answer=="0")||(answer=="1")||(answer=="2")||(answer=="3"))){
          cout<<"Invalid input!"<<endl;
        }
      }
      //*****************user input*****************
      clearscreen();

      if (answer=="1"){
        //printing all country in detail way

        //----------------print table----------------
        clearscreen();
        cout<<left;
        cout<<setw(15)<<"Country Name"<<setw(10)<<"Population"<<setw(10)<<"Infection"<<setw(10)<<"Death"<<setw(10)<<"Recovered"<<setw(10)<<"Economy"<<setw(20)<<"performance Index"<<endl;
        for (int i=0;i<size;++i){
          country temp;
          country_command(c[i],temp);

          cout<<setw(15)<<temp.name;
          cout<<setw(15)<<temp.population;
          cout<<setw(15)<<temp.infections;
          cout<<setw(15)<<temp.deaths;
          cout<<setw(15)<<temp.recovered;
          cout<<setw(15)<<temp.economy;
          cout<<setw(15)<<temp.pi;
          cout<<endl;
        }
        //----------------print table----------------

        //---------------quit the table---------------
        cout<<endl;
        cout<<"Input 0 to exit"
        printruller();
        answer="-1";
        while (answer=="0"){
          cout<<"Input: ";
          cin>>answer;
          if (!(answer=="0")){
            cout<<"Invalid input!"<<endl;
          }
        }
        //---------------quit the table---------------
        clearscreen();
      }

      if (answer=="2"){
        //purchase from the market

        clearscreen();
        //------------print market------------
        cout<<"Market:"<<endl;
        printruller();
        //buy for who or ???
        cout<<" 1: ???"<<endl;
        cout<<" 2: ???"<<endl;
        cout<<" 3: ???"<<endl;
        cout<<" 4: ???"<<endl;
        cout<<" 5: ???"<<endl;
        //buy action cards
        cout<<" 6: ???"<<endl;
        cout<<" 7: ???"<<endl;
        cout<<" 8: ???"<<endl;
        cout<<" 9: ???"<<endl;
        cout<<"10: ???"<<endl;
        cout<<endl;
        cout<<"0: quit"<<endl;

        printruller();
        //------------print market------------
        //-------------user input-------------
        answer="a";
        while ((answer.length==1)&&((answer[0]>="0")&&(answer[0]<="9"))){
          cout<<"Input: ";
          cin>>answer;
          if (!((answer.length==1)&&((answer[0]>="0")&&(answer[0]<="9")))){
            cout<<"Invalid input!"<<endl;
          }
        }
        clearscreen();
        //-------------user input-------------
      }

      if (answer=="3"){
        //action card
        action=true;
        string a[3];
        pop3(deck_head,trash_head,a);
        //???
        //3 cards store in array of string a in string format
      }

      if (answer=="0"){
        //quit game
        //-------------user input-------------
        clearscreen();
        cout<<"Are you sure to exit??? (Y/N)"<<endl;
        answer="a";
        while ((answer>="Y")&&(answer<="N")){
          cout<<"Input: ";
          cin>>answer;
          if (!((answer>="Y")&&(answer<="N"))){
            cout<<"Invalid input!"<<endl;
          }
        }
        clearscreen();
        //-------------user input-------------
        if (answer=="Y"){
          //which user really want to exit the game

          //-------------user input-------------
          clearscreen();
          cout<<"Save game??? (Y/N)"<<endl;
          answer="a";
          while ((answer>="Y")&&(answer<="N")){
            cout<<"Input: ";
            cin>>answer;
            if (!((answer>="Y")&&(answer<="N"))){
              cout<<"Invalid input!"<<endl;
            }
          }
          clearscreen();
          //-------------user input-------------

          if (answer=="Y"){
            //user want to save game
            filename=store_game;
            savegame(filename,day,who,nation,nation_size,action_card,cation_card_size,random_event_card,random_event_card_size,deck_head,trash_head,record_head);
          }
          //if answer=="N", the program will not save the game
          exit=true;
          //turn exit to true then out the loop so end the game
        }
        //if answer is No then nothing happen
        clearscreen();
      }

    }
    //finish one day by using one action card
    //-------------------------random event card-------------------------------
    //???
    //-------------------------random event card-------------------------------
  }
  //finish whole game
  if (exit==false){
    //exit == false means the user out the loop because he win the game
    //as PI over the graduation mark

    //??? congrat to the user ha ha
    system("rm "+store_game)
    //remove the store_game txt file because the user had win the game
    //if the user like the game, he should play new game as he finish the game
  }
  clearscreen();


  //---------------------------the game ----------------------------------
  //**************************free dynamic memory*******************************

  //-------------deck, trash and record list-------------------
  delete_list(deck_head);
  deltet_list(trash_head);
  delete_list(record);
  //-------------deck, trash and record list-------------------

  //----------------------dynamic array------------------------
  delete [] nation;
  delete [] action_card ;
  delete [] random_event_card;
  //----------------------dynamic array------------------------

  //**************************free dynamic memory*******************************
  return 0;
}
