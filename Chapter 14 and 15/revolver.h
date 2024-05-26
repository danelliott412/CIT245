#pragma once
/*
Dan Elliott
November 4th, 2023
CIT-245
Week 9 - Polymorphism (Chapter 15)
This file contains the header to the revolver class
*/


#ifndef REVOLVER_H
#define REVOLVER_H


#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"handgun.h"


using namespace std;

class revolver :public handgun
{
public:
	revolver();
	revolver(bool singleA, int numRounds);
	void setSingleAction(bool singleA);
	string getSingleAction();
	void setNumberOfRounds(int numRounds);
	void printGun(void)const override;
	string getNumberOfRounds();
private:
	bool singleAction;
	int numberOfRounds;
};

#endif // !REVOLVER_H