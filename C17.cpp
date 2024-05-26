/*
   Written by Professor Kenneth L Moore
   For CIT245 Data Structures and Programming C++
   This code implements a singly linked list
   Students must change it to a doubly linked list

   11/17/2023 - Modified by Dan Elliott: converted linked list to doubly linked list in reversePrint method 
*/
#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<fstream>
using namespace std;

// define a node for storage and linking
class node{  
public:
	string name; 
    node *next;
	node *prev; //Modified by D.E.
};

class linkedList{
public:
              linkedList():top(NULL){}
	bool empty(){return top == NULL;}
	node *getTop(){return top;}
	void setTop(node *n){top = n;}
	void add(string);
	int menu();
	void remove(string);
	~linkedList();
	void reversePrint(); // to be implemented by students
	friend ostream& operator << (ostream&, const linkedList&); // default output is in-order print.
private:
	node *top;
	node *end; // to be used for reverse print and implemented by students
};

void main(){
   linkedList l;
   cout << l.empty() << endl;
   int option = 0;
   string s;
   bool go = true;
   while(go){
	   option = l.menu();
	   switch(option){
			case 1: cout << "enter a name: ";cin >> s; l.add(s); break;
			case 2: cout << "enter name to be deleted: "; cin >> s; l.remove(s);break;
			case 3: cout << l; break;
			case 4:l.reversePrint(); break;
			case 5: cout << "exiting" << endl; go = false; break;
	   }
   }
   // l goes out of scope and calls ~linkedList()
}

// can not call this method "delete" - "delete" is a reserved keyword.
void linkedList::remove(string s){
	bool found = false;
	node *curr = getTop(), *prev=NULL;
	while(curr != NULL){

		// match found, delete
		if(curr->name == s){
			found = true;

			// found at top
			if(prev == NULL){
    			node *temp = getTop();
				setTop(curr->next);
				delete(temp);

			// found in list - not top
			}else{
				prev->next = curr->next;
				delete(curr);
			}
		}

		// not found, advance pointers
		if(!found){
			prev = curr;
			curr = curr->next;
		}

		// found, exit loop
		else curr = NULL;
	}
	if(found)cout << "Deleted " << s << endl;
	else cout << s << " Not Found "<< endl;
}

void linkedList::add(string s){
	node *n = new node();
	n->name = s;
	n->next = NULL;

	// take care of empty list case
	if(empty()){
		top = n;

	// take care of node belongs at beginning case
	} else if(getTop()->name > s){
		n->next = getTop();
		setTop(n);
	
	// take care of inorder and end insert
	}else{
        
		// insert in order case
		node *curr = getTop(), *prev = curr;
		while(curr != NULL){
			if(curr->name > s)break;
			prev = curr;
			curr = curr->next;
		}
		if(curr != NULL){ // search found insert point
			n->next = curr;
			prev->next = n;
		}

		// take care of end of list insertion
		else if(curr == NULL){// search did not find insert point
			prev->next = n;
			
		}
	}
}

ostream& operator << (ostream& os, const linkedList& ll){
	//linkedList x = ll; // put this in and the code blows up - why?
	node *n = ll.top;
	if(n == NULL)cout << "List is empty." << endl;
	else
		while(n != NULL){
			os << n->name << endl;
			n = n->next;
		}
	return os;
}
//Added by Dan E to print out list in reverse
void linkedList::reversePrint() {
	node* n = top;

	do {
		n->prev = end;
		end = n;

		n = n->next;
	} while (n != NULL);
	
	n = end;

	while(n != NULL){
		cout << n->name << endl;
		n = n->prev;
	}

	end = NULL; //resets end for next reverse print
}
// return memory to heap
linkedList::~linkedList(){
	cout << "~linkedList called." << endl;
	node *curr = getTop(), *del;
	while(curr != NULL){
		del = curr;
		curr = curr->next;
		delete(del);
	}
}

int linkedList::menu(){
	int choice = 0;
	while(choice < 1 || choice > 5){
		cout << "\nEnter your choice" << endl;
		cout << " 1. Add a name." << endl;
		cout << " 2. Delete a name." << endl;
		cout << " 3. Show list." << endl;
		cout << " 4. Show reverse list. " << endl; // to be implemented by students
		cout << " 5. EXIT " << endl;
		cin >> choice;
	}
	return choice;
}
