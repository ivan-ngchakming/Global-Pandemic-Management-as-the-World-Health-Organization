#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

#include "001main.h"
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
