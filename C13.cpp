/*
Dan Elliott
October 23, 2023
CIT-245
Week 8 - Towers of Hanoi (Chapter 13)
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<fstream>

using namespace std;

int times{};
void towersOfHanoi(int n, char fromTower, char toTower, char spareTower);



int main() {
	char goAgain = 'n';

	cout << "\n\n-------------------------------*Towers of Hanoi*-------------------------------"<<endl<<endl;

	do {
		cout << "Please enter the number of disks on the Towers of Hanoi puzzle: ";



		int n;

		cin >> n;

		towersOfHanoi(n, 'A', 'C', 'B');

		cout << "Number of moves " << times << endl;
		times = 0;
		
		cout << "Continue ? ('Y' for yes and 'N' for no): ";
		cin >> goAgain;

	} while (goAgain == 'Y' || goAgain == 'y');

	return 0;
}

void towersOfHanoi(int n, char fromTower, char toTower, char spareTower) {

	if (n == 1) {
		cout << "Move disk 1 from tower " << fromTower << " to tower " << toTower << endl;
		times += 1;
		return;
		
	}
	towersOfHanoi(n - 1, fromTower, spareTower, toTower);
	
	cout << "Move disk " << n << " from tower " << fromTower << " to tower " << toTower << endl;

	towersOfHanoi(n - 1, spareTower, toTower, fromTower);
	times += 1;
}