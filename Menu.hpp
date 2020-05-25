/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring 19
 * Description: Menu.hpp
 * This is the header file utilized by Menu.cpp for Project 
 * Three's fantasy game.
 * **********************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

class Menu
{
 private:
  string prompt;
  int menuSize;
  string* options;
 public:
  //default constructor.
  Menu(int numOptions);
  //prompt accepting Constructor.
  Menu(string promptIn, int numOptions);
  //Destructor.
  ~Menu() { delete[] options; }
  //Getter methods for displaying menu options
  string getPrompt() const { return prompt; }
  string* getOptions() const { return options; }
  int getMenuSize() const { return menuSize; }
  //Setter methods for displaying menu options
  void setPrompt(string promptIn) { prompt = promptIn; }
  void setMenuSize(int sizeIn) { menuSize = sizeIn; }
  void setOption(int optionNumber, string optionIn) const;
  void printPrompt() const;
  void printOptions() const;
};

#endif