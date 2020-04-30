#include "performance_index.h"


void calculate_performance_by_country(struct country AllCountries[], float country_pi_settings[], int country_count)
{
  for (int i=0;i<country_count;i++)
  {
    // std::cout << "Error Check" << '\n';
    AllCountries[i].pi = AllCountries[i].deaths / AllCountries[i].population * country_pi_settings[0];
    AllCountries[i].pi += ( AllCountries[i].infections - AllCountries[i].deaths - AllCountries[i].recovered ) / AllCountries[i].population * country_pi_settings[1];
    AllCountries[i].pi += AllCountries[i].recovered / AllCountries[i].population * country_pi_settings[2];
    AllCountries[i].pi += AllCountries[i].economy * country_pi_settings[3];

    // std::cout << AllCountries[i].name << " has a pi of " << AllCountries[i].pi <<'\n';
  }
}

float calculate_overall_performance_index(struct country AllCountries[], float country_pi_settings[], int country_count)
{
  double overall_pi=0;
  double average_pi=0;

  calculate_performance_by_country(AllCountries, country_pi_settings, country_count);
  long long int total_population = 0;
  for (int i=0;i<country_count;i++)
  {
    total_population += AllCountries[i].population;
  }
  for (int i=0;i<country_count;i++)
  {
    overall_pi += AllCountries[i].pi * AllCountries[i].population / total_population;
    // For checking:
    // overall_pi += 100 * AllCountries[i].population / total_population;
  }
  for (int i=0;i<country_count;i++)
  {
    average_pi += AllCountries[i].pi / 20;
  }

  // std::cout << "\noverall pi is : " << overall_pi << '\n';
  // std::cout << "average pi is : " << average_pi << '\n';
  return (float)overall_pi;
}
