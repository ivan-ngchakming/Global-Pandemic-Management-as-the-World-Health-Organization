#ifndef COMMAND_H
#define COMMAND_H

#include "main.h"

bool country_command(string command, struct country & c );

bool card_command(string command, struct card & c);

bool who_command(string command, struct WHO & w );

#endif
