/*
Dan Elliott
November 4th, 2023
CIT-245
Week 9 - Polymorphism (Chapter 15)
This file is the gun class
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"gun.h"

using namespace std;


gun::gun() {
	manufacturer = "none";
	caliber = "none";
}

gun::gun(string manufac, string cal) {
	manufacturer = manufac;
	caliber = cal;
}
void gun::printGun(void)const {
	cout << manufacturer << ", ";
	cout << caliber << " cal, ";
}

void gun::setManufacturer(string manufac) {
	manufacturer = manufac;
}
string gun::getManufacturer() {
	return manufacturer;
}
void gun::setCaliber(string cal) {
	caliber = cal;
}
string gun::getCaliber() {
	return caliber;
}

