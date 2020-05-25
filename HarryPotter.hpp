/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: Medussa.hpp
 * Project Three's header file utilized by Medussa.cpp
*  in Project Threes game program.
 * **********************************************************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "Character.hpp"
class HarryPotter :
	public Character
{
private:
	bool hogwarts = true;
public:
 HarryPotter();
 ~HarryPotter();
 virtual string getName();
 virtual void reduceStrength(int damageIn);
};

#endif