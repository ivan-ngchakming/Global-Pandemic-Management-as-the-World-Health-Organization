#include "resources_management.h"

void daily_resources_income(WHO who, int day, int & capital, int & staff, int & medical, float overall_pi)
{
  if (day %   who.income_frequency == 0) {
      capital += who.capital_income;
      staff +=  who.staff_increment;
      medical +=  who.medical_increment;
  }
}

bool use_card_resource_cost(int & capital, int & staff, int & medical, card c)
{
  if (c.cost_type == "capital")
  {
    if ( capital >= c.cost)
    {
       capital -= c.cost;
      return true;
    }
    else
    {
      cout << "Not enough capital to use this card" << endl;
      return false;
    }
  }

  else if (c.cost_type == "staff")
  {
    if ( staff >= c.cost)
    {
       staff -= c.cost;
      return true;
    }
    else
    {
      cout << "Not enough staff to use this card" << endl;
      return false;
    }
  }

  else if (c.cost_type == "medical")
  {
    if (  medical >= c.cost)
    {
        medical -= c.cost;
      return true;
    }
    else
    {
      cout << "Not enough medical equipment to use this card" << endl;
      return false;
    }
  }
}
