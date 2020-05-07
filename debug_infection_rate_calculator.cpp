#include <iostream>
using namespace std;

#include "infection_rate_calculator.h"

struct country
{
  string name;
  unsigned long int population;
  unsigned long int infections;
  unsigned int deaths;
  unsigned int recovered;
  float infected_percentage;
  double economy;
  double pi; //pi: performance index
  float infection_factor; // Range 0.0 - 5.0
  unsigned long int infection_increase;
  int death_probability; // Range 0 - 100
  int recover_probability; // Range 0 - 100
};
//for storing the data for a country


int main(){
  int day;
  cout<<"no of day: ";
  cin>>day;
  int no_of_country;
  cout<<"no of country: ";
  cin>>no_of_country;
  country * a = new country[no_of_country];
  for (int i=0;i<no_of_country;++i){
    cin>>a[i].name>>a[i].population>>a[i].infections>>a[i].deaths>>a[i].recovered>>
    a[i].infected_percentage>>a[i].economy>>a[i].pi>>a[i].infection_factor>>
    a[i].infection_increase>>a[i].death_probability>>a[i].recover_probability;
  }


  for (int j=0;j<=day;++j){
    for (int i=0;i<no_of_country;++i){
      cout<<j<<"th day:"<<endl;
      cout<<a[i].name<<","<<a[i].population<<","<<a[i].infections<<","<<
      a[i].deaths<<","<<a[i].recovered<<","<<a[i].infected_percentage<<
      ","<<a[i].economy<<","<<a[i].pi<<","<<a[i].infection_factor<<","<<
      a[i].infection_increase<<","<<a[i].death_probability<<","<<a[i].recover_probability<<endl;
    }
    calculate_daily_infection(a,no_of_country);
  }
  delete [] a;
  return 0;
}
