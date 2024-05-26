/*
Dan Elliott
November 4th, 2023
CIT-245
Week 9 - Polymorphism (Chapter 15)
This file contains the revolver class
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"revolver.h"


using namespace std;

revolver::revolver() {
	singleAction = false;
	numberOfRounds = 0;
}

void revolver::printGun(void)const{
	cout << "Revolver: ";
	gun::printGun();
	handgun::printGun();
	if (singleAction) {
		cout << "is single action" << ", ";
	}
	else {
		cout << "is not single action" << ", ";
	}
	cout << numberOfRounds <<" shots" << endl;
}

revolver::revolver(bool singleA, int numRounds){
	singleAction = singleA;
	numberOfRounds = numRounds;
}
void revolver::setSingleAction(bool singleA){
	singleAction = singleA;
}
string revolver::getSingleAction() {
	if (singleAction) {
		return "single action";
	}
	return "not single action";
}
void revolver::setNumberOfRounds(int numRounds) {
	numberOfRounds = numRounds;
}
string revolver::getNumberOfRounds() {


	return to_string(numberOfRounds) + " shot";
}