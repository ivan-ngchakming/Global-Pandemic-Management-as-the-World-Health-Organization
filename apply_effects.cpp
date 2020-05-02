#include "apply_effects.h"

double double_net_magnitude(struct card c)
{
  // This function takes a command card and return the magnitude with negative signs if applicapible.
  if (c.add)
    return c.magnitude;
  else
    return -1 * c.magnitude;
}

unsigned int unsigned_int_net_magnitude(struct card c)
{
  // This function takes a command card and return the magnitude with negative signs if applicapible.
  if (c.add)
    return c.magnitude;
  else
    return -1 * c.magnitude;
}

int int_net_magnitude(struct card c)
{
  // This function takes a command card and return the magnitude with negative signs if applicapible.
  if (c.add)
    return c.magnitude;
  else
    return -1 * c.magnitude;
}

float float_net_magnitude(struct card c)
{
  // This function takes a command card and return the magnitude with negative signs if applicapible.
  if (c.add)
    return c.magnitude;
  else
    return -1 * c.magnitude;
}

unsigned long int unsigned_long_int_net_magnitude(struct card c)
{
  // This function takes a command card and return the magnitude with negative signs if applicapible.
  if (c.add)
    return c.magnitude;
  else
    return -1 * c.magnitude;
}

bool apply_card_effects_on_country(struct country AllCountries[], struct card c, int no_of_countries)
{
  // This function apply the effects of a action card onto individual countries.
  for (int i=0;i<no_of_countries;i++)
  {
    int index; // Index of the target country in AllCountries[]
    if (AllCountries[i].name = c.target)
    {
      index = i;
      return true;
    }
    else
      return false;
  }

  if (c.variable = "infection_factor")
  {
    int new_factor = AllCountries[index].infection_factor + float_net_magnitude(c);
    if (new_factor < 5 || new_factor > 0)
      AllCountries[index].infection_factor = new_factor;
    else if (new_factor <= 0)
      AllCountries[index].infection_factor = 0;
    else (new_factor >= 5)
      AllCountries[index].infection_factor = 5;
  }

  if (c.variable = "infections")
    AllCountries[index].infections += unsigned_long_int_net_magnitude(c);

  if (c.variable = "deaths")
    AllCountries[index].deaths += unsigned_int_net_magnitude(c);

  if (c.variable = "recovered")
    AllCountries[index].recovered += unsigned_int_net_magnitude(c);

  if (c.variable = "death_probability")
  {
    int new_probability = AllCountries[index].death_probability + int_net_magnitude(c);
    if (new_probability < 100 || new_probability > 0)
      AllCountries[index].death_probability = new_probability;
  }

  if (c.variable = "recover_probability")
  {
    int new_probability = AllCountries[index].recover_probability + int_net_magnitude(c);
    if (new_probability < 100 || new_probability > 0)
      AllCountries[index].recover_probability = new_probability;
    else if (new_factor <= 0)
      AllCountries[index].recover_probability = 0;
    else (new_factor >= 100)
      AllCountries[index].recover_probability = 100;
  }

  if (c.variable = "economy")
  {
    double new_economy = AllCountries[index].economy + double_net_magnitude(c);
    if (new_economy < 100 || new_economy > 0)
      AllCountries[index].economy = new_economy;
    else if (new_factor <= 0)
      AllCountries[index].economy = 0;
    else (new_factor >= 100)
      AllCountries[index].economy = 100;
  }

}
