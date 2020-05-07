#include "ui.h"

#include <cstdlib>
#include <iomanip>
#include <limits>

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

void pressentertocontinue()
{
  cout << "Press Enter to Continue";
  cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
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
  cout << " Card Name: " << c.name << endl;
  cout << " Card Affect: ";
  if (c.add) {
    cout << c.variable << " will increase by " << c.magnitude << " for " << c.target<< endl;
  }
  else
  {
    cout << c.variable << " will decrease by " << c.magnitude << " for " << c.target<< endl;
  }
  if (c.cost_type == "capital") {
    cout << " Card Cost: $" << c.cost << endl;
  }
  else if (c.cost_type == "staff") {
    cout << " Card Cost: " << c.cost << " staff" << endl;
  }
  else
  {
    cout << " Card Cost: " << c.cost << " medical equipment" << endl;
  }
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
  if (choices != -1) {
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
  else
  {
    string answer="-1";
    cout << endl;
    cout << "Input: ";
    cin >> answer;
    return answer;
  }

}

void printmainmenu()
{
  clearscreen();
  printruler();
  cout << endl << endl << endl;
  cout << "WELCOME TO" << endl;
  cout << "Global Pandemic Management as the World Health Organization" << endl;
  cout << "The GAME" << endl;
  cout << endl << endl << endl;
  printruler();
  pressentertocontinue();
}

void printgamescreenheader(float overall_pi, int day, struct WHO who, int number_of_countries)
{
  printruler();
  cout<<left;
  cout << " Overall Performance Index: " << overall_pi << endl;
  printruler();
  who.income_frequency = 7; // Temperary for debug
  cout << " Days left until the next resources income arrive: " << who.income_frequency - day % who.income_frequency << endl;
  cout << " Capital: " << who.capital << " | Staff: " << who.staff << " | Medical Equipment: " << who.medical << endl;
  printruler();
}

void printsimplecountrystat(struct country AllCountries[], int number_of_countries)
{
  //----------printing all country statistic in simple way----------
  cout<<setw(20) << "Country" << setw(10)<<"PI"<< setw(18) << "Infections" << setw(18) << "infected %" << endl;
  for (int i=0;i<number_of_countries;++i){
    cout<<setw(20)<<AllCountries[i].name;
    printf("%.2f     ", AllCountries[i].pi);
    cout<<setw(18)<<AllCountries[i].infections;
    printf("%.2f", AllCountries[i].infected_percentage);
    // cout<<setw(18)<<AllCountries[i].infected_percentage;
    cout<<endl;
  }
  printruler();
  //----------printing all country statistic in simple way----------
}

void printmaingamescreen(float overall_pi, int day, struct WHO who, struct country AllCountries[], int number_of_countries)
{
  printgamescreenheader(overall_pi, day, who, number_of_countries);
  printsimplecountrystat(AllCountries, number_of_countries);
  //------------------------------menu------------------------------
  cout<<endl;
  cout<<"Day: "<< day << endl;
  cout<<"1: View statistics of all Countries"<<endl;
  cout<<"2: View market"<<endl;
  cout<<"3: Use Action card"<<endl;
  cout<<"0: Exit game"<<endl;
  printruler();
}

void printwingamescreen()
{
  cout << "Congratulations! You have won!" << endl;
}
