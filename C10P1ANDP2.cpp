/*
Dan Elliott
October 12, 2023
CIT-245
Week 6 - pointers & shallow and deep copy (Chapter 10)
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<stack>
#include<iostream>


using namespace std;


class WrapArrayDeep {

private:
	char* pch;
public:
	//initializes WrapArrayDeep
	WrapArrayDeep();
	//Copy constructor
	WrapArrayDeep(const WrapArrayDeep& wad);
	//Modifies array in WrapArryDeep class
	void ModifyWrapArrayDeep();
	//prints array WrapArryDeep class
	void ShowWrapArrayDeep();
	//deconstructor
	~WrapArrayDeep();
};

class WrapArrayShallow {

private:
	char* pch;
public:
	//initializes WrapArrayShallow
	WrapArrayShallow();
	//Copy constructor
	WrapArrayShallow(const WrapArrayShallow& was);
	//Modifies array in WrapArryShallow class
	void ModifyWrapArrayShallow();
	//prints array in WrapArryShallow class 
	void ShowWrapArrayShallow();
	//deconstructor
	~WrapArrayShallow();
};


int main() {


	int i = 7;
	int* pi = &i;

	cout << "(Pt.1) This program section uses 3 variables" << endl;
	cout << "i = " << i << ", pi is a pointer to i, and ppi is a pointer to pi" << endl<<endl;

	cout << "pi = " << pi << endl;
	cout << "address of pi = " << &pi << endl;
	cout <<"dereference of pi = " << * pi << endl;
	cout << "address of i = " << &i << endl<<endl;

	int **ppi = &pi;

	cout << "ppi = " << ppi << endl;
	cout <<"address of ppi = " << &ppi << endl;
	cout << "ppi single dereference = " << *ppi << endl;
	cout << "ppi double dereference = " << **ppi << endl;

	cout << endl << "(Pt. 2) This section instantiates a wrapper class for a dynamic array of 5 elements. " << endl;
	WrapArrayDeep wad1 = WrapArrayDeep();
	WrapArrayDeep wad2 = WrapArrayDeep(wad1);
	cout << "WrapArrayDeep 1" << endl;
	wad1.ShowWrapArrayDeep();
	cout << "WrapArrayDeep 2 created using the copy constructor on 1" << endl;
	wad2.ShowWrapArrayDeep();
	//modifies the contents of wad1
	wad1.ModifyWrapArrayDeep();
	cout << "After changing the contents of WrapArrayDeep 1, 1 and 2 = " << endl;
	wad1.ShowWrapArrayDeep();
	wad2.ShowWrapArrayDeep();
	cout << endl << "Now doing the same thing with WrapArrayShallow"<<endl<<endl;
	WrapArrayShallow was1 = WrapArrayShallow();
	WrapArrayShallow was2 = WrapArrayShallow(was1);
	cout << "WrapArrayShallow 1" << endl;
	was1.ShowWrapArrayShallow();
	cout << "WrapArrayShallow 2 created using the copy constructor on 1" << endl;
	was2.ShowWrapArrayShallow();
	//modifies the contents of was1
	was1.ModifyWrapArrayShallow();
	cout << "After changing the contents of WrapArrayShallow 1, 1 and 2 = " << endl;
	was1.ShowWrapArrayShallow();
	was2.ShowWrapArrayShallow();

	return 0;
}
WrapArrayDeep::WrapArrayDeep() {
	pch = new char[5];
	*pch = 97;
	*(pch + 1) = 98;
	*(pch + 2) = 99;
	*(pch + 3) = 100;
	*(pch + 4) = 101;

}
WrapArrayDeep::WrapArrayDeep(const WrapArrayDeep& wad) {
	pch = new char[5];
	for (int i = 0; i < 5; i++) {
		pch[i] = wad.pch[i];
	}
}
void WrapArrayDeep::ModifyWrapArrayDeep() {
	*pch = 50;
	*(pch + 1) = 51;
	*(pch + 2) = 52;
	*(pch + 3) = 53;
	*(pch + 4) = 54;
}
void WrapArrayDeep::ShowWrapArrayDeep() {
	for (int i = 0; i < 5; i++) {
		cout << pch[i];
	}
	cout << endl;
}

WrapArrayDeep::~WrapArrayDeep() {
	cout << "Destructor for WrapArrayDeep called." << endl;
	delete []pch;
}

WrapArrayShallow::WrapArrayShallow() {
	pch = new char[5];
	pch[0] = 'a';
	pch[1] = 'b';
	pch[2] = 'c';
	pch[3] = 'd';
	pch[4] = 'e';

}
WrapArrayShallow::WrapArrayShallow(const WrapArrayShallow& was) {

		pch = was.pch;
}
void WrapArrayShallow::ModifyWrapArrayShallow() {
	pch[0] = '2';
	pch[1] = '3';
	pch[2] = '4';
	pch[3] = '5';
	pch[4] = '6';
}
void WrapArrayShallow::ShowWrapArrayShallow() {
	for (int i = 0; i < 5; i++) {
		cout << *(pch + i);
	}
	cout << endl;
}
WrapArrayShallow::~WrapArrayShallow() {
	cout << "Destructor for WrapArrayShallow called." << endl;
	//delete [] pch; causes error.
}