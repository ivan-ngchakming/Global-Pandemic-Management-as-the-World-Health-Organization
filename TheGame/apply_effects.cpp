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

bool apply_card_effect_on_who(int & capital, int & staff, int & medical, struct card c)
{
  if (c.target_type=="who") {
    if (c.variable == "capital") {
      cout << "target correct: " << c.variable << endl;
      int new_capital = capital + int_net_magnitude(c);
      if (new_capital >=0) {
        capital = new_capital;
        return true;
      }
      else
      {
        capital = 0;
        return true;
      }
    }
    else if (c.variable == "staff") {
      cout << "target correct: " << c.variable << endl;
      int new_staff = staff + int_net_magnitude(c);
      if (new_staff >=0) {
        staff = new_staff;
        return true;
      }
      else
      {
        staff = 0;
        return true;
      }
    }
    else if (c.variable == "medical") {
      cout << "target correct: " << c.variable << endl;
      int new_medical = medical + int_net_magnitude(c);
      if (new_medical >=0) {
        medical = new_medical;
        return true;
      }
      else
      {
        medical = 0;
        return true;
      }
    }
    else
    {
      cout << "target error" << endl;
      return false;
    }
  }
  else
  {
    // Not a card used on who
    cout << "The card is not used on WHO" << endl;
    return false;
  }
}

bool apply_card_effects_on_country(struct country AllCountries[], struct card c, int no_of_countries)
{
  // This function apply the effects of a action card onto individual countries.
  int index; // Index of the target country in AllCountries[]
  // check if card target is country
  if (c.target_type == "country") {
    bool flag = false;
    for (int i=0;i<no_of_countries;i++)
    {
      if (AllCountries[i].name == c.target)
      {
        index = i;
        flag = true;
        break;
      }
    }
    if (!flag) {
      cout << "Error using card: Country does not exist..." << endl;
      return false;
    }
  }
  else
  {
    // Not a card used on country
    return false;
  }


  if (c.variable == "infection_factor")
  {
    float new_factor = AllCountries[index].infection_factor + float_net_magnitude(c);
    if (new_factor < 5 || new_factor > 0)
      AllCountries[index].infection_factor = new_factor;
    else if (new_factor <= 0)
      AllCountries[index].infection_factor = 0.0;
    else
      AllCountries[index].infection_factor = 5.0;
    return true;
  }

  if (c.variable == "infections")
  {
    unsigned long int new_infections = AllCountries[index].infections + unsigned_long_int_net_magnitude(c);
    if (new_infections > AllCountries[index].population)
    {
      AllCountries[index].infections = AllCountries[index].population;
    }
    else
    {
      AllCountries[index].infections = new_infections;
    }
    return true;
  }

  if (c.variable == "deaths")
  {
    unsigned int new_deaths = AllCountries[index].deaths += unsigned_int_net_magnitude(c);
    if (new_deaths > AllCountries[index].infections) {
      AllCountries[index].deaths = AllCountries[index].infections;
    }
    else
    {
      AllCountries[index].deaths = new_deaths;
    }
    return true;
  }

  if (c.variable == "recovered")
  {
    unsigned int new_recovers = AllCountries[index].recovered + unsigned_int_net_magnitude(c);
    if (new_recovers > AllCountries[index].infections - AllCountries[index].deaths) {
      AllCountries[index].deaths = AllCountries[index].infections - AllCountries[index].deaths;
    }
    else
    {
      AllCountries[index].deaths = new_recovers;
    }
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
    else if (new_probability <= 0)
      AllCountries[index].recover_probability = 0;
    else
      AllCountries[index].recover_probability = 100;
    return true;
  }

  if (c.variable == "economy")
  {
    cout << index << endl;
    // cout << "modifying " << c.variable << " in " << AllCountries[index].name << endl;
    // cout << "Old economy is " << AllCountries[index].economy << endl;
    double new_economy = AllCountries[index].economy + double_net_magnitude(c);
    if (new_economy < 100 || new_economy > 0)
      AllCountries[index].economy = new_economy;
    else if (new_economy <= 0)
      AllCountries[index].economy = 0;
    else
      AllCountries[index].economy = 100;

    // cout << "New economy is " << AllCountries[index].economy << endl;

    return true;
  }
  return false;
}

bool use_action_card(struct card c, int & capital, int & staff, int & medical, struct country AllCountries[], int no_of_countries)
{
  if (use_card_resource_cost(capital, staff, medical, c)) {
    if (apply_card_effects_on_country(AllCountries, c, no_of_countries)) {
      cout << "Effect applied... " << endl;
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

bool use_random_card(struct card c, int & capital, int & staff, int & medical, struct country AllCountries[], int no_of_countries)
{
  cout << "\nProcessing random card of the day..." << endl;
  cout << endl;
  cout << "Random Card Type: " << c.target_type << endl;
  cout << endl;
  if (apply_card_effects_on_country(AllCountries, c, no_of_countries)) {
    cout << "Effect applied on country" << endl;
    return true;
  }
  else if (apply_card_effect_on_who(capital, staff, medical, c))
  {
    cout << "Effect applied on WHO" << endl;
    return true;
  }
  else
  {
    // cout << "Passed both country and who functions" << endl;
    return false;
  }
}
