/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: Vampire.hpp
 * Header file used by the vampire class in Project Three's
 * fanatasy game program.
 * **********************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire :
	public Character
{
public:
 Vampire();
 ~Vampire();
 virtual string getName();
 virtual void reduceStrength(int damageIn);
};

#endif