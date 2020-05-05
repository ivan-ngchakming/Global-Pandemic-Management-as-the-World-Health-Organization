#ifndef COMMAND_H
#define COMMAND_H

bool country_command(string command, struct country & c );

bool card_command(string command, struct card & c);

bool who_command(string command, struct WHO & w );

bool country_pi_settings_command(string command, float a[]);

#endif
