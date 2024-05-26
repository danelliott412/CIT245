#pragma once
/*
Dan Elliott
November 4th, 2023
CIT-245
Week 9 - Polymorphism (Chapter 15)
This file contains the header to the pistol class
*/


#ifndef PISTOL_H
#define PISTOL_H


#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"handgun.h"


using namespace std;

class pistol :public handgun
{
public:
	pistol();
	pistol(bool semiAuto);
	void setSemiAuto(bool semiAuto);
	void printGun(void)const override;
	string getSemiAuto();
private:
	bool semiAuto = false;
};

#endif // !PISTOL_H

