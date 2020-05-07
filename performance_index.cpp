#include <string>
#include <iostream>
using namespace std;

#include "main.h"

void calculate_performance_by_country(country AllCountries[],int number_of_countries, float country_pi_settings[])
{
  for (int i=0;i<number_of_countries;i++)
  {
    cout<<"debug001: "<<i<<endl;
    cout << AllCountries[i].name << ": " << '\n';
    AllCountries[i].pi = 0;
    AllCountries[i].pi += (double) ( ( 100 - ( AllCountries[i].infections - AllCountries[i].deaths - AllCountries[i].recovered ) / AllCountries[i].population * 100 ) * country_pi_settings[1] );
    cout << "Adding infections of  " <<  ( 100 - ( AllCountries[i].infections - AllCountries[i].deaths - AllCountries[i].recovered ) / AllCountries[i].population * 100 ) << " to " << AllCountries[i].pi << '\n';
    AllCountries[i].pi += (double) ( 100 - ( AllCountries[i].infections / AllCountries[i].population * 100 ) * country_pi_settings[1] );
    cout << "Adding infections of  " <<  ( 100 - AllCountries[i].infections  / AllCountries[i].population * 100 ) << " to " << AllCountries[i].pi << '\n';
    cout << "Infections: " << AllCountries[i].infections << endl;
    cout << "deaths: " << AllCountries[i].deaths << endl;
    cout << "recovered: " << AllCountries[i].recovered << endl;
    cout << "population: " << AllCountries[i].population << endl;



    if (AllCountries[i].infections != 0 ) {
      AllCountries[i].pi += (double) (AllCountries[i].recovered / AllCountries[i].infections * country_pi_settings[2]);
      cout << "Adding recovered of " << AllCountries[i].recovered / AllCountries[i].infections << " to " << AllCountries[i].pi << '\n';
      AllCountries[i].pi += (double) ( (100 - AllCountries[i].deaths / AllCountries[i].infections) * country_pi_settings[0]);
      cout << "Adding deaths of  " << (100 - AllCountries[i].deaths / AllCountries[i].infections) << " to " <<  AllCountries[i].pi << '\n';
    }
    else
    {
      AllCountries[i].pi += (double) ( 100 * country_pi_settings[2]);
      AllCountries[i].pi += (double) ( 100 * country_pi_settings[0]);
    }

    AllCountries[i].pi += (double) ( AllCountries[i].economy * country_pi_settings[3]);
    cout << "Adding economy " << AllCountries[i].pi << '\n';


  }
}

float calculate_overall_performance_index(struct country AllCountries[], int country_count, float country_pi_settings[])
{
  double overall_pi=0;
  double average_pi=0;

  // cout << "Start of the pi calculations..." << endl;

  calculate_performance_by_country(AllCountries, country_count, country_pi_settings);
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

  // cout << "End of the pi calculations..." << endl;

  // std::cout << "\noverall pi is : " << overall_pi << '\n';
  // std::cout << "average pi is : " << average_pi << '\n';
  return (float)overall_pi;
}
