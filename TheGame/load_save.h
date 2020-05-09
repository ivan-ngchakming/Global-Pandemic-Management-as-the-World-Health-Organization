#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

bool savegame(string filename, int day, WHO who, int no_of_country, string c[],
  int init_death_probability, int init_recover_probability, float country_pi_settings[], float infection_factor,
  string ac[], int ac_size, int ac_num,
  string rec[], int rec_size, int rec_num,
  Node * & dh, Node * & dt, Node * & th, Node * & tt);



bool savegame002(string filename, int day, WHO who, int no_of_country, country AllCountries[],
    int init_death_probability, int init_recover_probability, float country_pi_settings[], float infection_factor,
    string ac[], int ac_size, int ac_num,
    string rec[], int rec_size, int rec_num,
    Node * & dh, Node * & dt, Node * & th, Node * & tt);


bool loadgame(string filename,int & day, WHO & who, int & max_country_size, int & no_of_country, string c[],
  int & init_death_probability, int & init_recover_probability, float country_pi_settings[], float & infection_factor,
  string ac[], int & ac_size, int & ac_num,
  string rec[], int & rec_size, int & rec_num,
  Node * & dh, Node * & dt, Node * & th, Node * & tt);



#endif
