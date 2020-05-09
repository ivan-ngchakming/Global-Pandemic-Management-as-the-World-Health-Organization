//encryptdecrypt.h
#ifndef ENCRYPTDECRYPT_H
#define ENCRYPTDECRYPT_H

#include <string>
#include <fstream>
#include "main.h"
#include "linkedlist.h"

bool decryption(string filename, struct Node * &head);
bool encryption(string filename, struct Node * &head);

#endif
