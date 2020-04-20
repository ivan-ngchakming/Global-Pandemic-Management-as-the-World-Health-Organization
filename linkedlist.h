//linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node{
  string content;
  Node * next;
};
//linked list

void delete_list (Node * & head);

void printlist(Node * & head);

#endif
