#pragma once
/*
Dan Elliott
November 4th, 2023
CIT-245
Week 9 - Polymorphism (Chapter 15)
This file is the headre file for the gun class
*/
#ifndef GUN_H
#define GUN_H


#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>


using namespace std;

class gun
{
public:
	gun();
	gun(string manufac, string cal);
	void setManufacturer(string manufac);
	string getManufacturer();
	void setCaliber(string cal);
	string getCaliber();
	void virtual printGun(void)const = 0;

private:
	string manufacturer;
	string caliber;
};

#endif // !GUN_H