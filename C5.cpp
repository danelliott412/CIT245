/*
Dan Elliott
September 21, 2023
CIT-245
Week 3 - random number sort (Chapter 5)
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {

	int goAgain = 0;

	cout << "This program creates an array of 20 randomized integers that range from 1 to 10." <<endl << "Then, it produces a sorted array and counts the occurences of each digit." << endl<< endl;

	do {
		//Sets seed for random number generation based on time
		int currentTime = time(NULL);
		srand(currentTime);
		int rolls;
		int randNum[20];
		int sortedRandNum[20];
		int Count[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
		double percentError;


		//Random Array creation
		for (int i = 0; i < 20; i++) {
			int newRandNum = (rand() % 10) + 1;

			randNum[i] = newRandNum;
		}

		//Sort random array
		sort(randNum, randNum + 20);

		cout << "Sorted Array: " << endl << endl;
		cout << "	Array" << endl << "	Position" << "	" << "Number" << endl;

		for (int i = 0; i <= 19; i++) {
			
			cout << "	" << "a[" << i << "]" << "		" << randNum[i] << endl;
		}
		//Counts occurence of each digit
		for (int i = 0; i <= 19; i++) {

			Count[randNum[i]]++;

		}

		//
		cout << endl << endl;
		cout << "Counts: " << endl << endl;
		cout << "	Number" << "		" << "Occurences" << endl;
		for (int i = 1; i < 11; i++) {

			cout << "	"  << "\""<<  i << "\"" << "		" << Count[i] << endl;

		}

		cout << endl << endl;
		cout << "Would you like to create another random array? 1 for 'Yes' or 0 for 'No': ";
		cin >> goAgain;

	} while (goAgain == 1);

	return 0;
}
