/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: Character.hpp
 * Project Three's header file utilized by the character class
 * in Project Threes game program.
 * **********************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
using std::string;
#include <cstdlib>

class Character
{
protected:
 string name;
//functions that each class uses to set base attribute values.
private:
 int numAttackDie;
 int dieSides;
 int numDefenseDie;
 int armor;
 int strength;
public:
 //default constructor
 Character();
 //destructor.
 ~Character();
 //functions for managing flow of game, char health status,
 int getNumAttackDie() const { return numAttackDie; }
 int getDieSides() const { return dieSides; }
 int getNumDefenseDie() const { return numDefenseDie; }
 int getArmor() const { return armor; }
 int getStrength() const { return strength; }
 void setNumAttackDie(int numAttackDieIn) { numAttackDie = numAttackDieIn; }
 void setDieSides(int dieSidesIn) { dieSides = dieSidesIn; }
 void setNumDefenseDie(int numDefenseDieIn) { numDefenseDie = numDefenseDieIn; }
 void setArmor(int armorIn) { armor = armorIn; }
 void setStrength(int strengthIn) { strength = strengthIn; }
 bool alive();
 virtual void reduceStrength(int damageIn);
 virtual int attack();
 virtual int defend();
 virtual string getName() = 0;
};

#endif