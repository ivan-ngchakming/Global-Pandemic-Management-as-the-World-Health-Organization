//use for debug only
#include <encryptdecrypt.h>
#include <list.h>
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
  list.printlist(head);
  bool success=encrypt&decrypt.encryption("testing.txt",head);
  list.delete_list(head);
  success=encrypt&decrypt.decryption("testing.txt",head);
  list.printlist(head);
}


int main(){
  debug();
}
