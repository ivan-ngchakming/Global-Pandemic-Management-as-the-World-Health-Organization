#include <string>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct Node{
  string content;
  Node * next;
};
//linked list

#include "linkedlist.h"

const int no_of_characters=64;
//a-z,A-Z,0-9,' '

char inttochar(int num){
  if ((num>=0)&&(num<=25)){
    return num+'a';
  }
  //0-25 storing a-z
  if ((num>=26)&&(num<=51)){
    return num-26+'A';
  }
  //26-51 storing A-Z
  if ((num>=52)&&(num<=61)){
    return num-52+'0';
  }
  //52-61 storing 0-9
  if (num==62){
    return ' ';
  }
  //62 storing ' '
  if (num==63){
    return ',';
  }
  //63 storing ' '
}

int chartoint(char answer){
  if ((answer>='a')&&(answer<='z')){
    return int(answer)-int('a')+0;
  }
  //0-25 storing a-z
  if ((answer>='A')&&(answer<='Z')){
    return int(answer)-int('A')+26;
  }
  //26-51 storing A-Z
  if ((answer>='0')&&(answer<='9')){
    return int(answer)-int('0')+52;
  }
  //52-61 storing 0-9
  if (answer==' '){
    return 62;
  }
  //62 storing ' '
  if (answer==','){
    return 63;
  }
  //63 storing '3'
}

char shift_decrypt(char inputchar, int shiftingpos){
  //inputchar is the character to be encrypted
  //shiftingpos is how much slot is needed to shift the character
  int charnum=chartoint(inputchar);
  //change character to integer
  charnum-=shiftingpos;
  //shift by -shiftingpos
  if (charnum<0){
    //if the charnum is outofrange due to shifting
    charnum+=no_of_characters;
  }
  return inttochar(charnum);
  //return the character of the calculated number
}

bool decryption(string filename, Node * &head){
  //decrypt the whole file and put the decrypted msg into linked list.
  Node * current=head;
  ifstream fin;
  fin.open(filename.c_str());
  if (fin.fail()){
    return false;
    //if fail to open the file, halt the program
    //return false to the main program
  }
  else{
    string previousline="";
    string currentline="";
    fin>>previousline;
    //the first line of the file is the key to decrypt second line
    delete_list(head);
    head=NULL;
    //initialise the lsit
    Node * tail = NULL;

    //get the previousline first
    getline(fin,currentline);

    while (getline(fin,currentline)){
      //loop until eof
      string templine="";
      //to store the temporary line to be input into linked list
      for (int i=0;i<currentline.length();++i){
        //decrypt the string character by character
        int shiftpos=chartoint(previousline[int(i%previousline.length())]);
        //finding the shiftposition by finding the previousline
        templine+=shift_decrypt(currentline[i],shiftpos);

      }
      Node * temp = new Node;
      temp->next=NULL;
      temp->content=templine;
      //creating newnode
      if (head==NULL){
        //if the list is empty
        //head and tail are pointing to temporary Node
        head=temp;
        tail=temp;
      }
      else{
        //if the list is not empty, the new node is added at the tail
        tail->next=temp;
        tail=temp;
      }
      previousline=templine;
      printlist(head);
    }
  }
  fin.close();
  return true;
  //closefile and return true which means the process runs smoothly
}

char shift_encrypt(char inputchar, int shiftingpos){
  //encrypt the character by shifting
  int charnum=chartoint(inputchar);
  //store the coresponding character using integer representation
  charnum+=shiftingpos;
  //shift the character by addition
  if (charnum>=no_of_characters){
    //after shifting, if the number is out of range, - no_of_characters
    charnum-=no_of_characters;
  }
  return inttochar(charnum);
  //return character
}

bool encryption(string filename, Node * &head){
  Node * current=head;
  ofstream fout;
  fout.open(filename.c_str());
  if (fout.fail()){
    //if fail to open txt, return to main program and return false.
    return false;
  }
  else{
    string previousline="";
    string currentline="";
    int max_length_of_the_key=20;
    //the first line is for encrypting the second line,
    //the maximum length of the first line is 20
    srand(time(NULL));
    int random_number=rand()%max_length_of_the_key;
    for (int i=0;i<random_number;++i){
      previousline+=inttochar(rand()%no_of_characters);
    }
    fout<<previousline<<endl;
    //debug
    while (current != NULL){
      string templine="";
      currentline=current->content;
      //reading content of the current node
      for (int i=0;i<currentline.length();++i){
        //encrypting the string character by character
        int shiftpos=chartoint(previousline[i%previousline.length()]);
        templine+=shift_encrypt(currentline[i],shiftpos);
        //templine stores the line to be writen into the file
      }
      fout<<templine<<endl;
      //write templine into file
      previousline=currentline;
      //the currentline will become previousline
      current=current->next;
      //the current Node will be the next node
    }
  }
  fout.close();
  return true;
  //the file is closed and return true means runs smoothly
}