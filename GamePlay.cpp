/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: GamePlay.cpp
 ************************************************************/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <ctime>//
#include "InputValidation.hpp"
#include "GamePlay.hpp"
#include "Menu.hpp"
#include "Character.hpp"
#include "Vampire.hpp"		
#include "Barbarian.hpp"	
#include "BlueMen.hpp"		
#include "Medussa.hpp"
#include "HarryPotter.hpp"


//Default constructor. sets random seed once to ensure 
//dice values are random throughout course of program.
GamePlay::GamePlay()
{
 srand(time(nullptr));
}

//destructor.
GamePlay::~GamePlay()
{
}

//function for running game.
void GamePlay::runGame()
{
 bool playAgain = false;
 do
 {
  int heroes[2];
  cout << "Welcome to Super Fantasy Game Melee 64!" << endl;
  cout << "-------------------------------" << endl;
  for (int i = 0; i < 2; i++)
  {
	//prints available characters that user can select from.
	heroes[i] = printHeroes(i);
  }

 //characters allocated to base class pointer values to manage gameplay.
 setFighter1(heroes[0]);
 setFighter2(heroes[1]);
 int roundCounter = 1;
 bool nextRound = true;
 int attackerRoll,
 defenderRoll;

 //funciton that keeps round active until user exits, or character passes.
 while (fighter1->alive() && fighter2->alive() && nextRound)
  {
   string validateInput;
   cout << "Round " << roundCounter++ << endl << endl;
    //Character 1 attacks | character 2 defends.
    attackerRoll = fighter1->attack();
    defenderRoll = fighter2->defend();
    cout << fighter1->getName() << " attacks, " << fighter2->getName() << " defends." << endl;
    printStats(fighter1, attackerRoll, fighter2, defenderRoll);
	//Character 2 attacks | character 1 defends.
    attackerRoll = fighter2->attack();
    defenderRoll = fighter1->defend();
    cout << fighter2->getName() << " attacks, " << fighter1->getName() << " defends." << endl;
   printStats(fighter2, attackerRoll, fighter1, defenderRoll);

   //check for characters state, if passed user is found not alive user is notified.
   if (!fighter1->alive())
   {
	 cout << fighter1->getName() << " KO!" << endl;
   }
   else if (!fighter2->alive())
   {
	 cout << fighter2->getName() << " KO!" << endl;
   }

   //user is asked to play another round after/if char died.
   if (fighter1->alive() && fighter2->alive())
    {
	do
	{
	 cout << "Continue? (y/n) ";
	 getline(cin, validateInput);
	 if (validateInput.length() > 1 || (tolower(validateInput[0] != 'y') && tolower(validateInput[0] != 'n')))
     {
	   cout << "Select from y or n only." << endl;
	 }
	} while (validateInput.length() > 1 || (tolower(validateInput[0] != 'y') && tolower(validateInput[0] != 'n')));
   }
   //game exist if user enters "n"
   if (validateInput == "n")
   {
	nextRound = false;
   }
 }

 //input validation for game menu and continuing/exiting options.
 //continues in loop allowing users to play game endlessly if y is
 //only selected.
 string validateInput;
 do
 {
  cout << endl;
  cout << "Continue? (y/n) ";
  getline(cin, validateInput);
	if (validateInput.length() > 1 || (tolower(validateInput[0] != 'y') && tolower(validateInput[0] != 'n')))
	 {
	  cout << "Select from y or n only." << endl;
	 }
	} while (validateInput.length() > 1 || (tolower(validateInput[0] != 'y') && tolower(validateInput[0] != 'n')));
	if (validateInput == "y")
	 {
	  playAgain = true;
	 }
 //game ends.
 else
  {
	playAgain = false;
  }
 cout << endl << endl;
 //character data whiped.
 delete fighter1;
 delete fighter2;
 } while (playAgain);
}

//player one gets set to chosen character type.
void GamePlay::setFighter1(int fighterIn)
{
 switch (fighterIn)
 {
 case 1: fighter1 = new Vampire;
	 break;

 case 2: fighter1 = new Barbarian;
	 break;

 case 3: fighter1 = new BlueMen;
	 break;

 case 4: fighter1 = new Medussa;
	 break;

 case 5: fighter1 = new HarryPotter;
 }
}

//player two gets set to chosen character type.
void GamePlay::setFighter2(int fighterIn)
{
 switch (fighterIn)
 {
 case 1: fighter2 = new Vampire;
	 break;

 case 2: fighter2 = new Barbarian;
	 break;

 case 3: fighter2 = new BlueMen;
	 break;

 case 4: fighter2 = new Medussa;
	 break;

 case 5: fighter2 = new HarryPotter;
 }
}

//character list is printed and chosen fighter types
//displayed to user(s)
int GamePlay::printHeroes(int heroNum)
{
 Menu heroMenu(5);
 heroMenu.setOption(0, "Vampire");
 heroMenu.setOption(1, "Barbarian");
 heroMenu.setOption(2, "Blue Men");
 heroMenu.setOption(3, "Medussa");
 heroMenu.setOption(4, "Harry Potter");
 int heroChoice = 0;
 string validateInput;
 do
  {
	 heroMenu.printOptions();
	 cout << "Choose your character! (0-4): ";
	 getline(cin, validateInput);
	 heroChoice = getInt(validateInput);
	 if (heroChoice < 1 || heroChoice > 5)
	 {
	  cout << "Please enter a listed menu choice. (0-4)" << endl;
	 }
 } while (heroChoice < 1 || heroChoice > 5);
 return heroChoice;
}

//function for displaying character stats at the end of each round.
void GamePlay::printStats(Character * attacker, int attackRoll,
	Character * defender, int defendRoll)
{
 cout << "--------------------------------" << endl;
 cout << "Attacker: " << attacker->getName() << endl;
 cout << "Attacker Roll Value: " << attackRoll << endl << endl;
 cout << "Defender: " << defender->getName() << endl;
 cout << "Defender Armor Value: " << defender->getArmor() << endl;
 cout << "Defender Strength Value: " << defender->getStrength() << endl;
 cout << "Defender Roll Value: " << defendRoll << endl << endl;
 cout << "Total Damage Given: " << attackRoll - defendRoll << endl;
 defender->reduceStrength(attackRoll - defendRoll);
 cout << "Defenders New Strength Value: " << defender->getStrength() << endl;
 cout << endl;
}