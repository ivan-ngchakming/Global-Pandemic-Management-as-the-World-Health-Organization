#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include "main.h"

using namespace std;

void clearscreen();
void printruler();
void pressentertocontinue();
void printcountry(country c[], int index, int no_of_c);
void printcard(struct card c);
void printusecardresult(card c);
void printcounrty(struct country c);
string get_user_input(int choices);
void printmainmenu();
void printgamescreenheader(float overall_pi, int day, struct WHO who, int number_of_countries);
void printsimplecountrystat(struct country AllCountries[], int number_of_countries);
void printmaingamescreen(float overall_pi, int day, struct WHO who, struct country AllCountries[], int number_of_countries);
void printwingamescreen();
void printloosegamescreen();


#endif
