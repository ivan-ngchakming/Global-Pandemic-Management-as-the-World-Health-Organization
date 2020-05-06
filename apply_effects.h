#ifndef APPLY_EFFECTS_H
#define APPLY_EFFECTS_H

#include "main.h"

#include <iostream>

bool apply_card_effects_on_country(struct country AllCountries[], struct card c, int no_of_countries);
bool use_action_card(struct card c, struct WHO who, struct country AllCountries[], int no_of_countries);
bool use_random_card(struct card c, struct WHO who, struct country AllCountries[], int no_of_countries);

#endif
