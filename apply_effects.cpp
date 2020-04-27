#include "apply_effects.h"

double net_magnitude(struct card c)
{
  // This function takes a command card and return the magnitude with negative signs if applicapible.
  if (c.add)
    return c.magnitude;
  else
    return -1 * c.magnitude;
}

bool apply_card_effects_on_country(struct country AllCountries[], struct card c)
{
  // This function apply the effects of a action card onto individual countries.
  for (int i=0;i<20;i++)
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

  if (c.variable = infection_factor)
    AllCountries[i].infection_factor += net_magnitude(c);
  if (c.variable = death_probability)
    AllCountries[i].death_probability += net_magnitude(c);
  if (c.variable = infections)
    AllCountries[i].infections += net_magnitude(c);
  if (c.variable = deaths)
    AllCountries[i].deaths += net_magnitude(c);
  if (c.variable = recovered)
    AllCountries[i].recovered += net_magnitude(c);
  if (c.variable = economy)
    AllCountries[i].economy += net_magnitude(c);

}
