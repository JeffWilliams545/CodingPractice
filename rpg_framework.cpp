//Author - Jeffrey Williams
//Code based off of coding challenge from edabit.com rpg_framwork

#include "rpg_framework.h"

using namespace std;

int main( int argc, char* argv[] )
{
	srand( time( 0 ) );
	GameEngine rpg;
	Player jeff;
	jeff.load( string( "Jeff" ), 10, 2, 1, 1, 0, string( "Get rekt." ), string( "Oof owch owie my bones." ) );
	rpg.addPlayer( jeff );
	Enemy ruby;
	ruby.load( string( "Ruby" ), 5, 1, 1, 1, 1, string ( "Bark!" ), string( "Woof." ) );
	rpg.addEnemy( ruby );
	rpg.combat( jeff, ruby );
	rpg.menu();
	return 1;
}

void GameEngine::addPlayer( Player &player )
{
	playerList.push_back( player );
}

void GameEngine::addEnemy( Enemy &enemy )
{
	enemyList.push_back( enemy );
}

void GameEngine::attack( Player &primary, Enemy &secondary )
{
	if( primary.isDead() )
	{
		primary.defeat( secondary );
		return;
	}	
	int dmg = max( 1, primary.getAtk() - secondary.getDef() );
	secondary.setHP( secondary.getHP() - dmg );
	cout << primary.getName() << " attacked " << secondary.getName() << " and dealt " << dmg << " damage!" << endl;
	if ( secondary.isDead() )
	{	
		primary.victory( secondary );
		return;
	}
	dmg = max( 1, secondary.getAtk() - primary.getDef() );
	primary.setHP( primary.getHP() - dmg );
	cout << secondary.getName() << " attacked " << primary.getName() << " and dealt " << dmg << " damage!" << endl;
}

void GameEngine::combat( Player &primary, Enemy &secondary )
{
  	int turnCount = 0;
  	while ( !primary.isDead() && !secondary.isDead() )
  	{
    		attack( primary, secondary );
    		turnCount++;
  	}	
  	return;
}
void GameEngine::menu()
{
	// menuIndex used for switch statement
	// validInput used to check for valid user input
	// userGuess and randNumber used for the silly game (random number generation guessing)
	int menuIndex, userGuess, randNumber;
	bool validInput;

	// Printing menu to terminal
	cout << "-----------------------------------------------" << endl;
	cout << "Welcome to the menu." << endl << endl;
	cout << "Please select from the following options." << endl << endl;
	cout << "1 - See a picture of a rose." << endl;
	cout << "2 - Play a silly game." << endl;
	cout << "0 - Exit program." << endl;
	cout << "-----------------------------------------------" << endl;

	// Input from user
	validInput = false;
	while( !validInput )
	{
		cin >> menuIndex;
		if( menuIndex > 2 || menuIndex < 0 )
		{
			cout << endl << "invalid input. Please try again." << endl;
		}
		else
		{
			validInput = true;
		}
	}

	// Switch statement for menu options
	switch ( menuIndex )
	{
		// Case of silly game using random number generation
		case 2:
		{
			cout << endl << "Guess the number I am thinking of between 1 and 10" << endl;
			randNumber = (rand() % 10) + 1;
			cin >> userGuess;
			if( randNumber == userGuess )
				cout << endl << "You won! Please pat yourself on your back." << endl << endl;
			else
				cout << endl << "You lost. Better luck next time!" << endl << endl;
			usleep(2000000);
			menu();
		}
	}
}

int GameEngine::generateRandomInt( int high )
{
	return ( rand() % high ) + 1;
}

void CharBase::setHP( int hp )
{
	this->hp = hp;
}

void CharBase::setAtk( int atk )
{
	this->atk = atk;
}

void CharBase::setDef( int def )
{
	this->def = def;
}

void CharBase::setLevel( int lvl )
{
	this->lvl = lvl;
}

void CharBase::setXP( int xp )
{
	this->xp = xp;
}

void CharBase::setName( string name )
{
	this->name = name;
}

void CharBase::setVictoryQuote( string victoryQuote )
{
	this->victoryQuote = victoryQuote;
}

void CharBase::setDefeatQuote( string defeatQuote )
{
	this->defeatQuote = defeatQuote;
}

int CharBase::getHP()
{
	return hp;
}

int CharBase::getAtk()
{
	return atk;
}

int CharBase::getDef()
{
	return def;
}

int CharBase::getLevel()
{
	return lvl;
}

int CharBase::getXP()
{
	return xp;
}

string CharBase::getName()
{
	return name;
}

string CharBase::getVictoryQuote()
{
	return victoryQuote;
}

string CharBase::getDefeatQuote()
{
	return defeatQuote;
}

void CharBase::load( string name, int hp, int atk, int def, int lvl, int xp, string victoryQuote, string defeatQuote )
{
	this->name = name;
	this->hp = hp;
	this->atk = atk;
	this->def = def;
	this->lvl = lvl;
	this->xp = xp;
	this->victoryQuote = victoryQuote;
	this->defeatQuote = defeatQuote;
}

bool CharBase::isDead()
{
	if( hp <= 0 )
		return true;
	else
		return false;
}

void Player::victory( Enemy &enemy )
{
	cout << name << " has defeated " << enemy.getName() << '!' << endl;
	cout << name << ": " << victoryQuote << endl;
	cout << enemy.getName() << ": " << enemy.getDefeatQuote() << endl;
	setXP( getXP() + enemy.getXP() );
	lvlUp();
}

void Player::defeat( Enemy &enemy )
{
	cout << name << " has died to " << enemy.getName() << '.' << endl;
	cout << enemy.getName() << ": " << enemy.getVictoryQuote() << endl;
	cout << name << ": " << defeatQuote << endl << "GAME OVER" << endl << endl;
}

void Player::lvlUp()
{
	while( xp >= lvl )
	{
		cout << name << " has leveled up!" << endl;
		xp = xp - lvl;
		lvl = lvl + 1;
		hp = hp + 2;
		atk = atk + 1;
		def = def + 1;
	}
}
