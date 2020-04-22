#include <iostream>

#include "load_init_countries_statistics.h"
#include "performance_index.h"
#include "infection_rate_calculator.h"



int main()
{
  struct country AllCountries[20];
  float pi_by_country[20];
  load_countries_statistics(AllCountries);

  std:: cout << "Calculating all countries' PI..." << '\n';
  std:: cout << calculate_overall_performance_index(AllCountries) << '\n';


  for(int i=0;i<5;i++)
  calculate_daily_infection(AllCountries);

  return 0;
}
