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
  int economy;
  int pi;
};

void calculate_performance_by_country(struct country AllCountries[]);
float calculate_overall_performance_index(struct country AllCountries[]);

#endif
