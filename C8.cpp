/*
Dan Elliott
September 28, 2023
CIT-245
Week 4 - Money (Chapter 8)
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<iostream>

using namespace std;

class Money
{
public:
	Money(): dollars(0), cents(0){};
	Money(double amount) :dollars(dollarsPart(amount)), cents(centsPart(amount)){};
	Money(int theDollars, int theCents);
	Money(int theDollars) : dollars(theDollars), cents(0) {};
	double getAmount() const { return(dollars + cents); };
	int getDollars() const { return dollars; };
	int getCents() const { return cents; };
	void input();
	void output() const;
	const Money operator +(const Money& amount2) const;
	const Money operator -(const Money& amount2) const;
	bool operator >(const Money& amount2) const;
	bool operator <(const Money& amount2) const;
	const Money operator %(const int amount2) const;
	bool operator ==(const Money& amount2) const;
	const Money operator -() const;

	friend istream& operator >>(istream& inputStream, Money& amount);
	friend ostream& operator <<(ostream& outputStream, const Money& amount);

private:
	int dollars;
	int cents;

	int dollarsPart(double amount) const { return static_cast<int>(amount); };
	int centsPart(double amount) const;
	int round(double number) const{ return static_cast<int>(floor(number + 0.5)); };

};
//Main method
int main()
{
	Money AddAmount, SubtractAmount, PercentAmount, YourAmount, MyAmount(11,22);
	cout << "Please enter your money amount (include $): ";
		YourAmount.input();

		cout << "your amount is ";
		YourAmount.output();
		cout << endl;
		cout << endl;

		cout << "My amount is ";
		MyAmount.output();
		cout << endl;
		cout << endl;


		if (YourAmount == MyAmount)
			cout << "We have the same amount! \n";
		else {
			cout << "One of us is richer... \n";

			if (YourAmount > MyAmount)
				cout << "You have more money than me.";

			if (YourAmount < MyAmount)
				cout << "I have more money than you.";
		}
		cout << endl;

		PercentAmount = YourAmount % 25;
		cout << "25% of your money is: ";
		PercentAmount.output();
		cout << endl;

		AddAmount = YourAmount + MyAmount;
		YourAmount.output();
		cout << " + ";
		MyAmount.output();
		cout << " = ";
		AddAmount.output();
		cout << endl;
		SubtractAmount = YourAmount - MyAmount;
		YourAmount.output();
		cout << " - ";
		MyAmount.output();
		cout << " = ";
		SubtractAmount.output();
		cout << endl;


	return 0;
}

Money::Money(int theDollars, int theCents)
{
	if ((theDollars < 0 && theCents > 0) ||
		(theDollars > 0 && theCents < 0))
	{
		cout << "Inconsistent money data." << endl;
		exit(1);
	}
	dollars = theDollars;
	cents = theCents;
}

//percent operator for money object.
const Money Money::operator %(const int secondOperand) const
{
	int allCents = cents + dollars * 100;
	int percent = secondOperand;
	int newAllCents = (allCents * percent) / 100;
	int absAllCents = abs(newAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;


	return Money(finalDollars, finalCents);
}


//addition operator
const Money Money::operator +(const Money& secondOperand) const
{
	int allCents1 = cents + dollars * 100;
	int allCents2 = secondOperand.cents + secondOperand.dollars * 100;
	int sumAllCents = allCents1 + allCents2;
	int absAllCents = abs(sumAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;
	if (sumAllCents < 0)
	{
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}

	return Money(finalDollars, finalCents);
}


const Money Money::operator -() const
{
	return Money(-dollars, -cents);
}

//subtration operator
const Money Money::operator -(const Money& secondOperand) const
{
	int allCents1 = cents + dollars * 100;
	int allCents2 = secondOperand.cents + secondOperand.dollars * 100;
	int sumAllCents = allCents1 - allCents2;
	int absAllCents = abs(sumAllCents);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;
	if (sumAllCents < 0)
	{
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	return Money(finalDollars, finalCents);
}


//less than oerator
bool Money::operator <(const Money& secondOperand) const
{
	if (dollars < secondOperand.dollars)
		return true;

	if ((dollars == secondOperand.dollars) && (cents < secondOperand.cents))
		return true;

	else 
		return false;

}

//greater than operator
bool Money::operator >(const Money& secondOperand) const
{
	if (dollars > secondOperand.dollars)
		return true;

	if ((dollars == secondOperand.dollars) && (cents > secondOperand.cents))
		return true;

	else
		return false;

}
//equal to operator
bool Money::operator ==(const Money& secondOperand) const
{
	return ((dollars == secondOperand.dollars) && (cents == secondOperand.cents));

}

ostream& operator <<(ostream& outputStream, const Money& amount)
{
	int absDollars = abs(amount.dollars);
	int absCents = abs(amount.cents);
	if (amount.dollars < 0 || amount.cents < 0)
		outputStream << "$-";
	else
		outputStream << "$";
	outputStream << absDollars;

	if (absCents >= 10)
		outputStream << "." << absCents;
	else
		outputStream << "." << "0" << absCents;
	return outputStream;

}


istream& operator >>(istream& inputStream, Money& amount)
{
	char dollarSign;
	inputStream >> dollarSign;
	if (dollarSign != '$')
	{
		cout << "No dollar sign in Money input. \n";
		exit(1);
	}

	double amountAsDouble;
	inputStream >> amountAsDouble;
	amount.dollars = amount.dollarsPart(amountAsDouble);
	amount.cents = amount.centsPart(amountAsDouble);

	return inputStream;
}

int Money::centsPart(double amount) const
{
	double doubleCents = amount * 100;
	int intCents = (round(fabs(doubleCents))) % 100;
	if (amount < 0)
		intCents = -intCents;
	return intCents;
}

void Money::input()
{
	char dollarSign;
	cin >> dollarSign;
	if (dollarSign != '$')
	{
		cout << "No dollar sign in money input. \n";
		exit(1);
	}
	double amountAsDouble;
	cin >> amountAsDouble;
	dollars = dollarsPart(amountAsDouble);
	cents = centsPart(amountAsDouble);
}

void Money::output() const
{
	int absDollar = abs(dollars);
	int absCents = abs(cents);
	if (dollars < 0 || cents < 0)
	{
		cout << "$-";
	}
	else
	{
		cout << '$';
	}
	cout << absDollar;
	if (absCents >= 10)
		cout << '.' << absCents;
	else
		cout << '.' << '0' << absCents;
}
