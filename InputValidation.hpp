/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: InputValidation.hpp
 * Project Three header file Input Validation.
 * **********************************************************/

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP

#include <string>
using std::string;

bool checkStringToInt(string);

int getInt(string);
double getDouble(string);

void getNum(int &num);

#endif