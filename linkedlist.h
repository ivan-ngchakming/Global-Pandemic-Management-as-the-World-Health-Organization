//linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

#include "main.h"
#include "linkedlist.h"

void delete_list(struct Node * & head);

void insertlist(struct Node * & head ,struct Node * & tail, string s);

void printlist(struct Node * & head);

void pop3(struct Node * & list_head, struct Node * & trashhead, string s[3]);

string pop1(struct Node * & list);

#endif
