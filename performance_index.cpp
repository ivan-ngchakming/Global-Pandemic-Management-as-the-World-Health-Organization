#include "performance_index.h"


void calculate_performance_by_country(struct country AllCountries[])
{
  float country_pi_settings[4] = {0.4, 0.1, 0.1, 0.3};
  for (int i=0;i<20;i++)
  {
    AllCountries[i].pi = AllCountries[i].deaths * country_pi_settings[0];
    AllCountries[i].pi += AllCountries[i].infections * country_pi_settings[1];
    AllCountries[i].pi += AllCountries[i].recovered * country_pi_settings[2];
    AllCountries[i].pi += AllCountries[i].economy* country_pi_settings[3];
  }
}

float calculate_overall_performance_index(struct country AllCountries[])
{
  double overall_pi=0;

  calculate_performance_by_country(AllCountries);
  long total_population = 0;
  for (int i=0;i<20;i++)
  {
    overall_pi += AllCountries[i].pi * AllCountries[i].population;
    total_population += AllCountries[i].population;
  }
  return (float)overall_pi;
}
