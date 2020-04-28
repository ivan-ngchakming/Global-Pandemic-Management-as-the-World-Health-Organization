#include <iostream>

#include "load_init_countries_statistics.h"
#include "performance_index.h"
#include "infection_rate_calculator.h"
#include "main.h"

using namespace std;

int main()
{
  struct country AllCountries[20];
  int number_of_countries;
  int init_death_probability = 1;
  int init_recover_probability = 3;
  float country_pi_settings[4] = {0.4, 0.1, 0.1, 0.3};
  float infection_factor = 0.7;

  load_countries_statistics(AllCountries, init_death_probability,
    number_of_countries, infection_factor, init_recover_probability);

  cout << "Calculating all countries' PI..." << '\n';
  cout << calculate_overall_performance_index(AllCountries, country_pi_settings, number_of_countries) << '\n';

  cout << number_of_countries << '\n';

  for(int i=0;i<20;i++)
  {
    cout << "\nDAY " << i << '\n';
    calculate_daily_infection(AllCountries, number_of_countries);
    // cout << "Press Enter to continue";
    // cin.ignore();
  }

  return 0;
}
