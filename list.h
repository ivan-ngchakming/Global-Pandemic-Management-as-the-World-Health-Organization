//list.h
#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

struct Node{
  string content;
  Node * next;
};
//linked list

//delete the head node from a linked list
void delete_head (Node * & head){
  if (head !=NULL){
    Node * p = head;
    head=head->next;
    delete p;
  }
}

//free an entire linked list
void delete_list (Node * & head){
  while (head !=NULL){
    delete_head(head);
  }
}

// output the linked list
void printlist(Node * head){
    Node * current = head;
    while (current != NULL)
    {
        // process the current node, e.g., print the content
        cout << current->content << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

#endif
