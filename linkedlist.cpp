#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
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

void swaplist (Node * & list_head, Node *& trashhead){
  Node * temp = list_head;
  list_head=trashhead;
  trashhead=temp;
}

void random_insert_to_trash(Node *& targetnode, Node * & trashhead,int & no_trash){
  Node * current=trashhead;
  srand(time(NULL));
  int random_number=rand()%no_trash;
  //generating the pos of the new node randomly
  for (int i=0;i<random_number;++i){
    current=current->next;
  }
  targetnode->next=current->next;
  current->next = *targetnode;
  //inputting the node into the list in random position generated before
  no_trash+=1;
  //the nodes in trash list increase by 1
}

//pop the first three node from the delete_list
//and put into rubbish_bin_list randomly
//if the list only contains less than 3 nodes,
//the remaining node will be randomly put into rubbish_bin_list
//swap the list with rubbish_bin_list
//the return 3 string is stored in s which s is an array of 3 slots
void pop3(Node * & list_head, Node * & trashhead, string s[3], int & no_list, int & no_trash){
  int count=0;
  Node * head = list_head;
  while (count<3){
    if (no_list>=3){
      s[i]=list_head->content;
      //store the content into the array
      random_insert_to_trash(s[i],trashhead,no_of_trash);
      list_head=list_head->next;
      //remove the first node in list_head and put into the trash list
    }
    else{
      while (list_head!=NULL){
        //the first node of the list is pop out.
        random_insert_to_trash(list_head,trashhead,no_trash);
        list_head=list_head->next;
      }
      swaplist(list_head, trashhead);
    }
    cout+=1;
    //loop three times
  }
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
