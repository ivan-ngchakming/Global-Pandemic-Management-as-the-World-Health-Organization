//linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

void delete_list (Node * & head);

void insertlist(Node *& head ,Node *& tail, string s);

void printlist(Node * & head);

void pop3(Node * & list_head, Node * & trashhead, string s[3], int & no_list, int & no_trash);

string pop1(Node *&  list);

#endif
