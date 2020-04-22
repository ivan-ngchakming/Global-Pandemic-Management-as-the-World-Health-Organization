#ifndef COMMAND_H
#define COMMAND_H

bool country_command(string command, string & country_name, double & population, double & infection, double & deaths, double & recovered, double & economy, double & pi);

bool card_command(string command, string & card_name, string & target_name, string & variable, bool & add, double & magnitude);

#endif
