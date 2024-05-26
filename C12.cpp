/*
Dan Elliott
October 12, 2023
CIT-245
Week 7 - read and write (Chapter 12)
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<fstream>

using namespace std;


int main(){


    string goAgain;


    do {
        ifstream inStream;
        ofstream outStream;

        string inAdvice;
        cout << "Would you like to read or write to \"advice.txt\" ? "<< endl;
        cout << "Enter 'R' for Read and 'W' for Write: ";
        cin >> goAgain;

        if (goAgain == "R") {
            inStream.open("advice.txt");
            if (!inStream.fail()) {  // file exists…
                
                char next;
                cout << endl;
                inStream.get(next);
                while (!inStream.eof()) {
                    cout << next;
                    outStream << next;
                    inStream.get(next);
                }
                cout << endl << endl;
                inStream.close();
            }else {    // This file does NOT exist.
                inStream.close(); // close the input file stream
                outStream.open("advice.txt", ios::in | ios::out | ios::trunc);  // create new file
                cout << "Failed to open file, \"advice.txt\" was nonexistent. Creating a new instance now." << endl;
            }
        }
        else if (goAgain == "W") {

            cout << endl << endl << "PLease enter the advice you would like to add: ";
            cin.ignore();
            getline(cin, inAdvice);
            outStream.open("advice.txt");
            if (!outStream.fail()) {  // file exists…
                outStream << inAdvice;
                outStream.close();
            }
            else {    // This file does NOT exist.
                outStream.close(); // close the output file stream
                outStream.open("advice.txt", ios::in | ios::out | ios::trunc);  // create new file
                outStream << inAdvice;
            }
        }
            cout << "Would you like to read or write more advice?" << endl << "Enter 'Y' for Yes and 'N' for no: ";
            cin >> goAgain;
            cout << endl;
    } while (goAgain == "Y");
    return 0;
}