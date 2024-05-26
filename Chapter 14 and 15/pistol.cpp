/*
Dan Elliott
November 4th, 2023
CIT-245
Week 9 - Polymorphism (Chapter 15)
This file contains the pistol class
*/



#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"pistol.h"


using namespace std;

pistol::pistol() {
	semiAuto = false;
}
pistol::pistol(bool semiA) {
	semiAuto = semiA;
}

void pistol::printGun(void)const{
	cout << "Pistol: ";
	gun::printGun();
	handgun::printGun();
	if (semiAuto) {
		cout << "is Semi Auto" << endl;
	}
	else {
		cout << "is not Semi Auto" << endl;
	}
}

void pistol::setSemiAuto(bool semiA) {
	semiAuto = semiA;
}

string pistol::getSemiAuto() {
	if (semiAuto) {
		return "SemiAutomatic";
	}
	return "not SemiAutomatic";
}