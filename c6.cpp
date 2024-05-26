/*
Dan Elliott
September 22, 2023
CIT-245
Week 3 - Class for video game player (Chapter 6)
*/

#pragma warning(disable: 4996)
#include<string>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<iostream>


using namespace std;
class Player
{
//all class variables are private
private:
	string name = "";
	string password = "";
	int experience = 0;
	string inventory[4] = {"", "", "", ""};
	int positionX = 0;
	int positionY = 0;
// Public accessors and mutators
public:
	void setName(string Name) { name = Name; };
	string getName() { return name; };
	void setPassword(string Password) { password = Password; };
	string getPassword() { return password; };
	void setExperience(int Experience) { experience = Experience; };
	int getExperience() { return experience; };
	void setPosition(int PositionX, int PositionY);
	int* getPosition();
	void setInventory(string Item1, string Item2, string Item3, string Item4);
	string* getInventory();
	void output();
};


int* Player::getPosition()
{
	int position[2] = { positionX, positionY };
	return position;
}
void Player::setPosition(int PositionX, int PositionY)
{
	positionX = PositionX;
	positionY = PositionY;
}
//Assigns string items to string array "Inventory" max of 4 items
void Player::setInventory(string Item1, string Item2, string Item3, string Item4)
{
	inventory[0] = Item1;
	inventory[1] = Item2;
	inventory[2] = Item3;
	inventory[3] = Item4;
}
string* Player::getInventory()
{
	return inventory;
}
//Outputs Player info
void Player::output()
{
	cout << "Player Stats: " << endl;
	cout << " Player Name: " << name << endl;
	cout << " Password: " << password << endl;
	cout << " Experience: " << experience << endl;
	cout << " Position: " << positionX << ", " << positionY << endl;
	cout << " Inventory: ";
	for (int i = 0; i < 3; i++)
	{
		cout << inventory[i] << ", ";
	}
	cout << inventory[3] << endl << endl;
}


int main() {

	cout << "This program tests the Player class by creating 3 players and assigning them various attributes." << endl << endl;
	string name;
	Player Garfunkel, Simon, Dianne;
	Garfunkel.setName("Garfunkel");
	Garfunkel.setPassword("HarryPotter22");
	Garfunkel.setExperience(121);
	Garfunkel.setPosition(5032, -23);
	Garfunkel.setInventory("Sword", "Axe", "Hammer", "Potion");

	Garfunkel.output();

	Simon.setName("Simon");
	Simon.setPassword("DogBone12");
	Simon.setExperience(89);
	Simon.setPosition(125, 652);
	Simon.setInventory("Tooth pick", "Tic Tac", "T-shirt", "Bottle");

	Simon.output();

	Dianne.setName("Dianne");
	Dianne.setPassword("BaldingHarry");
	Dianne.setExperience(1100);
	Dianne.setPosition(-234, -5004);
	Dianne.setInventory("Crown", "Cape", "Sword", "Shield");

	Dianne.output();



	cout << name << endl;

	return 0;
}