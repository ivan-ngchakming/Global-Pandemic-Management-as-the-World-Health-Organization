#include <iostream>
#include <string>
using namespace std;

#include "command.h"

string doubletostr(double num){
  return to_string(num);
}

int main(){
  string country_name;
  double population;
  double infection;
  double death;
  double recovered;
  double economy;
  double pi;

  string card_name;
  string target_name;
  string variable;
  bool add;
  double magnitude;

  string command;
  cin>>command;
  cout<<"The command is: "<<command;
  bool success=country_command(command,country_name,population,infection,death,recovered,economy,pi);
  cout<<country_name<<" "<<to_string(population)<<" "<<to_string(infection)<<" "<<to_string(death)<<" "<<to_string(recovered)<<" "<<to_string(economy)<<" "<<to_string(pi)<<endl;
  cout<<"bool: "<<boolalpha<<success<<endl;
  cin>>command;
  success=card_command(command,card_name,target_name,variable,add,magnitude);
  cout<<card_name<<" "<<target_name<<" "<<variable<<" "<<boolalpha<<add<<" "<<to_string(magnitude)<<endl;
  cout<<"bool: "<<success<<endl;
  return 0;
}
