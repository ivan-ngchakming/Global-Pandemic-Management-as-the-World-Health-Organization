#include <iostream>
#include <string>
using namespace std;

#include "main.h"

//delete the head node from a linked list
void delete_head (Node * & head){
  if (head !=NULL){
    Node * p = head;
    head=head->next;
    delete p;
  }
}

//free an entire linked list
void delete_list(struct Node * & head){
  while (head !=NULL){
    delete_head(head);
  }
}

void insertlist(Node *& head ,Node *& tail, string s){
  Node * temp = new Node;
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

void swaplist (Node * & list_head, Node *& trashhead){
  Node * temp = list_head;
  list_head=trashhead;
  trashhead=temp;
}

// output the linked list number of Node
int countlist(Node * & head){
    int answer=0;
    Node * current = head;
    while (current != NULL)
    {
        answer+=1;
        current = current->next;
    }
    return answer;
}

// output the linked list
void printlist(Node * & head){
    Node * current = head;
    while (current != NULL)
    {
        // process the current node, e.g., print the content
        cout << current->content << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}


void random_insert_to_trash(Node *& firstnode, Node * & trashhead,int & no_trash){
  Node * current=trashhead;
  Node * previous=trashhead;
  int random_number;
  if (no_trash==0){
      random_number=0;
      //because for an empty trash list
      //the random position to put the node into the list must be 0
  }
  else{
    srand(time(NULL));
    random_number=rand()%no_trash;
    //generating the pos of the new node randomly
    for (int i=1;i<random_number;++i){
      previous=previous->next;
    }
    current=previous->next;
  }
  if (random_number==0){
    Node * temp = new Node;
    temp->content=firstnode->content;
    temp->next=trashhead;
    trashhead=temp;
    //add the node to the front of the trash list if the random_number is 0.
    Node * poptemp=firstnode;
    firstnode=firstnode->next;
    delete poptemp;
    //remove the first node in the list
  }
  else{
    Node * temp = new Node;
    temp->content=firstnode->content;
    temp->next=current;
    previous->next=temp;
    Node * poptemp=firstnode;
    firstnode=firstnode->next;
    delete poptemp;
    //remove the first node in the list
  }
  no_trash+=1;
  //the nodes in trash list increase by 1
}

//pop the first three node from the delete_list
//and put into rubbish_bin_list randomly
//if the list only contains less than 3 nodes,
//the remaining node will be randomly put into rubbish_bin_list
//swap the list with rubbish_bin_list
//the return 3 string is stored in s which s is an array of 3 slots
void pop3(Node * & list_head, Node * & trashhead, string s[]){
  int no_list=countlist(list_head);
  int no_trash=countlist(trashhead);

  // printlist(list_head);
  // printlist(trashhead);
  // cout<<no_list<<":"<<no_trash<<endl;

  int count=0;
  while (count<3){
    if (no_list==0){
      swaplist(list_head,trashhead);
      no_list=no_trash;
      no_trash=0;
      //if the deck list is empty, then the trash list will become deck list
      //and trash list is empty
    }
    s[count]=list_head->content;
    //store the content of the first node into the array
    random_insert_to_trash(list_head,trashhead,no_trash);
    //pop the first node in list_head and put into the trash list
    no_list-=1;
    count+=1;
  }
}

//pop the first node of the list
//and the node is free
string pop1(Node *&  list){
  if (list==NULL){
    return "";
  }
  else{
    string s=list->content;
    Node * temp = new Node;
    temp=list;
    list=list->next;
    delete temp;
    return s;
  }
}
