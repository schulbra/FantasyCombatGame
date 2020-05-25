/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: Barbarian.cpp
 * Project Three's header file utilized by the barbarian
 * character in Project Threes game program.
 * **********************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"
class Barbarian :
	public Character
{
public:
 Barbarian();
 ~Barbarian();
 virtual string getName();
};

#endif