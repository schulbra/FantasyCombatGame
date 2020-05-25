/*************************************************************
 * Name: Brandon Schultz
 * Date: 5-7-19 CS 162 OSU Spring19
 * Description: GamePlay.hpp
 ************************************************************/

#include <memory>
using std::shared_ptr;
#include "Character.hpp"

class GamePlay
{
private:
	Character* fighter1 = nullptr;
	Character* fighter2 = nullptr;
public:
 //default constructor
 GamePlay();
 //destructor
 ~GamePlay();
 //get methods for characters.
 Character* getFighter1() const { return fighter1; }
 Character* getFighter2() const { return fighter2; }
 //set methods for characters
 void setFighter1(int fighterIn);
 void setFighter2(int fighterIn);
 //Functions for running game, gameplay methods.
 void runGame();
 int printHeroes(int heroNum);
 void printStats(Character* attacker, int attackRoll,
 Character* defender, int defendRoll);
};