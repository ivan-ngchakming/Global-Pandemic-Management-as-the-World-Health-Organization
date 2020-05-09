#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

#include "main.h"

//----------------- break down the country command------------------------------
//command format
//<country name>,<population>,<infection>,<deaths>,<recovered>,<economy>,<pi>
bool country_command(string command, country & c ){
  int pos=0;
  string temp;
  int next_pos=command.find(",");
  c.name=command.substr(pos,next_pos);
  //extract country name

  //cout<<c.name<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.population=STRtoULI(temp);
  //extract population

  //cout<<c.population<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.infections=STRtoULI(temp);
  //extract infections

  //cout<<c.infections<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.deaths=STRtoULI(temp);
  //extract deaths

  //cout<<c.deaths<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.recovered=STRtoULI(temp);
  //extract recovered

  //cout<<c.recovered<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.infected_percentage=str_to_float(temp);
  //extract infected_percentage

  //cout<<c.infected_percentage<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.economy=str_to_double(temp);
  //extract economy

  //cout<<c.economy<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.pi=str_to_double(temp);
  //extract pi

  //cout<<c.pi<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.infection_factor=str_to_float(temp);
  //extract infection_factor

  //cout<<c.infection_factor<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.infection_increase=STRtoULI(temp);
  //extract infection_increase

  //cout<<c.infection_increase<<endl;

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.death_probability=str_to_int(temp);
  //extract death_probability

  //cout<<c.death_probability<<endl;

  pos=next_pos;
  temp=command.substr(pos+1);
  c.recover_probability=str_to_int(temp);
  //extract recover_probability

  //cout<<c.recover_probability<<endl;

  return true;
  //means the function runs smoothly
}



//------------------------ break down the card command------------------------------
//command format:
//<card name>,<target name>,<variable>,<true/false>,<magnitude>
//if the target is not country, variable will store garbage value
bool card_command(string command, card & c){
  int pos=0;
  string temp;
  int next_pos=command.find(",");
  c.name=command.substr(pos,next_pos);
  //extract c.name

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  c.target_type=command.substr(pos+1,next_pos-pos-1);
  //extract target_type

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  c.target=command.substr(pos+1,next_pos-pos-1);
  //extract target

  pos=next_pos;  // cout<<"target: "<<c.target<<endl;
  next_pos=command.find(",",pos+1);
  c.variable=command.substr(pos+1,next_pos-pos-1);
  //extract variable

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  if ((temp=="true")||(temp=="false")){
    if (temp=="true"){
      c.add=true;
    }
    else{
      c.add=false;
    }
  }
  else{
    return false;
    //which means have error
  }
  //extract add (true means add / false means minus)

  pos=next_pos;
  // cout<<"target: "<<c.target<<endl;
  next_pos=command.find(",",pos+1);
  c.magnitude=str_to_double(command.substr(pos+1,next_pos-pos-1));
  //extract magnitude

  pos=next_pos;  // cout<<"target: "<<c.target<<endl;
  next_pos=command.find(",",pos+1);
  c.cost_type=command.substr(pos+1,next_pos-pos-1);
  //extract cost_type

  pos=next_pos;
  temp=command.substr(pos+1);
  c.cost=str_to_int(temp);
  //extract cost

  return true;
  //means the function runs smoothly
}

//----------------- break down the WHO command------------------------------
//command format
//<capital>,<staff>,<medical>
bool who_command(string command, WHO & w ){
  int pos=0;
  string temp;
  int next_pos=command.find(",");
  temp=command.substr(pos,next_pos);
  w.capital=str_to_int(temp);
  //extract capital

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  w.staff=str_to_int(temp);
  //extract staff

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  w.medical=str_to_int(temp);
  //extract medical

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  w.capital_income=str_to_int(temp);
  //extract capital_income

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  w.staff_increment=str_to_int(temp);
  //extract staff_increment

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  w.medical_increment=str_to_int(temp);
  //extract medical_increment


  pos=next_pos;
  temp=command.substr(pos+1);
  w.income_frequency=str_to_int(temp);
  //extract income_frequency

  return true;
  //means the function runs smoothly
}

//----------------- break down the country_pi_settings command------------------------------
//command format
//<a>,<b>,<c>,<d>
bool country_pi_settings_command(string command, float a[] ){
  int pos=0;
  string temp;

  int next_pos=command.find(",");
  temp=command.substr(pos,next_pos);
  a[0]=str_to_float(temp);

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  a[1]=str_to_float(temp);

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  a[2]=str_to_float(temp);

  pos=next_pos;
  temp=command.substr(pos+1);
  a[3]=str_to_float(temp);

  return true;
  //means the function runs smoothly
}
