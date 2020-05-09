#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits>
using namespace std;

#include "main.h"
#include "linkedlist.h"
#include "load_save.h"
#include "command.h"
#include "performance_index.h"
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

// void printeverything(int day, WHO who, int max_country_size, int no_of_country, string c[],
//   int init_death_probability, int init_recover_probability, float country_pi_settings[], float infection_factor,
//   string ac[], int ac_size, int ac_num,
//   string rec[], int rec_size, int rec_num,
//   Node * & dh, Node * & dt, Node * & th, Node * & tt)
// {
//
//   printruler();
//
//   cout<<"Day: "<<day<<endl;
//   cout<<endl;
//
//   cout<<"WHO: "<<endl;
//   cout<<"capital: "<<who.capital<<endl;
//   cout<<"staff: "<<who.staff<<endl;
//   cout<<"medical: "<<who.medical<<endl;
//   cout<<"capital_income: "<<who.capital_income<<endl;
//   cout<<"staff_increment: "<<who.staff_increment<<endl;
//   cout<<"medical_increment: "<<who.medical_increment<<endl;
//   cout<<"income_frequency: "<<who.income_frequency<<endl;
//   cout<<endl;
//
//   cout<<"Maximum country size: "<<max_country_size<<endl;
//   cout<<"no of country: "<<no_of_country<<endl;
//   cout<<"Country: "<<endl;
//   for(int i=0;i<no_of_country;++i){
//     cout<<i+1<<" : "<<c[i]<<endl;
//   }
//   cout<<endl;
//
//   cout<<"init_death_probability: "<<init_death_probability<<endl;
//   cout<<endl;
//
//   cout<<"init_recover_probability: "<<init_recover_probability<<endl;
//   cout<<endl;
//
//   cout<<"country_pi_settings: "<<endl;
//   cout<<"{";
//   for(int i=0;i<4;++i){
//     cout<<country_pi_settings[i]<<" , ";
//   }
//   cout<<"}"<<endl;
//   cout<<endl;
//
//   cout<<"infection_factor: "<<infection_factor<<endl;
//   cout<<endl;
//
//
//   cout<<"action cards: "<<"(Max: "<<ac_size<<" : no. "<<ac_num<<")"<<endl;
//   for(int i=0;i<ac_size;++i){
//     cout<<i<<" : "<<ac[i]<<endl;
//   }
//   cout<<endl;
//
//   cout<<"random event cards: "<<"(Max: "<<rec_size<<" : no. "<<rec_num<<")"<<endl;
//   for(int i=0;i<rec_size;++i){
//     cout<<i<<" : "<<rec[i]<<endl;
//   }
//   cout<<endl;
//
//   cout<<"deck: "<<endl;
//   printlist(dh);
//   cout<<endl;
//
//   cout<<"trash: "<<endl;
//   printlist(th);
//   cout<<endl;
//
//   printruler();
// }

// void printeverything002(int day, WHO who, int no_of_country, country c[],
//   int init_death_probability, int init_recover_probability, float country_pi_settings[], float infection_factor,
//   string ac[], int ac_size, int ac_num,
//   string rec[], int rec_size, int rec_num,
//   Node * & dh, Node * & dt, Node * & th, Node * & tt)
// {
//
//   printruler();
//
//   cout<<"Day: "<<day<<endl;
//   cout<<endl;
//
//   cout<<"WHO: "<<endl;
//   cout<<"capital: "<<who.capital<<endl;
//   cout<<"staff: "<<who.staff<<endl;
//   cout<<"medical: "<<who.medical<<endl;
//   cout<<"capital_income: "<<who.capital_income<<endl;
//   cout<<"staff_increment: "<<who.staff_increment<<endl;
//   cout<<"medical_increment: "<<who.medical_increment<<endl;
//   cout<<"income_frequency: "<<who.income_frequency<<endl;
//   cout<<endl;
//
//   // printnewcountry(c,no_of_country);
//   cout<<endl;
//
//   cout<<"init_death_probability: "<<init_death_probability<<endl;
//   cout<<endl;
//
//   cout<<"init_recover_probability: "<<init_recover_probability<<endl;
//   cout<<endl;
//
//   cout<<"country_pi_settings: "<<endl;
//   cout<<"{";
//   for(int i=0;i<4;++i){
//     cout<<country_pi_settings[i]<<" , ";
//   }
//   cout<<"}"<<endl;
//   cout<<endl;
//
//   cout<<"infection_factor: "<<infection_factor<<endl;
//   cout<<endl;
//
//
//   cout<<"action cards: "<<"(Max: "<<ac_size<<" : no. "<<ac_num<<")"<<endl;
//   for(int i=0;i<ac_size;++i){
//     cout<<i<<" : "<<ac[i]<<endl;
//   }
//   cout<<endl;
//
//   cout<<"random event cards: "<<"(Max: "<<rec_size<<" : no. "<<rec_num<<")"<<endl;
//   for(int i=0;i<rec_size;++i){
//     cout<<i<<" : "<<rec[i]<<endl;
//   }
//   cout<<endl;
//
//   cout<<"deck: "<<endl;
//   printlist(dh);
//   cout<<endl;
//
//   cout<<"trash: "<<endl;
//   printlist(th);
//   cout<<endl;
//
//   printruler();
// }

//--------------------for debug-------------------------------------------


int main(){
  clearscreen();
  printmainmenu();

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
  int action_card_size=100;
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


  //   printeverything002(day,who,number_of_countries,AllCountries,
  //     init_death_probability,init_recover_probability,country_pi_settings,infection_factor,
  //     action_card,action_card_size,number_of_action_card,
  //     random_event_card,random_event_card_size,number_of_random_event_card,
  //     deck_head,deck_tail,trash_head,trash_tail);

  //---------------------------the game ----------------------------------
  bool exit=false;
  bool win = false;
  bool loose = false;
  float winning_pi = 80;
  float loosing_pi = 30;

  float overall_pi = calculate_overall_performance_index(AllCountries,number_of_countries,country_pi_settings);
  // Start loop of the day.
  while ((!win) && (!loose) && (exit==false)){
    overall_pi = calculate_overall_performance_index(AllCountries,number_of_countries,country_pi_settings);
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
      printmaingamescreen(overall_pi, day, who, AllCountries, number_of_countries);
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
        clearscreen();
        //-------------user input-------------
        if (answer=="Y"){
          //user really want to exit the game
          //-------------user input-------------
          clearscreen();
          cout<<"Save game? (Y/N)"<<endl;
          answer="a";
          while ((answer!="Y")&&(answer!="N")){
            cout<<"Input: ";
            cin>>answer;
            if ((answer!="Y")&&(answer!="N")){
              cout<<"Invalid input!"<<endl;
            }
          }
          clearscreen();
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
        while (answer != "0")
        {
          clearscreen();
          printruler();
          //printing all country in detail way
          //----------------print table----------------
          printcountry(AllCountries, str_to_int(answer) - 1, number_of_countries);
          printruler();
          //----------------print table----------------

          cout << endl;
          cout << " Enter the number of the Country to see detail information" << endl;
          cout << " Enter 0 to Exit" << endl;
          printruler();
          answer = get_user_input(number_of_countries);
        }
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
            card temp1card[2];
            if (card_command(temp5card[str_to_int(answer)-5],temp1card[0])){
              temp1card[0].cost = 0;
              if (use_action_card(temp1card[0], who.capital, who.staff, who.medical, AllCountries, number_of_countries)) {
                action = true;
                clearscreen();
                cout << endl;
                cout << " Card Selected" << endl;
                printruler();
                printcard(temp1card[0]);
                cout << "Moving card to trash" << endl;
                insertlist(trash_head, trash_tail, temp5card[str_to_int(answer)-5]);
              }
              else
              {
                cout << "Use card error" << endl;
              }
            }
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
        // action card
        clearscreen();
        bool used_action_card = false;
        string a[3];
        pop3(deck_head,trash_head,a);

        //3 cards store in array of string a in string format
        card a3[3];
        printgamescreenheader(overall_pi, day, who, number_of_countries);
        cout << "Please choose an Action card..." << endl;
        printruler();
        for (int i=0;i<3;++i){
           if (card_command(a[i],a3[i])==true){
             cout << " Card " << i+1 << endl;
             printcard(a3[i]);
             cout<<endl;
           }
           else{
             cout<<"error in read card"<<endl;
           }
         }

        //---------------user choose---------------
        cout << "\nPlease enter 1, 2 or 3 to select a card..." << endl;
        cout << "To Exit, enter 0" << endl;
        printruler();
        answer = get_user_input(3);
        if (answer != "0") {
          //---------------user choose---------------
          //---------------effect---------------
          clearscreen();
          if (!(use_action_card(a3[str_to_int(answer) - 1], who.capital, who.staff, who.medical, AllCountries, number_of_countries))) {

            while (!used_action_card) {
              clearscreen();
              cout << "Please choose an Action card..." << endl;
              printruler();
              for (int i=0;i<3;++i){
                 if (card_command(a[i],a3[i])==true){
                   cout << " Card " << i+1 << endl;
                   printcard(a3[i]);
                   cout<<endl;
                 }
                 else{
                   cout<<"error in read card"<<endl;
                 }
               }
              cout << "Please choose another card." << endl;
              cout << "\nPlease enter 1/2/3 to select a card..." << endl;
              printruler();
              answer = get_user_input(3);
              if ((use_action_card(a3[str_to_int(answer) - 1], who.capital, who.staff, who.medical, AllCountries, number_of_countries))) {
                used_action_card = true;
                printusecardresult(a3[str_to_int(answer) - 1]);
              }
            }
          }
          else if ( answer != "0" )
          {
            action=true;
            printusecardresult(a3[str_to_int(answer) - 1]);
            cout << "Enter to continue to the Random Effect Card of the day" << endl;
          }
        }
        //---------------effect---------------
      }

      // Process random event card if player did not exit the game
      if (!exit && action) {
        cin.ignore();
        cout << endl;
        printruler();
        pressentertocontinue();
        clearscreen();
        //finish one day by using one action card
        //-------------------------random event card-------------------------------
        card tempcard;
        if (!(card_command(random_event_card[rand()%number_of_random_event_card],tempcard))){
          cout<<"Error in reading random event card"<<endl;
        }
        if (use_random_card(tempcard, who.capital, who.staff, who.medical, AllCountries, number_of_countries)) {
          printruler();
          cout << "Random card of the day is:" << endl << endl;
          cout << "Card Name: " << tempcard.name << endl;
          cout << "Card Effects: ";
          if (tempcard.add) {
            cout << tempcard.variable << " will increase by " << tempcard.magnitude << " for " << tempcard.target<< endl;
          }
          else
          {
            cout << tempcard.variable << " will decrease by " << tempcard.magnitude << " for " << tempcard.target<< endl;
          }
          printruler();
        }
        else
        {
          cout << "Random card error..." << endl;

          if (tempcard.add) {
            cout << tempcard.variable << " will increase by " << tempcard.magnitude << " for " << tempcard.target<< endl;
          }
          else
          {
            cout << tempcard.variable << " will decrease by " << tempcard.magnitude << " for " << tempcard.target<< endl;
          }

        }
        pressentertocontinue();
      }

    }

    //-------------------------random event card-------------------------------

    delete [] temp5card;

    //-------------------------Update Game Status-------------------------------
    daily_resources_income(who, day, who.capital, who.staff, who.medical, overall_pi);
    calculate_daily_infection(AllCountries, number_of_countries);
    calculate_daily_economic_impact(AllCountries, number_of_countries, lockdown_economy_threshold);
    overall_pi = calculate_overall_performance_index(AllCountries,number_of_countries,country_pi_settings);
    //-------------------------Update Game Status-------------------------------

    //-------------------------Check if player won-------------------------------
    if ( (overall_pi > winning_pi) && day > 10 ) {
      win = true;
    }
    if ( (overall_pi < loosing_pi) && day > 10 ) {
      loose = true;
    }
    //-------------------------Check if player won-------------------------------

    // End loop of the day
  }

  //won and finished the game
  if (win==true){
    //exit == false means the user out the loop because he win the game
    printwingamescreen();
    //as PI over the graduation mark
    ifstream infile(store_game);
    if (infile.good()) {
    string command="rm "+store_game;
    system(command.c_str());
  }
  //remove the stored game status if exist because user had win the game
}
  else if (loose==true){
    //exit == false means the user out the loop because he win the game
    printloosegamescreen();
    //as PI over the graduation mark
    ifstream infile(store_game);
    if (infile.good()) {
      string command="rm "+store_game;
      system(command.c_str());
    }
    //remove the stored game status if exist because user had lost the game
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
