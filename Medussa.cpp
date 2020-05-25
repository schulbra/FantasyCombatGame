/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: Medussa.cpp
 * Project Three's class implementation file for the medussa 
 * character in Project Threes game program.
 * **********************************************************/

#include <iostream>
using std::cout;
using std::endl;
#include "Medussa.hpp"

//Default constructor.
Medussa::Medussa()
{
 name = "Medussa";
 setNumAttackDie(2);
 setDieSides(6);
 setNumDefenseDie(1);
 setArmor(3);
 setStrength(8);
}

//Destructor.
Medussa::~Medussa()
{
}

//Medussa's attack function.
int Medussa::attack()
{
 int attackRoll = 0;
 for (int i = 0; i < getNumAttackDie(); i++)
 {
  //Function increases until 12 rolls has occured, at 12
  //attack function is performed.
  attackRoll += rand() % getDieSides() + 1;
  //glare ability.
  if (attackRoll == 12)
  {
	cout << "Medussa used Glare! The opponent is paralyzed and unable to attack." << endl;
	return 50;
  }
 }
 return attackRoll;
}

//Medussa class name returned.
string Medussa::getName()
{
 return name;
}