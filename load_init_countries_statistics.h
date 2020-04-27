#ifndef LOAD_INIT_COUNTRY_STATISTICS_H
#define LOAD_INIT_COUNTRY_STATISTICS_H

#include "main.h"
#include "command.h"

#include <sstream>
#include <fstream>

void load_countries_statistics(struct country AllCountries[], double init_death_probability, int &no_of_country);
#endif
