/*
Dan Elliott
September 27, 2023
CIT-245
Week 4 - Counter (Chapter 7)
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<iostream>

using namespace std;

class Counter
{
private:
	int count;
	static int totalIncandDec;
public:
	Counter() { count = 0; };
	Counter(int initializer) { count = initializer; };
	void display();
	void inc();
	void dec();
};

int main() {
	//for loops used to test counter
	Counter C1, C2(200);
	cout << "Current state of C1 (Created with the default constructor)" << endl;
	C1.display();
	cout << "Current state of C2 (Created as C2(200))" << endl;
	C2.display();

	cout << "Current state of C1 after 85 inc()" << endl;
	for (int i = 0; i < 85; i++) {
		C1.inc();	
	}
	C1.display();

	cout << "Current state of C2 after 242 dec()" << endl;
	for (int i = 0; i < 242; i++) {
		C2.dec();
	}
	C2.display();

	return 0;
}


int Counter::totalIncandDec = 0;
//increments up
void Counter::inc() {
	count++;
	totalIncandDec++;
}
//decrements down
void Counter::dec() {
	count--;
	totalIncandDec++;
}
void Counter::display() {

	{
		cout << "Current count: " << count << endl;
		cout << "Total increments and dcrements: " << totalIncandDec << endl;
	}

}