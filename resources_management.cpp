#include "resources_management.h"

void daily_resources_income(int day, WHO who, float overall_pi)
{
  if (day % who.income_frequency == 0) {
    who.capital += who.capital_income;
    who.staff += who.staff_increment;
    who.medical += who.medical_increment;
  }
}

bool use_card(WHO who, card c)
{
  if (c.cost_type == "capital")
  {
    if (who.capital >= c.cost)
      who.capital -= c.cost;
      return true;
    else
      return false;
  }

  else if (c.cost_type == "staff")
  {
    if (who.staff >= c.cost)
      who.staff -= c.cost;
      return true;
    else
      return false;
  }

  else if (c.cost_type == "medical")
  {
    if (who.medical >= c.cost)
      who.medical -= c.cost;
      return true;
    else
      return false;
  }
}
