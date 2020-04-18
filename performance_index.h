#ifndef PERFORMANCE_INDEX_H
#define PERFORMANCE_INDEX_H
#include <string>

struct country
{
  std::string name;
  int population;
  int infections;
  int deaths;
  int recovered;
};

float calculate_overall_performance_index(float pi_by_country[], struct country AllCountries[]);


#endif
