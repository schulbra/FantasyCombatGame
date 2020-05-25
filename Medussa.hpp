/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: Medussa.hpp
 * Project Three's header file utilized by Medussa.cpp
*  in Project Threes game program.
 * **********************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medussa :
	public Character
{
public:
 //Default constructor.
 Medussa();
 //destructor.
 ~Medussa();
 virtual string getName();
 virtual int attack();
};

#endif