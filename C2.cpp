/*
Dan Elliott
September 6, 2023
CIT-245
Week 1 - Buoyancy calculator (Chapter 2)
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<iostream>

using namespace std;

const double PI = 3.141592;

double BuoyancyCalc(double input);

int main() {
	int goAgain;
	double radius;
	double buoyantForce;
	double weight;
	//Do-While loop so user can use program multiple times.
	do {
		cout << "This program computes buoyancy of a sphere based on its radius and weight.\n\n";
		cout << "Please enter the radius of the sphere(ft): ";
		cin >> radius;
		cout << "Please enter your sphere's weight(lbs): ";
		cin >> weight;

		buoyantForce = BuoyancyCalc(radius);

		if (weight <= buoyantForce) {
			cout << "Your sphere floats in water! \n Its buoyant force is  " << buoyantForce << " lbs which is greater than its weight of  " << weight << " lbs." << endl;
		}
		else {
			cout << "Your sphere will sink in water. \n Its buoyant force is  " << buoyantForce << " lbs which is less than its weight of  " << weight << " lbs." << endl;
		}

		cout << "Need to recalculate? 0 = No, 1 = Yes \n";

		cin >> goAgain;

	} while (goAgain == 1);
	return 1;
}

double BuoyancyCalc(double input) {
	//Volume formula for sphere
	double volume = 4.0  * PI / 3.0 * pow(input, 3.0);
	//Calculate buoyancy
	double buoyancy = volume * 62.4;
	return buoyancy;
}

