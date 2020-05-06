#include "ui.h"

#include <cstdlib>

// void printruler(int length)
// {
//   for (int i=0;i<length;i++) {
//     cout << "-";
//   }
//   cout << endl;
//   //synchronized every ruller have the same length
// }

void clearscreen(){
  system("clear");
}

void printruler(){
  cout<<"---------------------------------------------------------------"<<endl;
  //synchronized every ruller have the same length
}

void printnewcountry(country c[], int no_of_country){
  cout<<"no. of country: "<<no_of_country<<endl;
  cout<<"Country: "<<endl;
  for(int i=0;i<no_of_country;++i){
    cout<<i+1<<":\n";
    cout<<"Name: "<<c[i].name<<endl;
    cout<<"Population: "<<c[i].population<<endl;
    cout<<"Infections: "<<c[i].infections<<endl;
    cout<<"Deaths: "<<c[i].deaths<<endl;
    cout<<"Recovered: "<<c[i].recovered<<endl;
    cout<<"Infected_percentage: "<<c[i].infected_percentage<<endl;
    cout<<"Economy: "<<c[i].economy<<endl;
    cout<<"Pi: "<<c[i].pi<<endl;
    cout<<"Infection_factor: "<<c[i].infection_factor<<endl;
    cout<<"Infection_increase: "<<c[i].infection_increase<<endl;
    cout<<"Death_probability: "<<c[i].death_probability<<endl;
    cout<<"Recover_probability: "<<c[i].recover_probability<<endl;
    cout<<endl;
  }
}

void printcard(card c){
  cout<<"Name: "<<c.name;
  cout<<"Target_type: "<<c.target_type;
  cout<<"Target: "<<c.target;
  cout<<"Variable: "<<c.variable;

  cout<<"Add: "<<boolalpha<<c.add;
  cout<<"Magnitude: "<<c.magnitude;
  cout<<"Cost_type: "<<c.cost_type;
  cout<<"Cost: "<<c.cost;
}

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

string get_user_input(int choices)
{
  string answer="-1";
  bool flag = false;
    while (!flag)
    {
      cout << endl;
      cout << "Input: ";
      cin>>answer;
      for (int i = 0; i < choices+1; i++)
      {
        if (answer == to_string(i))
          flag = true;
      }
      if (!flag) {
        cout<<"Invalid input!"<<endl;
      }
    }
    return answer;
}
