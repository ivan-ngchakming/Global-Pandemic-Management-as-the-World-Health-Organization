#include <iostream>
#include <string>
using namespace std;

#include "main.h"
#include "command.h"

int main(){
  string command;
  cin>>command;
  cout<<"The command is: "<<command;
  cout<<endl;
  country  c;
  bool success=country_command(command,c);
  printcounrty(c);
  cout<<"success: "<<boolalpha<<success<<endl;

  printruler();

  cin>>command;
  cout<<endl;
  card  d;
  success=card_command(command,d);
  printcard(d);
  cout<<"success: "<<boolalpha<<success<<endl;

  return 0;

}
