#include "apply_effects.h"
#include "resources_management.h"

using namespace std;

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

bool apply_card_effect_on_who(struct WHO who, struct card c)
{
  if (c.target_type=="who") {
    if (c.target == "capital") {
      who.capital += int_net_magnitude(c);
      return true;
    }
  }
  else
  {
    // Not a card used on who
    return false;
  }
}

bool apply_card_effects_on_country(struct country AllCountries[], struct card c, int no_of_countries)
{
  // This function apply the effects of a action card onto individual countries.
  // check if card target is country
  if (c.target_type == "country") {
    for (int i=0;i<no_of_countries;i++)
    {
      int index; // Index of the target country in AllCountries[]
      if (AllCountries[i].name == c.target)
      {
        index = i;
        return true;
      }
      else
      {
        cout << "Error using card: Country does not exist..." << endl;
        return false;
      }
    }
  }
  else
  {
    // Not a card used on country
    return false;
  }


  if (c.variable == "infection_factor")
  {
    int new_factor = AllCountries[index].infection_factor + float_net_magnitude(c);
    if (new_factor < 5 || new_factor > 0)
      AllCountries[index].infection_factor = new_factor;
    else if (new_factor <= 0)
      AllCountries[index].infection_factor = 0;
    else (new_factor >= 5)
      AllCountries[index].infection_factor = 5;
    return true;
  }

  if (c.variable == "infections")
  {
    AllCountries[index].infections += unsigned_long_int_net_magnitude(c);
    return true;
  }

  if (c.variable == "deaths")
  {
    AllCountries[index].deaths += unsigned_int_net_magnitude(c);
    return true;
  }

  if (c.variable == "recovered")
  {
    AllCountries[index].recovered += unsigned_int_net_magnitude(c);
    return true;
  }

  if (c.variable == "death_probability")
  {
    int new_probability = AllCountries[index].death_probability + int_net_magnitude(c);
    if (new_probability < 100 || new_probability > 0)
    {
      AllCountries[index].death_probability = new_probability;
      return true;
    }
  }

  if (c.variable == "recover_probability")
  {
    int new_probability = AllCountries[index].recover_probability + int_net_magnitude(c);
    if (new_probability < 100 || new_probability > 0)
      AllCountries[index].recover_probability = new_probability;
    else if (new_factor <= 0)
      AllCountries[index].recover_probability = 0;
    else (new_factor >= 100)
      AllCountries[index].recover_probability = 100;
    return true;
  }

  if (c.variable == "economy")
  {
    double new_economy = AllCountries[index].economy + double_net_magnitude(c);
    if (new_economy < 100 || new_economy > 0)
      AllCountries[index].economy = new_economy;
    else if (new_factor <= 0)
      AllCountries[index].economy = 0;
    else (new_factor >= 100)
      AllCountries[index].economy = 100;
    return true;
  }
  return false;
}

bool use_action_card(struct card c, struct WHO who, struct country AllCountries[], int no_of_countries)
{
  if (use_card_resource_cost(who, c)) {
    if (apply_card_effects_on_country(AllCountries, c, no_of_countries)) {
      cout << "Effect applied on country" << endl;
      return true;
    }
    else
    {
      // Not a country action card...
      cout << "Error in using action card: card target not recognized" << endl;
      return true;
    }
  }
  else
  {
    // Not enough resources to use this action card.
    return false;
  }
}

bool use_random_card(struct card c, struct WHO who, struct country AllCountries[], int no_of_countries)
{
  if (apply_card_effects_on_country(AllCountries, c, no_of_countries)) {
    cout << "Effect applied on country" << endl;
    return true;
  }
  else if (apply_card_effect_on_who(who, c))
  {
    cout << "Effect applied on WHO" << endl;
    return true;
  }
  else
  {
    return false;
  }
}
