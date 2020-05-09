#ifndef RESOURCES_MANAGEMENT_H
#define RESOURCES_MANAGEMENT_H

#include <iostream>
#include "main.h"
#include "apply_effects.h"

void daily_resources_income(WHO who, int day, int & capital, int & staff, int & medical, float overall_pi);
bool use_card_resource_cost(int & capital, int & staff, int & medical, card c);


#endif
