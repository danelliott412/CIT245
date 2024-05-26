#pragma once
/*
Dan Elliott
November 4th, 2023
CIT-245
Week 9 - Polymorphism (Chapter 15)
This file contains the handgun class
*/
#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"handgun.h"


using namespace std;


handgun::handgun() {
	grips = "No grips";
	sights = "No sight";
	laser = false;
}
void handgun::printGun(void)const {
	cout << grips << ", ";
	cout << sights << ", ";
	if (laser) {
		cout << "has laser" << ", ";
	}
	else {
		cout << "no laser" << ", ";
	}
}

handgun::handgun(string grip, string sight, bool las) {
	grips = grip;
	sights = sight;
	laser = las;
}
void handgun::setGrips(string grip) {
	grips = grip;
}
string handgun::getGrips() {
	return grips;
}
void handgun::setSights(string sight) {
	sights = sight;
}
string handgun::getSights() {
	return sights;
}
void handgun::setLaser(bool las) {
	laser = las;
}
string handgun::getLaser() {

	if (laser) {
		return "has laser";
	}

	return "no laser";
		

}