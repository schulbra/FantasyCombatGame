/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: BlueMen.hpp
 * Project Three's header file utilized by the BlueMen class
 * in Project Threes game program.
 * **********************************************************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Character.hpp"
class BlueMen :
	public Character
{
private:
	int cummulativeDamage = 0;
public:
 BlueMen();
 ~BlueMen();
 virtual string getName();
 virtual void reduceStrength(int damageIn);
};

#endif