/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: InputValidation.cpp
 * Project Three
 * **********************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::to_string;

#include <climits>
#include <cfloat>

#include "InputValidation.hpp"

//checks for input of value 1-9.
bool checkStringToInt(string stringIn)
{
if (stringIn == "")
 {
  return false;
 }
 for (char c : stringIn)
 {
  int asciiValue = int(c);
  if (asciiValue < 48 || asciiValue > 57)
  {
   return false;
  }
 }
 return true;
}

//Checks string for int and ints size. will only return int
//value, -1 is returned otherwise.
int getInt(string stringIn)
{
 if (checkStringToInt(stringIn))
 {
  string maxInt = to_string(INT_MAX);
  if (stringIn.length() < maxInt.length())
   {
	int validInt = stoi(stringIn);
	if (validInt > INT_MAX || validInt < INT_MIN)
	 {
	  return -1;
	 }
  return validInt;
   }
  }
 return -1;
}

//compares int value against double range.
double getDouble(string stringIn)
{
 int period = stringIn.find('.');
 string quotient = stringIn.substr(0, period),
 dividend = stringIn.substr(period + 1, stringIn.size() - period - 1);
if (checkStringToInt(quotient) && checkStringToInt(dividend))
 {
  string maxDouble = to_string(DBL_MAX);
  if (stringIn.length() < maxDouble.length())
  {
   double validDouble = stod(stringIn);
   if (validDouble > DBL_MAX || validDouble < DBL_MIN)
   {
	return -1;
   }
  return validDouble;
  }
 }
 return -1;
}

//input validation function for non int, -int user input.
void getNum(int& numIn)
{
 bool valid = false;
 string validateInput;
 int num;
 do
	{
	 getline(cin, validateInput);
	 if (validateInput[0] == '-')
	  {
	  num = -1 * getInt(validateInput.substr(1, validateInput.length()));
      if (!checkStringToInt(validateInput.substr(1, validateInput.length()))
		  //problem
		|| getInt(validateInput.substr(1, validateInput.length())) == -1)
	  {
	   cout << "Please enter a valid int option." << endl;
	  }
	  else
	  {
	   valid = true;
      }
	 }
 else
 {
  num = getInt(validateInput);
  if (!checkStringToInt(validateInput)
  //
	|| getInt(validateInput) == -1)
   {
	cout << "Please enter a valid int option." << endl;
   }
  else
  {
	valid = true;
  }
 }
} while (!valid);
  numIn = num;
}