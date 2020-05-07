#ifndef INFECTION_RATE_CALCULATOR_H
#define INFECTION_RATE_CALCULATOR_H



void calculate_daily_infection(struct country AllCountries[], int country_count);
void calculate_daily_economic_impact(struct country AllCountries[], int country_count, float lockdown_economy_threshold);


#endif
