#include <string>
using namespace std;

#include "main.h"

void grow_array(string a[], int & array_size){
  //if the array is full,
	// create a new dynamic array with a new size = array_size*2
	string * a_new = new string[array_size*2];

	// copy all the records from the original array to the new dynamic array
	for (int i = 0; i < array_size; i++)
	{
		a_new[i] = a[i];
	}

	// destroy the old dynamic array to free up the memory allocated to it
	delete [] a;
	// assign the pointer to the new dynamic array to the pointer variable
	a = a_new;
	// update the size of the array
	array_size *= 2;
}

void list_to_array(Node * & content_list, string stop_content, string array[], int & array_size){
  int num=0;
  //num stores number of command stored in the array_size
  Node * current = content_list;
  //current stores the node which currently read
  while ((current->content)==stop_content){
    //loop until read stop_content such as "end"
    if (array_size>=num){
      grow_array(array,array_size);
    }
    array[num]=content_list->content;
    content_list=content_list->next;
    num+=1;
  }
}
