/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: HarryPotter.cpp
 * Project Three's class implementation file for the Harry 
 * Potter character in Project Threes game program.
 * **********************************************************/

#include <iostream>
using std::cout;
using std::endl;

#include "HarryPotter.hpp"

//default constructor
HarryPotter::HarryPotter()
{
 name = "Harry Potter";
 setNumAttackDie(2);
 setDieSides(6);
 setNumDefenseDie(2);
 setArmor(0);
 setStrength(10);
}

//destructor.
HarryPotter::~HarryPotter()
{
}

//function for harry potters strength ability.
void HarryPotter::reduceStrength(int damageIn)
{
 if (damageIn > 0)
 {
  damageIn -= getArmor();
  setStrength(getStrength() - damageIn);
  //If harry is koed...
  if (getStrength() < 1)
  {
	if (hogwarts)
	{
	 cout << "Harry is no more!";
	 cout << "Just Kidding!" << endl;
	 //harry is max revived with x2 gains.
	 setStrength(20);
	 hogwarts = false;
	}
  }
 }
}
//harrypotter c name returned.
string HarryPotter::getName()
{
	return name;
}
