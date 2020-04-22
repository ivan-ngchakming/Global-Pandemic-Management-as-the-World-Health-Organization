#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node{
  string content;
  Node * next;
};
//linked list

#include "encryptdecrypt.h"
#include "linkedlist.h"

int main(){
  string filename;
  cout<<"File name: ";
  cin>>filename;
  //inputting filename
  //creating list
  Node * head=new Node NULL;
  Node * tail=new Node NULL;
  //finish creating list

  ifstream fin;
  fin.open(filename.c_str());
  if (fin.fail()){
    return 1;
  }
  string s;
  while (fin>>s){
    Node * temp=new Node;
    temp->content=s;
    temp->next=NULL;
    if (head==NULL){
      head=temp;
      tail=temp;
    }
    else{
      tail->next=temp;
      tail=temp;
    }
  }
  printlist(head);
  fin.close();
  //finish inputting from the txt document
  if (fin.open(filename.c_str()))
  cout<<"File name for output encrypted msg: ";
  cin>>filename;
  encryption(filename,head);

  delete_list(head);
}
