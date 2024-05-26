/*
Dan Elliott
September 12, 2023
CIT-245
Week 2 - Dice Roll (Chapter 3)
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<iostream>
#include <iomanip>

using namespace std;
//returns int array for odds of a roll of total dice value 
int* odds(int rolls);
double PercentError(double rolls, double odds);
int main() {
	
	int goAgain = 0;


	do {
		//Sets seed for random number generation based on time
		int currentTime = time(NULL);
		srand(currentTime);
		int rolls;
		int RollTotals[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		int Error[13] = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
		double percentError;
		
		
		cout << "Please enter how many times you wish to roll the dice: ";
		cin >> rolls;

		int* totalOdds = odds(rolls);

		for (int i = 0; i < rolls; i++) {
			int diceRoll1 = (rand() % 6) + 1;
			int diceRoll2 = (rand() % 6) + 1;
			int diceRollTotal = diceRoll1 + diceRoll2;

			RollTotals[diceRollTotal]++;
		}
		//sets percent error to ten thousandths percision
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(4);

		cout << "Totals		#Rolled		Odds		%Error \n";

		for (int i = 2; i <= 12; i++) {

			cout << i << "		" << RollTotals[i] << "		" << totalOdds[i] << "		" <<  PercentError(RollTotals[i], totalOdds[i]) << endl;

			
		}


		cout << "Would you like to perform another simulation? 1 for 'Yes' or 0 for 'No': ";
		cin >> goAgain;

	} while (goAgain == 1);

	return 0;
}

int* odds(int rolls) {
	int* calcOdds = new int[13];
	double odds = 0;
	//increments odds up then down to create constant odds pattern of rolls per totals
	for (int i = 2; i < 13; i++) {
		if (i <= 7) {
			odds++;
		}
		else {
			odds--;
		}

		//fractional cast to double incase user enters outrageous number like "360000000", or else int values > memory capabilities.
		calcOdds[i] = rolls * (double)(odds / 36);
	}


	return calcOdds;
}

double PercentError(double rolls, double odds) {
	double percent = (odds - rolls) / odds * 100.0000;
	percent = fabs(percent);
	return percent;
}


