#include <iostream>
using namespace std;

#include "main.h"
#include "performance_index.h"

int main(){
  float country_pi_settings[4]={0.4,0.1,0.1,0.3};
  cout<<"country_pi_settings: ";
  cin>>country_pi_settings[0]>>country_pi_settings[1]>>country_pi_settings[2]>>country_pi_settings[3];

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

  cout<<"your input:"<<endl;
  for (int i=0;i<no_of_country;++i){
    cout<<i<<":"<<endl;
    cout<<a[i].name<<","<<a[i].population<<","<<a[i].infections<<","<<
    a[i].deaths<<","<<a[i].recovered<<","<<a[i].infected_percentage<<
    ","<<a[i].economy<<","<<a[i].pi<<","<<a[i].infection_factor<<","<<
    a[i].infection_increase<<","<<a[i].death_probability<<","<<a[i].recover_probability<<endl;
    cout<<endl;
  }
  cout<<"------------------------------------------------------------------------"<<endl;

  for (int j=0;j<=day;++j){
    cout<<j<<"th day:"<<endl;
    cout<<endl;
    for (int i=0;i<no_of_country;++i){
      cout<<i<<":"<<endl;
      cout<<a[i].name<<","<<a[i].population<<","<<a[i].infections<<","<<
      a[i].deaths<<","<<a[i].recovered<<","<<a[i].infected_percentage<<
      ","<<a[i].economy<<","<<a[i].pi<<","<<a[i].infection_factor<<","<<
      a[i].infection_increase<<","<<a[i].death_probability<<","<<a[i].recover_probability<<endl;
      cout<<endl;
    }
    cout<<calculate_overall_performance_index(a,no_of_country,country_pi_settings)<<endl;
    cout<<"------------------------------------------------------------\n";
  }
  delete [] a;
  return 0;
}
