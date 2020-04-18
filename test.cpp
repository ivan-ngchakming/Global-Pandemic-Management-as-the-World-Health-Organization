#include <iostream>

#include "load_init_countries_statistics.h"
#include "performance_index.h"

int main()
{
  struct country AllCountries[20];
  float pi_by_country[20];
  load_countries_statistics(AllCountries);

  // For debugging.
  for (int i=0;i<20;i++)
    std::cout << AllCountries[i].name << ", pop: " << AllCountries[i].population << '\n';

  std:: cout << calculate_overall_performance_index(pi_by_country, AllCountries) << '\n';
  return 0;
}
