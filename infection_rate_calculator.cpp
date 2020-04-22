#include "infection_rate_calculator.h"


int increase_in_infection(int infection_factor, double infections)
{
  int distribution_mean = infection_factor * infections;

  std::default_random_engine generator;
  std::poisson_distribution<int> distribution(distribution_mean);

  int increases = distribution(generator);

  return increases;
}

void calculate_daily_infection(struct country AllCountries[])
{
  // This function calculate the increase in number of infection in each country

  int infection_factor = 2;


  for (int i=0;i<20;i++)
  {
    int increase = increase_in_infection(infection_factor, AllCountries[i].infections);
    AllCountries[i].infection_increase = increase;
    std::cout << "Increase in infection for " << AllCountries[i].name << " is " << increase << '\n';
    AllCountries[i].infections += increase;
  }

}
