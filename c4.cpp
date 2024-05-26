/*
Dan Elliott
September 14, 2023
CIT-245
Week 2 - Fraction reduction (Chapter 4)
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<iostream>

int gcd(int a, int b);

using namespace std;
int main() {

	int goAgain = 0;
	do {
		int num = 0;
		int den = 0;
		cout << "This program reduces a numerator and denominator by finding the greatest common denominator. \n";
		cout << "Enter numerator: ";
		cin >> num;
		cout << "Enter denominator: ";
		cin >> den;
		int g = gcd(num, den);

		cout << " The greatest common denominator is " << g << endl;

		num = num / g;
		den = den / g;

		cout << "Your reduced fraction is " << num << "/" << den << endl;

		cout << "Would you like to reduce another fraction? 1 for 'Yes' or 0 for 'No': ";
		cin >> goAgain;
		
	} while(goAgain == 1);

	return(0);
}

int gcd(int a, int b) {

	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}

	return(a);
}