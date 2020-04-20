//use for debug only
#include "encryptdecrypt.h"
#include "linkedlist.h"
#include <string>
#include <iostream>
using namespace std;

struct Node{
  string content;
  Node * next;
};
//linked list

void debug(){
  Node * head = NULL;
  Node * tail = NULL;
  string s="";
  while (s!="exit"){
    Node * temp= new Node;
    temp->next=NULL;
    cin>>s;
    if (s!="exit"){
      temp->content=s;
      if (head==NULL){
        head=temp;
        tail=temp;
      }
      else{
        tail->next=temp;
        tail=temp;
      }
    }
  }
  printlist(head);
  bool success=encryption("testing.txt",head);
  delete_list(head);
  success=decryption("testing.txt",head);
  printlist(head);
}


int main(){
  debug();
}
