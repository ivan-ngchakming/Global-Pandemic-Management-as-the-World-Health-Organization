#include <string>
#include <iostream>
using namespace std;

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

double str_to_double(string s){
  if (is_digits(s)){
    //turn string to double
    double temp=stod(s);
    return temp;
  }
  exit(1);
}

//----------------- break down the country command------------------------------
//command format
//<country name>,<population>,<infection>,<deaths>,<recovered>,<economy>,<pi>
bool country_command(string command, string & country_name, double & population, double & infection, double & deaths, double & recovered, double & economy, double & pi){
  int pos=0;
  string temp;
  int next_pos=command.find(",");
  country_name=command.substr(pos,next_pos);
  //extract country_name
  cout<<"country_name: "<<country_name<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  population=str_to_double(temp);
  //extract population
  cout<<"population: "<<population<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  infection=str_to_double(temp);
  //extract infection
  cout<<"infection: "<<infection<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  deaths=str_to_double(temp);
  //extract deaths
  cout<<"deaths: "<<deaths<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  recovered=str_to_double(temp);
  //extract recovered
  cout<<"recovered: "<<recovered<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  economy=str_to_double(temp);
  //extract economy
  cout<<"economy: "<<economy<<endl;

  pos=next_pos;
  temp=command.substr(pos+1);
  pi=str_to_double(temp);
  //extract pi
  cout<<"pi: "<<pi<<endl;

  return true;
  //means the function runs smoothly
}



//------------------------ break down the card command------------------------------
//command format
//<card name>,<target name>,<variable>,<true/false>,<magnitude>
//if the target is not country, variable will store garbage value
bool card_command(string command, string & card_name, string & target_name, string & variable, bool & add, double & magnitude){
  int pos=0;
  string temp;
  int next_pos=command.find(",");
  card_name=command.substr(pos,next_pos);
  //extract card_name
  pos=next_pos;
  next_pos=command.find(",",pos+1);
  target_name=command.substr(pos+1,next_pos-pos-1);
  //extract target_name
  cout<<"target_name: "<<target_name<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  variable=command.substr(pos+1,next_pos-pos-1);
  //extract variable
  cout<<"variable: "<<variable<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  if ((temp=="true")||(temp=="false")){
    if (temp=="true"){
      add=true;
    }
    else{
      add=false;
    }
  }
  else{
    return false;
    //which means have error
  }
  //extract add (true means add / false means minus)
  cout<<"add: "<<add<<endl;

  pos=next_pos;
  temp=command.substr(pos+1);
  magnitude=str_to_double(temp);
  //extract magnitude
  cout<<"magnitude: "<<magnitude<<endl;

  return true;
  //means the function runs smoothly
}
