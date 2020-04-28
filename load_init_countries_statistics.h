#ifndef LOAD_INIT_COUNTRY_STATISTICS_H
#define LOAD_INIT_COUNTRY_STATISTICS_H

#include "main.h"
#include "command.h"

#include <sstream>
#include <fstream>

void load_countries_statistics(struct country AllCountries[], int init_death_probability, int &no_of_country,
   float infection_factor, int init_recover_probability);
#endif
