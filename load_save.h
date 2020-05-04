#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

#include "main.h"
#include "linkedlist.h"
#include "encryptdecrypt.h"
#include "command.h"
#include "dynamic_array.h"
#include "linkedlist.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

bool savegame(string filename, int day, struct WHO who, string c[], int country_size,
  string ac[], int ac_size, string rec[], int rec_size, struct Node * & dh,
  struct Node * & th, struct Node * &record);

bool loadgame(string filename, int & day, struct WHO & who, string c[],
  int & country_size, string ac[], int & ac_size, string rec[], int & rec_size,
  struct Node * & dh, struct Node * & dt, struct Node * & th,
  struct Node * & tt, struct Node * & rec_h, struct Node * & rec_t);

#endif
