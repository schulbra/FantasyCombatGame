/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring 19
 * Description: Main.cpp
 * Project Three
 * **********************************************************/
 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Menu.hpp"
#include "InputValidation.hpp"
#include "GamePlay.hpp"

int main()
{
 Menu mainMenu("Welcome challenger.", 2);
 mainMenu.setOption(0, "Play Game");
 mainMenu.setOption(1, "Exit");
 bool exitChoice = false;
 string validateInput;
 int menuChoice;
 GamePlay game;
 mainMenu.printPrompt();
 do
  {
  mainMenu.printOptions();
  getline(cin, validateInput);
  menuChoice = getInt(validateInput);
  switch (menuChoice)
  {
  //Play game case. 
   case 1:
    cout << endl << endl;
	game.runGame();
	exitChoice = true;
	break;
  //Quit game case.
   case 2:
	exitChoice = true;
	break;
  //input validation.
   default:
	cout << "Plese choose a valid menu option. " << endl;
   }
 }
 //prompt saying goodbye to user if not continuing
 while (!exitChoice);
  cout << "Live to play another day. " << endl;
  return 0;
}
