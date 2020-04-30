#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "main.h"
#include "encryptdecrypt.h"
#include "linkedlist.h"

int main(){
  string choice="a";
  cout<<"decrypt (d) or encrypt(e)? [d/e]: "<<endl;
  while ((choice!="e")&&(choice!="d")){
    cin>>choice;
  }
  if (choice=="e"){
    //encryption
    string filename;
    cout<<"File name: ";
    cin>>filename;
    //inputting filename
    //creating list
    Node * head=NULL;
    Node * tail=NULL;
    //finish creating list

    ifstream fin;

    fin.open(filename.c_str());
    if (fin.fail()){
      cout<<"fail to open the file!";
      return 1;
    }
    string s;
    while (getline(fin,s)){
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
    cout<<"File name for output encrypted msg: ";
    cin>>filename;
    encryption(filename,head);

    delete_list(head);

  }
  else{
    //decryption
    string filename;
    cout<<"Input file name: ";
    cin>>filename;
    //inputting filename

    //creating list
    Node * head=NULL;
    Node * tail=NULL;
    //finish creating list

    ifstream fin;
    fin.open(filename.c_str());
    string s;
    while (getline(fin,s)){
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
    fin.close();
    //creating list
    printlist(head);
    //print encrypted msg

    decryption(filename, head);
    printlist(head);
    delete_list(head);
  }
  return 0;
}
