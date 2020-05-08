//linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

void delete_list(struct Node * & head);

void insertlist(struct Node * & head ,struct Node * & tail, string s);

void printlist(struct Node * & head);

void pop3(struct Node * & list_head, struct Node * & trashhead, string s[]);

string pop1(struct Node * & list);

void new_card_to_trash(string s, Node * & trashtail);

#endif
