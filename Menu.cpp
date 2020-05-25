/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring 19
 * Description: Menu.cpp
 * This is the class implementation file used to display a 
 * menu for Project Three's fantasy game.
 * **********************************************************/
 
 #include "Menu.hpp"
#include <iostream>

//Int taking constructor for setting # of menu options.
Menu::Menu(int numOptions)
{
 setPrompt("");
 setMenuSize(numOptions);
 options = new string[getMenuSize()];
}

//Prompt/# of options taking constructor.
Menu::Menu(string promptIn, int numOptions)
{
 setPrompt(promptIn);
 setMenuSize(numOptions);
 options = new string[getMenuSize()];
}

//Matches array option to input string.
void Menu::setOption(int optionNumber, string optionIn) const
{
 if (optionNumber < getMenuSize())
 {
  options[optionNumber] = optionIn;
 }
}

//Displays prompt.
void Menu::printPrompt() const
{
 std::cout << getPrompt() << std::endl;
}

//Prints menu options.
void Menu::printOptions() const
{
 for (int i = 0; i < getMenuSize(); i++)
 {
  if (options[i] != "")
  {
	std::cout << i + 1 << ". ";
	std::cout << options[i] << std::endl;
  }
 }
}