/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: Barbarian.cpp
 * Project Three's class implementation file for the barbarian
 * character in Project Threes game program.
 * **********************************************************/

#include "Barbarian.hpp"

//barbarian attribute values.
Barbarian::Barbarian()
{
 name = "Barbarian";
 setNumAttackDie(2);
 setDieSides(6);
 setNumDefenseDie(2);
 setArmor(0);
 setStrength(12);
}

//destructor
Barbarian::~Barbarian()
{
}

//return class name
string Barbarian::getName()
{
 return name;
}