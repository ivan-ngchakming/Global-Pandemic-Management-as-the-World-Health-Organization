#include <string>
#include <iostream>
using namespace std;

#include "main.h"
#include "command.h"

//----------------- break down the country command------------------------------
//command format
//<country name>,<population>,<infection>,<deaths>,<recovered>,<economy>,<pi>
bool country_command(string command, country & c ){
  int pos=0;
  string temp;
  int next_pos=command.find(",");
  c.name=command.substr(pos,next_pos);
  //extract country name

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.population=str_to_double(temp);
  //extract population

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.infections=str_to_double(temp);
  //extract infection

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.deaths=str_to_double(temp);
  //extract deaths

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.recovered=str_to_double(temp);
  //extract recovered

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.economy=str_to_double(temp);
  //extract economy

  pos=next_pos;
  next_pos=command.find(",",pos+1);
  temp=command.substr(pos+1,next_pos-pos-1);
  c.pi=str_to_double(temp);
  //extract pi

  pos=next_pos;
  temp=command.substr(pos+1);
  c.infection_factor=str_to_double(temp);
  //extract infection_factor

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
  c.target=command.substr(pos+1,next_pos-pos-1);
  //extract target

  pos=next_pos;cout<<"target: "<<c.target<<endl;
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
  temp=command.substr(pos+1);
  c.magnitude=str_to_double(temp);
  //extract magnitude

  return true;
  //means the function runs smoothly
}
