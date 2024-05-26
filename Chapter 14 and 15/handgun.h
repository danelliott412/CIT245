#pragma once
/*
Dan Elliott
October 26, 2023
CIT-245
Week 8 - Managing mutliple files(Chapter 14)
This file contains the header for the handgun class
*/
#ifndef HANDGUN_H
#define HANDGUN_H


#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include"gun.h"


using namespace std;

class handgun:public gun
{
public:
	handgun();
	handgun(string grip, string sight, bool las);
	void setGrips(string grip);
	string getGrips();
	void setSights(string sight);
	string getSights();
	void setLaser(bool las);
	void printGun(void)const;
	string getLaser();
private:
	string grips;
	string sights;
	bool laser;
};

#endif // !HANDGUN_H
