#include <iostream>
#include <string>

using namespace std;

#include "main.h"
#include "linkedlist.h"

int main(){
  Node * list_head=NULL;
  Node * list_tail=NULL;
  Node * trash_head=NULL;
  Node * trash_tail=NULL;
  string input="";
  cout<<"deck list: "<<endl;
  while (input!="exit"){
    //loop until user enter exit
    cin>>input;
    if (input!="exit"){
      Node * temp = new Node;
      temp->content=input;
      temp->next=NULL;
      if (list_head==NULL){
        list_head=temp;
        list_tail=temp;
      }
      else{
        list_tail->next=temp;
        list_tail=temp;
      }
    }
  }
  input="";
  cout<<"trash list: "<<endl;
  while (input!="exit"){
    //loop until user enter exit
    cin>>input;
    if (input!="exit"){
      Node * temp = new Node;
      temp->content=input;
      temp->next=NULL;
      if (trash_head==NULL){
        trash_head=temp;
        trash_tail=temp;
      }
      else{
        trash_tail->next=temp;
        trash_tail=temp;
      }
    }
  }
  input="";
  printlist(list_head);
  printlist(trash_head);
  cout<<"It is time to test"<<endl;
  int number_of_loops=0;
  cin>>number_of_loops;
  for (int i=0;i<number_of_loops;++i){
    cout<<"________________________________________________"<<endl;
    cout<<"loop: "<<i<<endl;
    string s[3];
    pop3(list_head,trash_head,s);
    cout<<"Pop 3: "<<endl;
    for (int j=0;j<3;++j){
      cout<<s[j]<<endl;
    }
    printlist(list_head);
    printlist(trash_head);
  }
  delete_list(list_head);
  delete_list(trash_head);
  return 0;
}
