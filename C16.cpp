/*
Dan Elliott
November 8th, 2023
CIT-245
Week 10 - Templates (Chapter 16)
This program creates and tests a template function for running a binary search of various types.
*/


#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>


using namespace std;

template<class T>
void bsearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	int mid;
	if (first > last)
	{
		found = false;
	}
	else {
		mid = (first + last) / 2;
		if (key == a[mid]) {
			found = true;
			location = mid;
		}
		else if (key < a[mid]) {
			bsearch(a, first, mid - 1, key, found, location);
		}
		else if (key > a[mid]) {
			bsearch(a, mid + 1, last, key, found, location);
		}
	}
}

template<class T>
void printArray(const T a[], int arrayLength){

	

	for (int i = 0; i < arrayLength; i++)

		if (i == arrayLength - 1)
			cout << a[i] << endl;
		else
			cout << a[i] << ", ";

}

int main() {
	
	int intArray[] = { 0,1,4,5,12,14,15,24,45,55,55,63 };
	string Apple = "Apple";
	string Bike = "Bike";
	string Cat = "Cat";
	string Dog = "Dog";
	string Equator = "Equator";
	string Folk = "Folk";

	string strArray[] = { Apple,Bike,Cat,Dog,Equator,Folk};

	cout << "This program runs a binary search by utilizing a binary search template function." << endl;
	cout << "Two arrays will be tested. One of type int and the the other of type string." << endl;

	cout << endl << "int array: " << endl;
	printArray(intArray, 12);

	cout << endl << "string array: " << endl;
	printArray(strArray, 6);
	bool found = false;
	int location = 0;
	cout << endl;
	cout << "Binary search for key: 15 in int array. array location = ";

	bsearch(intArray, 0, 11, 15, found, location);
	if (found)
		cout << location << endl;
	else
		cout << "Not Found." << endl;
	cout << "TEST: intArray[" << location << "] = " << intArray[location];
	cout << endl<<endl;
	

	location = 0;
	found = false;
	cout << "Binary search for key: \"Equator\" in string array. array location = ";
	bsearch(strArray, 0, 5, Equator, found, location);

	if (found)
		cout << location << endl;
	else
		cout << "Not Found." << endl;
	cout << "TEST: strArray[" << location << "] = " << strArray[location];
	cout << endl << endl;
	


	return 0;
}