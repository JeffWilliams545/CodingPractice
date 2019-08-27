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
	Enemy ruby( "Ruby", 1 );	
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

void GameEngine::attack( Player &player, Enemy &enemy )
{
	if( player.isDead() )
	{
		player.defeat( enemy );
		return;
	}	
	int dmg = max( 1, player.getAtk() - enemy.getDef() );
	enemy.setHP( enemy.getHP() - dmg );
	cout << player.getName() << " attacked " << enemy.getName() << " and dealt " << dmg << " damage!" << endl;
	if ( enemy.isDead() )
	{	
		player.victory( enemy );
		return;
	}
	dmg = max( 1, enemy.getAtk() - player.getDef() );
	player.setHP( player.getHP() - dmg );
	cout << enemy.getName() << " attacked " << player.getName() << " and dealt " << dmg << " damage!" << endl;
}

void GameEngine::combat( Player &player, Enemy &enemy )
{
  	int turnCount = 0;
  	while ( !player.isDead() && !enemy.isDead() )
  	{
    		attack( player, enemy );
    		turnCount++;
  	}	
  	return;
}

void GameEngine::menu()
{
	// menuIndex used for switch statement
	// validInput used to check for valid user input
	int menuIndex;
	bool validInput;

	// Printing menu to terminal
	cout << "-----------------------------------------------" << endl;
	cout << "Welcome to Cave." << endl << endl;
	cout << "Please select from the following options." << endl << endl;
	cout << "1 - Fight an enemy" << endl;
	cout << "2 - Fight a tough enemy" << endl;
	cout << "3 - Make camp for the night." << endl;
	cout << "0 - Exit Cave." << endl;
	cout << "-----------------------------------------------" << endl;

	// Input from user
	validInput = false;
	while( !validInput )
	{
		cin >> menuIndex;
		if( menuIndex > 3 || menuIndex < 0 )
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
		case 1:
		{
			encounter();
			break;
		}
		case 2:
		{
			toughEncounter();
			break;
		}
		case 3:
		{
			camp();
			break;
		}
		case 0:
		{
			break;
		}	
	}	
}

int GameEngine::generateRandomInt( int high )
{
	return ( rand() % high ) + 1;
}

void GameEngine::encounter()
{
	cout << "encounter" << endl;
	menu();
}

void GameEngine::toughEncounter()
{
	cout << "toughEncounter" << endl;
	menu();
}
void GameEngine::camp()
{
	cout << "camp" << endl;
	menu();
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

Enemy::Enemy( string name, int lvl )
{
	load( name, 5 * lvl, 2 * lvl, 1 * lvl, lvl, lvl, string( "default" ), string( "default" ) );
}
