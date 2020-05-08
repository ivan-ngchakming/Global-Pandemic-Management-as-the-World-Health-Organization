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
  // cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
  cin.ignore();
}

void printruler(){
  cout<<"---------------------------------------------------------------"<<endl;
  //synchronized every ruller have the same length
}

void printcountry(country c[], int index, int no_of_c){
  int width = 20;
  int name_width = 25;
  int i = index;
  int j = 0;
  cout << "Detail Country Statistics: " << endl;
  printruler();
  cout << endl;
  cout << setw(name_width) << " Country: " << setw(width) << c[i].name << setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  cout << setw(name_width) << " Population: " << setw(width) << c[i].population << setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  cout << setw(name_width) << " Infections: " << setw(width) << c[i].infections << setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  cout << setw(name_width) << " Deaths: " << setw(width) <<c[i].deaths<<setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  cout << setw(name_width) << " Recovered: " << setw(width) <<c[i].recovered<<setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  cout << setw(name_width) << " Infected %: " << setw(width);
  printf("%.2f%%               ", c[i].infected_percentage);
  cout <<setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  cout << setw(name_width) << " Economy: " << setw(width) <<c[i].economy<<setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  cout << setw(name_width) << " Performance Index: " << setw(width) <<c[i].pi<<setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  cout << setw(name_width) << " Infection factor: " << setw(width) <<c[i].infection_factor<<setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  cout << setw(name_width) << " Infection increase: " << setw(width) <<c[i].infection_increase<<setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  cout << setw(name_width) << " Death probability(%): "  << setw(width) << c[i].death_probability<<setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  cout << setw(name_width) << " Recover probability(%): " << setw(width) <<c[i].recover_probability<<setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  j++;
  for (j;j<no_of_c;j++) {
    cout << setw(name_width + width) << " " << setw(2) << " | " << j + 1 <<" - " << c[j].name << endl;
  }
  cout << endl;

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


void printusecardresult(card c){
  clearscreen();
  cout << endl;
  cout << " Card Selected" << endl;
  printruler();
  cout << endl;
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
  cout << endl;
  printruler();
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
  cout<<setw(20) << "Country" << setw(9) << "PI" << setw(12) << "Infections"  << setw(12) << "Deaths" << setw(18) << "infected %" << endl;
  for (int i=0;i<number_of_countries;++i){
    cout<<setw(20)<<AllCountries[i].name;
    printf("%.2f    ", AllCountries[i].pi);
    cout<<setw(12)<<AllCountries[i].infections;
    cout<<setw(12)<<AllCountries[i].deaths;
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
