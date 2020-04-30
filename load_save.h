#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

bool savegame(string filename, int day, WHO who, string c[], int country_size, string ac[], int ac_size, string rec[], int rec_size, Node * & dh, Node * & th, Node * &record);
bool loadgame(string filename, int & day, WHO & who, string c[], int & country_size, string ac[], int & ac_size, string rec[], int & rec_size, Node * & dh, Node * & dt, Node * & th, Node * & tt, Node * & rec_h, Node * & rec_t);

#endif
