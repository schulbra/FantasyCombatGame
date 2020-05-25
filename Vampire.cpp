/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: Vampire.cpp
 * Project Three
 * **********************************************************/

#include <iostream>
using std::cout;
using std::endl;
#include "Vampire.hpp"////////

//default constructor for vampire character
Vampire::Vampire()
{
	name = "Vampire";
	setNumAttackDie(1);
	setDieSides(12);
	setNumDefenseDie(1);
	setArmor(1);
	setStrength(18);
}

//vampire character destructor.
Vampire::~Vampire()
{
}

void Vampire::reduceStrength(int damageIn)
{
	if (damageIn > 0)
	{
		//charm function for vampire character attribute 
		//causing it to take no damage
		if (rand() % 2 == 0)
		{
			damageIn -= getArmor();
			setStrength(getStrength() - damageIn);
		}
		else
		{
			cout << "Vampire uses Charm. The opponents attack is sharply reduced!" << endl;
		}
	}
}

//Function for returning vampire class name.
string Vampire::getName()
{
	return name;
}
