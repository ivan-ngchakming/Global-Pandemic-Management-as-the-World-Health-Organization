#include "load_init_countries_statistics.h"


// This function loads the country stats directly from a txt file
void load_countries_statistics(struct country AllCountries[], int init_death_probability, int &no_of_country,
  float infection_factor, int init_recover_probability)
{
  std::cout << "Loading countries' statistics..." << "\n";

  // Read data from txt file and store them in struct array.
  // each line in the txt file represent a country, with format: name, population, infections, deaths, recovered, economy
  std::string line;
  std::ifstream data;
  int country_count = 0;

  data.open("init_countries_statistics.txt");
  while(std::getline(data, line))
  {
    std::stringstream   linestream(line);
    std::string         value;

    int data_count = 0;
    while(getline(linestream, value, ','))
    {
        if (data_count==0)
          AllCountries[country_count].name = value;
        else if (data_count==1)
          AllCountries[country_count].population = std::stoi(value);
        else if (data_count==2)
          AllCountries[country_count].infections = std::stoi(value);
        else if (data_count==3)
          AllCountries[country_count].deaths = std::stoi(value);
        else if (data_count==4)
          AllCountries[country_count].recovered = std::stoi(value);
        else if (data_count==5)
          AllCountries[country_count].economy = std::stoi(value); // Economy is a index out of 100 to measure how busy a economy is in a country.
        data_count++;
    }
    country_count++;

  }
  data.close();

  for (int i=0;i<country_count;i++)
  {
    AllCountries[i].death_probability = init_death_probability;
    AllCountries[i].infection_factor = infection_factor;
    AllCountries[i].recover_probability = init_recover_probability;
  }
  no_of_country = country_count;
  std::cout << country_count << " countries' data loaded" << '\n';

}
