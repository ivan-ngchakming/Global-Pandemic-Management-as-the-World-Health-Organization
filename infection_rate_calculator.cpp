#include "infection_rate_calculator.h"


double increase_in_infections(struct country country)
{
  double increases = 0;
  if (country.infections < country.population - country.deaths - country.recovered)
  {
    // Increase by domestic infections
    double average_domestic_infection = country.infection_factor * country.infections;

    unsigned int time_ui = static_cast<unsigned int>( time(NULL) / country.population );
    // std::cout << "The seed is " << time_ui << '\n';
    std::default_random_engine generator (time_ui);
    std::poisson_distribution<int> domestic_infection_distribution(average_domestic_infection);

    increases += (double)domestic_infection_distribution(generator);


    // Increase by foreign infection every 10 economy score will lead to an average of one infection
    if (country.economy>0)
    {
      float average_foreign_infection = country.economy / 10;
      std::poisson_distribution<int> foreign_infection_distribution(average_foreign_infection);
      double foreign_infection = (double)foreign_infection_distribution(generator);
      // std::cout << "There is a foregin infection of " << foreign_infection << '\n';
      // std::cout << "The average foreign infection is " << average_foreign_infection << '\n';
      increases += foreign_infection;
    }
  }

  return increases;
}

int increase_in_deaths(float death_probability, double infections)
{
  ;
}

void calculate_daily_infection(struct country AllCountries[])
{
  // This function calculate the increase in number of infection in each country

  float infection_factor = 2;


  for (int i=0;i<20;i++)
  {
    int increase = increase_in_infections(AllCountries[i]);
    AllCountries[i].infection_increase = increase;
    AllCountries[i].infections += increase;
    std::cout << "Increase in infection for " << AllCountries[i].name << " is " << increase << " to " << AllCountries[i].infections << " infected" << '\n';
  }

}
