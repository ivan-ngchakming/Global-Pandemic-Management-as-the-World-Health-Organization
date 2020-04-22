#ifndef PERFORMANCE_INDEX_H
#define PERFORMANCE_INDEX_H
#include <string>
#include <iostream>

struct country
{
  std::string name;
  double population;
  double infections;
  double deaths;
  double recovered;
  double economy;
  double pi;
};


float calculate_overall_performance_index(struct country AllCountries[]);

#endif
