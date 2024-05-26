/*
Dan Elliott
October 19, 2023
CIT-245
Week 7 - Managing mutliple files(Chapter 11)
This file is the main file that runs the program
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include "g.h"
#include "f.h"
#include<iostream>


using namespace std;

int main() {
	{
	using namespace g;
		hello();
	}
	{
		using namespace f;
		hello();
	}
	return 0;
}