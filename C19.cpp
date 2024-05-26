/*
Dan Elliott
December 5th, 2023
CIT-245
Week 14 - Templates (Chapter 19)
This program creates and tests a  map template class for storing names and social security numbers.
*/


#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<map>


using namespace std;

int main()
{


	map<string, string> person;


	person["Paul Brown"] = "123-45-6790";
	person["Mary Smith"] = "123-45-6791";
	person["John Smith"] = "123-45-6789";
	person["Lisa Brown"] = "123-45-6792";

	//Iterator section of program
	cout << "Iterate through all people and their ssn's: " << endl;
	map<string, string>::const_iterator iter;
	for (iter = person.begin(); iter != person.end(); iter++) {
		cout << iter->first << " - " << iter->second << endl;
	}


	string personToFind = "Paul Brown";

	cout << endl << "Trying to find: " << personToFind << endl;

	if (person.find(personToFind) != person.end())
		cout << personToFind << " was found. ssn: " << person[personToFind] << endl;
	else
		cout << personToFind << "Joe Smith was not found"<<endl;

	personToFind = "Joe Smith";

	cout << endl << "Trying to find: " << personToFind << endl;

	if (person.find(personToFind) != person.end())
		cout << personToFind << " was found. ssn: "<< person[personToFind] <<endl;
	else
		cout << personToFind << " was not found"<<endl;

	return 0;
}