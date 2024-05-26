/*
Dan Elliott
October 4, 2023
CIT-245
Week 5 - STL Stack (Chapter 9)
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<stack>
#include<iostream>

using namespace std;

stack<char> reverse(char* s);

int main() {

	int goAgain = 0;
	char* s = (char*)malloc(80);
	stack<char> rS;
	int clear; //Used to read input to clear it
	do {
		cout << "This program reverses a string using the STL stack."<< endl
			<< "Enter your string of less than 80 characters followed by an Enter : " << endl;
		
		cin.getline(s,81,'\n');
		cout << endl << "You entered:" << endl;
		cout << s << endl << endl;
		cout << "Your input reversed:" << endl;
		rS = reverse(s);

		//After STL Stack reverse, print out each character while the stack is not empty
		while (!rS.empty()) {
			//read the top character
			cout << rS.top();
			//remove top character from stack
			rS.pop();
		}

		cout << " \n\n Enter another string? Enter 1 for 'Yes' or 0 for 'No' : ";
		cin >> goAgain;
		clear = getchar();
	} while (goAgain == 1);
	//reset memory allolcation
	free(s);
	return 0;
}

stack<char> reverse(char* s) {
	stack<char> rS;

	for (int i = 0; i < strlen(s); i++)
		rS.push(s[i]);	

	return rS;
}