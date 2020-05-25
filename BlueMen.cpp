/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: BlueMen.cpp
 * Project Three's class implementation file for the BlueMen
 * character type utilized in Project Threes game program.
 * **********************************************************/

#include <iostream>
using std::cout;
using std::endl;


#include "BlueMen.hpp"

//default constructor
BlueMen::BlueMen()
{
 name = "Blue Men";
 setNumAttackDie(2);
 setDieSides(10);
 setNumDefenseDie(3);
 setArmor(3);
 setStrength(12);
}

//Destructor for bluemen.
BlueMen::~BlueMen()
{
}
//Bluemen attributes function. Unlike other classes
//this character begins with ability, can only loose it
//when # of bluemen, or strength values < 4.
void BlueMen::reduceStrength(int damageIn)
{
 if (damageIn > 0)
 {
  damageIn -= getArmor();
  cummulativeDamage += damageIn;
  setStrength(getStrength() - damageIn);
  //if strength is above 4, no reduction.
  if (cummulativeDamage >= 4)
  {
	cout << "The BlueMen's ranks are being depleted!" << endl;
  }
  //when strength decreases to a valuless than 4,
  //character type looses a dice roll.
  setNumDefenseDie(getStrength() / 4);
 }
}

//Returns BlueMen class name.
string BlueMen::getName()
{
	return name;
}