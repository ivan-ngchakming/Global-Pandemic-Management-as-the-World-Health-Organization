#include <iostream>
#include <random>
#include <time.h>

using namespace std;

#include "main.h"
#include "infection_rate_calculator.h"


unsigned int increase_in_infections(country c)
{
  unsigned int increases = 0;
  if (c.infections < c.population)
  {
    // Increase by domestic infections
    int average_domestic_infection = c.infection_factor * c.infections;
    random_device rd;
    mt19937 generator(rd());
    poisson_distribution<unsigned int> domestic_infection_distribution(average_domestic_infection);

    increases += domestic_infection_distribution(generator);

    // Increase by foreign infection every 10 economy score will lead to an average of one infection
    if (c.economy>0)
    {
      double average_foreign_infection = c.economy / 10;
      poisson_distribution<unsigned long int> foreign_infection_distribution(average_foreign_infection);
      unsigned int foreign_infection = foreign_infection_distribution(generator);
      increases += foreign_infection;
    }
  }
  if (increases > c.population - c.infections)
    return c.population - c.infections;
  else
    return increases;
}

unsigned int increase_in_deaths(country c)
{
  unsigned int average_deaths = c.infections * c.death_probability / 100;
  random_device rd;
  mt19937 generator(rd());
  poisson_distribution<unsigned int> deaths_distribution(average_deaths);
  unsigned int deaths = deaths_distribution(generator);
  if (deaths > c.infections - c.deaths) {
    return c.infections - c.deaths;
  }
  else
    return deaths;
}

unsigned int increase_in_recoveries(country c)
{
  unsigned int average_recoveries = c.infections * c.recover_probability / 100;
  random_device rd;
  mt19937 generator(rd());
  poisson_distribution<unsigned int> recover_distribution(average_recoveries);
  return recover_distribution(generator);
}

/// <summary>This function calculate the increase in number of infection in each country</summary>
/// <param name="AllCountries[]">Array of struct of all countries.</param>
/// <returns>None</returns>
void calculate_daily_infection(country AllCountries[], int country_count)
{
  // Loop through each country to calculate their increase in infections, deaths and recoveries in a day.
  for (int i=0;i<country_count;i++)
  {
    unsigned int increase = increase_in_infections(AllCountries[i]);
    unsigned int deaths = increase_in_deaths(AllCountries[i]);
    unsigned int recoveries = increase_in_recoveries(AllCountries[i]);
    AllCountries[i].infection_increase = increase;
    AllCountries[i].infections += increase;
    AllCountries[i].deaths += deaths;
    AllCountries[i].recovered += recoveries;


    double percent = (double)AllCountries[i].infections / (double)AllCountries[i].population * 100;
    AllCountries[i].infected_percentage = (float)percent;

    // printf( "\nInfection in %s is %.2f, infected: %lu, healthy: %lu, pop: %lu\n",
    // AllCountries[i].name.c_str(), percent,
    // AllCountries[i].infections, healthy, AllCountries[i].population);
    // cout << "death increase is " << deaths << " to " << AllCountries[i].deaths << endl;
    // printf("Increase: %lu\n", AllCountries[i].infection_increase);

  }

}

void calculate_daily_economic_impact(struct country AllCountries[], int country_count, float lockdown_economy_threshold)
{
  for (int i=0;i<country_count;i++)
  {
    AllCountries[i].infected_percentage = ( (long double)AllCountries[i].infections - (long double)AllCountries[i].recovered - (long double)AllCountries[i].deaths ) / (long double)AllCountries[i].population;
    // High infection rate leads to lower economic activity
    if (AllCountries[i].economy > 0)
    {
      AllCountries[i].economy -= (int)(AllCountries[i].infected_percentage * 10);
      if (AllCountries[i].infected_percentage > lockdown_economy_threshold)
        AllCountries[i].economy = 0;
    }
    else
      AllCountries[i].economy = 0;
  }
}
