#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

#include "main.h"
#include "linkedlist.h"
#include "load_save.h"
#include "performance_index.h"
#include "command.h"
#include "ui.h"
#include "resources_management.h"
#include "infection_rate_calculator.h"
#include "apply_effects.h"


//--------------------data type conversion--------------------------------------
bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789.") == std::string::npos;
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

unsigned long int STRtoULI(string s){
  return stoul(s,nullptr,0);
}
//--------------------data type conversion--------------------------------------

//--------------------for debug--------------------------------------------

void printeverything(int day, WHO who, int max_country_size, int no_of_country, string c[],
  int init_death_probability, int init_recover_probability, float country_pi_settings[], float infection_factor,
  string ac[], int ac_size, int ac_num,
  string rec[], int rec_size, int rec_num,
  Node * & dh, Node * & dt, Node * & th, Node * & tt)
{

  printruler();

  cout<<"Day: "<<day<<endl;
  cout<<endl;

  cout<<"WHO: "<<endl;
  cout<<"capital: "<<who.capital<<endl;
  cout<<"staff: "<<who.staff<<endl;
  cout<<"medical: "<<who.medical<<endl;
  cout<<"capital_income: "<<who.capital_income<<endl;
  cout<<"staff_increment: "<<who.staff_increment<<endl;
  cout<<"medical_increment: "<<who.medical_increment<<endl;
  cout<<"income_frequency: "<<who.income_frequency<<endl;
  cout<<endl;

  cout<<"Maximum country size: "<<max_country_size<<endl;
  cout<<"no of country: "<<no_of_country<<endl;
  cout<<"Country: "<<endl;
  for(int i=0;i<no_of_country;++i){
    cout<<i+1<<" : "<<c[i]<<endl;
  }
  cout<<endl;

  cout<<"init_death_probability: "<<init_death_probability<<endl;
  cout<<endl;

  cout<<"init_recover_probability: "<<init_recover_probability<<endl;
  cout<<endl;

  cout<<"country_pi_settings: "<<endl;
  cout<<"{";
  for(int i=0;i<4;++i){
    cout<<country_pi_settings[i]<<" , ";
  }
  cout<<"}"<<endl;
  cout<<endl;

  cout<<"infection_factor: "<<infection_factor<<endl;
  cout<<endl;


  cout<<"action cards: "<<"(Max: "<<ac_size<<" : no. "<<ac_num<<")"<<endl;
  for(int i=0;i<ac_size;++i){
    cout<<i<<" : "<<ac[i]<<endl;
  }
  cout<<endl;

  cout<<"random event cards: "<<"(Max: "<<rec_size<<" : no. "<<rec_num<<")"<<endl;
  for(int i=0;i<rec_size;++i){
    cout<<i<<" : "<<rec[i]<<endl;
  }
  cout<<endl;

  cout<<"deck: "<<endl;
  printlist(dh);
  cout<<endl;

  cout<<"trash: "<<endl;
  printlist(th);
  cout<<endl;

  printruler();
}

void printeverything002(int day, WHO who, int no_of_country, country c[],
  int init_death_probability, int init_recover_probability, float country_pi_settings[], float infection_factor,
  string ac[], int ac_size, int ac_num,
  string rec[], int rec_size, int rec_num,
  Node * & dh, Node * & dt, Node * & th, Node * & tt)
{

  printruler();

  cout<<"Day: "<<day<<endl;
  cout<<endl;

  cout<<"WHO: "<<endl;
  cout<<"capital: "<<who.capital<<endl;
  cout<<"staff: "<<who.staff<<endl;
  cout<<"medical: "<<who.medical<<endl;
  cout<<"capital_income: "<<who.capital_income<<endl;
  cout<<"staff_increment: "<<who.staff_increment<<endl;
  cout<<"medical_increment: "<<who.medical_increment<<endl;
  cout<<"income_frequency: "<<who.income_frequency<<endl;
  cout<<endl;

  printnewcountry(c,no_of_country);
  cout<<endl;

  cout<<"init_death_probability: "<<init_death_probability<<endl;
  cout<<endl;

  cout<<"init_recover_probability: "<<init_recover_probability<<endl;
  cout<<endl;

  cout<<"country_pi_settings: "<<endl;
  cout<<"{";
  for(int i=0;i<4;++i){
    cout<<country_pi_settings[i]<<" , ";
  }
  cout<<"}"<<endl;
  cout<<endl;

  cout<<"infection_factor: "<<infection_factor<<endl;
  cout<<endl;


  cout<<"action cards: "<<"(Max: "<<ac_size<<" : no. "<<ac_num<<")"<<endl;
  for(int i=0;i<ac_size;++i){
    cout<<i<<" : "<<ac[i]<<endl;
  }
  cout<<endl;

  cout<<"random event cards: "<<"(Max: "<<rec_size<<" : no. "<<rec_num<<")"<<endl;
  for(int i=0;i<rec_size;++i){
    cout<<i<<" : "<<rec[i]<<endl;
  }
  cout<<endl;

  cout<<"deck: "<<endl;
  printlist(dh);
  cout<<endl;

  cout<<"trash: "<<endl;
  printlist(th);
  cout<<endl;

  printruler();
}

//--------------------for debug-------------------------------------------


int main(){
  srand(time(NULL));
  //randomise
  //-----------------------------declare variables-----------------------------
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
  float lockdown_economy_threshold = 0.8;
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
  //-----------------------------declare variables-----------------------------

  //---------------------------------initialize---------------------------------
  //---------check if the user had saved game before----------
  bool saved_game_flag;
  ifstream fin;
  fin.open(store_game.c_str());
  if (fin.fail()){
    saved_game_flag=false;
    //which means fail to open storegame.txt
  }
  else{
    //if there is txt file, the game is saved
    saved_game_flag=true;
  }
  //if saved_game_flag is true, which means there is saved game
  //and the program will ask user if he want to continue the game

  //---------ask user play saved game or not----------
  if (saved_game_flag==true){
    string s="0";
    while ((s!="1")&&(s!="2")){
      //clearscreen();
      cout<<"Menu:"<<endl;
      printruler();
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
  string filename;
  if (saved_game_flag==false){
    //new game
    filename=init_game;
  }
  else{
    //load previous saved game
    filename=store_game;
  }

  loadgame(filename,day,who,max_country_size,number_of_countries,countries,
    init_death_probability,init_recover_probability,country_pi_settings,infection_factor,
    action_card,action_card_size,number_of_action_card,
    random_event_card,random_event_card_size,number_of_random_event_card,
    deck_head,deck_tail,trash_head,trash_tail);


  //---------------------------------initialize---------------------------------

  // printeverything(day,who,max_country_size,number_of_countries,countries,
  //   init_death_probability,init_recover_probability,country_pi_settings,infection_factor,
  //   action_card,action_card_size,number_of_action_card,
  //   random_event_card,random_event_card_size,number_of_random_event_card,
  //   deck_head,deck_tail,trash_head,trash_tail);
  // //debug


  country * AllCountries = new country[number_of_countries];
  for (int i=0;i<number_of_countries;++i){
    if (country_command(countries[i],AllCountries[i])==false){
      cout<<"Error in input country"<<endl;
    }
  }
  delete [] countries;

  // printeverything002(day,who,number_of_countries,AllCountries,
  //   init_death_probability,init_recover_probability,country_pi_settings,infection_factor,
  //   action_card,action_card_size,number_of_action_card,
  //   random_event_card,random_event_card_size,number_of_random_event_card,
  //   deck_head,deck_tail,trash_head,trash_tail);


//---------------------------the game ----------------------------------
bool exit=false;
float winning_pi = 90;
float overall_pi = calculate_overall_performance_index(AllCountries,number_of_countries,country_pi_settings);
while ((overall_pi<=winning_pi) && (exit==false)){
  overall_pi = calculate_overall_performance_index(AllCountries,number_of_countries,country_pi_settings);
  // when the PI is not enough and the user not yet want to exit
  // Start loop of the day.

  // clearscreen();
  string answer;
  //storing the answer from user
  day+=1;
  //the next day
  bool action=false;

  string * temp5card = new string[5];
  for (int i=0;i<5;++i){
    temp5card[i]=action_card[rand()%number_of_action_card];
  }

  while ((action==false)&&(exit==false)){
    //loop until the user quit or perform action
    clearscreen();
    //----------printing all country statistic in simple way----------
    printruler();
    cout<<left;
    cout << " Overall Performance Index: " << overall_pi << endl;
    printruler();
    who.income_frequency = 7; // Temperary for debug
    cout << " Days left until the next resources income arrive: " << who.income_frequency - day % who.income_frequency << endl;
    cout << " Capital: " << who.capital << "| Staff: " << who.staff << "| Medical Equipment: " << who.medical << endl;
    printruler();
    cout<<setw(20)<<"Country Name"<<setw(10)<<"performance Index"<<endl;
    for (int i=0;i<number_of_countries;++i){
      cout<<setw(20)<<AllCountries[i].name;
      cout<<setw(10)<<AllCountries[i].pi;
      cout<<endl;
    }
    printruler();
    //----------printing all country statistic in simple way----------
    //------------------------------menu------------------------------
    cout<<endl;
    cout<<"Day: "<< day << endl;
    cout<<"1: View statistics of all Countries"<<endl;
    cout<<"2: View market"<<endl;
    cout<<"3: Use Action card"<<endl;
    cout<<"0: Exit game"<<endl;
    printruler();
    //------------------------------menu------------------------------
    //----------------user input----------------
    answer = get_user_input(3);
    //clearscreen();
    //----------------user input----------------

    if (answer=="0"){
      //quit game
      //-------------user input-------------
      cout<<"Are you you want to exit (Y/N)"<<endl;
      answer="a";
      while ((answer!="Y")&&(answer!="N")){
        //loop until answer is not Y or N
        cout<<"Input: ";
        cin>>answer;
        if ((answer!="Y")&&(answer!="N")){
          cout<<"Invalid input!"<<endl;
        }
      }
      //clearscreen();
      //-------------user input-------------
      if (answer=="Y"){
        //user really want to exit the game
        //-------------user input-------------
        //clearscreen();
        cout<<"Save game? (Y/N)"<<endl;
        answer="a";
        while ((answer!="Y")&&(answer!="N")){
          cout<<"Input: ";
          cin>>answer;
          if ((answer!="Y")&&(answer!="N")){
            cout<<"Invalid input!"<<endl;
          }
        }
        //clearscreen();
        //-------------user input-------------

        if (answer=="Y"){
          //user want to save game

          string command="touch "+store_game;
          system(command.c_str());

          filename=store_game;
          savegame002(filename,day,who,number_of_countries,AllCountries,
            init_death_probability,init_recover_probability,country_pi_settings,infection_factor,
            action_card,action_card_size,number_of_action_card,
            random_event_card,random_event_card_size,number_of_random_event_card,
            deck_head,deck_tail,trash_head,trash_tail);
        }
        //if answer=="N", the program will not save the game
        exit=true;
        //turn exit to true then out the loop so end the game
      }
      //if answer is No then nothing happen
    }

    if (answer=="1"){
      //printing all country in detail way
      //----------------print table----------------
      printnewcountry(AllCountries, number_of_countries);
      //----------------print table----------------

      //---------------quit the table---------------
      cout << endl;
      cout << "Input 0 to exit" << endl;
      printruler();
      answer = answer = get_user_input(0);
      //---------------quit the table---------------
    }

    if (answer=="2")
    {
      //purchase from the market
      //------------print market------------
      clearscreen();
      cout<<"Market:"<<endl;
      printruler();
      cout<<setw(50)<<" 1: Hire 50 staffs"<<setw(15)<<"Cost:$100"<<endl;
      cout<<setw(50)<<" 2: Hire 100 staffs"<<setw(15)<<"Cost:$200"<<endl;
      cout<<setw(50)<<" 3: Buy 50 medical equipment"<<setw(15)<<"Cost:$100"<<endl;
      cout<<setw(50)<<" 4: Buy 100 medical equipment"<<setw(15)<<"Cost:$200"<<endl;
      //buy action cards
      for (int i=0;i<5;++i){
        int pos=0;
        string temps;
        int next_pos=temp5card[i].find(",");
        temps=temp5card[i].substr(pos,next_pos);
        cout<<setw(50)<<" "+to_string(i+5)+": CARD - "+temps<<setw(15)<<"Cost:$300"<<endl;
      }
      cout << setw(50) << " 0: Exit." << endl;
      printruler();
      //------------print market------------
      //-------------user input-------------
      answer = get_user_input(9);
      //-------------user input-------------

      //---------------effect---------------
      if (answer=="1") {
        if (who.capital >= 100) {
          who.staff += 50;
          who.capital -= 100;
        }
        else
        {
          clearscreen();
          cout << "Not enough capital" << endl;
          cout << "Press 0 to Continue" << endl;
          get_user_input(0);
        }
      }
      else if (answer=="2") {
        if (who.capital >= 200) {
          who.staff += 100;
          who.capital -= 200;
        }
        else
        {
          clearscreen();
          cout << "Not enough capital" << endl;
          cout << "Press 0 to Continue" << endl;
          get_user_input(0);
        }
      }
      else if (answer=="3") {
        if (who.capital >= 100) {
          who.medical += 50;
          who.capital -= 100;
        }
        else
        {
          clearscreen();
          cout << "Not enough capital" << endl;
          cout << "Press 0 to Continue" << endl;
          get_user_input(0);
        }
      }
      else if (answer=="4") {
        if (who.capital >= 200) {
          who.medical += 100;
          who.capital -= 200;
        }
        else
        {
          clearscreen();
          cout << "Not enough capital" << endl;
          cout << "Press 0 to Continue" << endl;
          get_user_input(0);
        }
      }
      else if (str_to_int(answer) > 4)
      {
        if (who.capital >= 300) {
          // MIKE: Move card back into deck
        }
        else
        {
          clearscreen();
          cout << "Not enough capital" << endl;
          cout << "Press 0 to Continue" << endl;
          get_user_input(0);
        }
      }
      else if (answer == "0") {
        // Return to menu.
      }
      //---------------effect---------------
    }

    if (answer=="3")
    {
      cout << "Debug: start action card menu" << endl;
      //action card
      action=true;

      string a[3];
      pop3(deck_head,trash_head,a);
      //3 cards store in array of string a in string format
      card a3[3];
      for (int i=0;i<3;++i){
         if (card_command(a[i],a3[i])==true){
           cout<<i+1<<":"<<endl;
           printcard(a3[i]);
           cout<<endl;
         }
         else{
           cout<<"error in read card"<<endl;
         }
       }

      //---------------user choose---------------
      cout << "Input 1/2/3" << endl;
      printruler();
      answer = get_user_input(3);
      //---------------user choose---------------
      //---------------effect---------------

       if (!(use_action_card(a3[str_to_int(answer)], who, AllCountries, number_of_countries))) {
         cout << setw(50) << "Not enough resource to use this card." << endl;
       }

      //---------------effect---------------
    }


  }
  //finish one day by using one action card
  //-------------------------random event card-------------------------------

  card tempcard;
  if (!(card_command(random_event_card[rand()%number_of_random_event_card],tempcard))){
    cout<<"Error in reading random event card"<<endl;
  }
  use_random_card(tempcard, who, AllCountries, number_of_countries);

  //-------------------------random event card-------------------------------

  delete [] temp5card;

  //-------------------------Update Game Status-------------------------------
  daily_resources_income(day, who, overall_pi);
  calculate_daily_infection(AllCountries, number_of_countries);
  calculate_daily_economic_impact(AllCountries, number_of_countries, lockdown_economy_threshold);
  overall_pi = calculate_overall_performance_index(AllCountries,number_of_countries,country_pi_settings);
  //-------------------------Update Game Status-------------------------------

  // End loop of the day
}
//finish whole game
if (exit==false){
  //exit == false means the user out the loop because he win the game
  //as PI over the graduation mark

  string command="rm "+store_game;
  system(command.c_str());
  //remove the stored game status because user had win the game
}
//clearscreen();
//---------------------------the game ----------------------------------


  //----------------------------free dynamic memory-----------------------------
  //-------------deck, trash and record list-------------------
  delete_list(deck_head);
  delete_list(trash_head);
  //-------------deck, trash and record list-------------------

  //----------------------dynamic array------------------------
  delete [] countries;
  delete [] action_card ;
  delete [] random_event_card;
  //----------------------dynamic array------------------------
  //----------------------------free dynamic memory-----------------------------

  return 0;
}
