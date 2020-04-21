#include <iostream>
#include <string>
using namespace std;

struct Node{
  string content;
  Node * next;
};
//linked list

#include <linkedlist>

int main(){
  Node * list_head=NULL;
  Node * list_tail=NULL;
  Node * trash_head=NULL;
  Node * trash_tail=NULL;
  string input="";
  cout<<"deck list: "<<endl;
  int no_list=0;
  while (intput!="exit"){
    //loop until user enter exit
    cin>>answer;
    if (answer!="exit"){
      no_list+=1;
      Node * temp = new Node;
      temp->content=answer;
      temp->next=NULL;
      if (head==NULL){
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
  int no_trash=0;
  while (intput!="exit"){
    //loop until user enter exit
    cin>>answer;
    if (answer!="exit"){
      no_trash+=1;
      Node * temp = new Node;
      temp->content=answer;
      temp->next=NULL;
      if (head==NULL){
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
  cout<<"It is time to test"<<endl;
  int number_of_loops=0;
  cout>>number_of_loops;
  for (int i=0;i<number_of_loops;++i){
    string s[3];
    pop3(list_head,trash_head,s,no_list,no_trash)
    cout<<"deck: "<<no_deck<<endl;
    printlist(list_head);
    cout<<"trasn: "<<no_trash<<endl;
    printlist(trash_head);
  }
  delete_list(list_head);
  delete_list(trash_head);
  return 0;
}
