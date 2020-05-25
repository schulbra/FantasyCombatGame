/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: Character.cpp
 * Project Three's class implementation file for the generic,
 * character type in Project Threes game program. This file acts
 * as a template that all characters/heros use to obtain attribute
 * values for strength, defense, armor, and attack. This file
 * also assists in keeping track of characters dead/alive state.
 * **********************************************************/

#include "Character.hpp"

//default constructor.
Character::Character()
{
}

//destructor.
Character::~Character()
{
}

//Generic attack function based off incremental die roll value.
int Character::attack()
{
 int attackRoll = 0;
 for (int i = 0; i < getNumAttackDie(); i++)
 {
  attackRoll += rand() % getDieSides() + 1;
 }
 return attackRoll;
}

//function for tracking character health. damage taken
//is subtracted by an armor value, or hp.
void Character::reduceStrength(int damageIn)
{
 if (damageIn > 0)
 {
  damageIn -= getArmor();
  setStrength(getStrength() - damageIn);
 }
}


//Generic defend function.
int Character::defend()
{
 int defendRoll = 0;
 for (int i = 0; i < getNumDefenseDie(); i++)
 {
  defendRoll += rand() % 6 + 1;
 }
 return defendRoll;
}

//function for checking if character is still active.
//if armor (hp) > 0 character is considered dead.
bool Character::alive()
{
 if (getStrength() < 1)
 {
  return false;
 }
 return true;
}