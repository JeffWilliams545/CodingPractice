//Author - Jeffrey Williams
//Code based off of coding challenge from edabit.com rpg_framwork

#include "rpg_framework.h"

using namespace std;

int main( int argc, char* argv[] )
{
	srand( time( 0 ) );
	GameEngine rpg;
	Player jeff;
	jeff.load( string( "Jeff" ), 5, 2, 1, 1, 0, string( "get rekt" ) );
	Enemy ruby;
	ruby.load( string( "Ruby" ), 3, 1, 1, 1, 0, string( "Bark. Ball?" ) );
	rpg.addPlayer( jeff );
	rpg.addEnemy( ruby );
	rpg.combat( jeff, ruby );
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

void GameEngine::attack( CharBase &primary, CharBase &secondary )
{
	if( primary.isDead() )
	{
		primary.defeat();
		return;
	}	
	int dmg = max( 0, primary.getAtk() - secondary.getDef() );
	secondary.setHP( secondary.getHP() - dmg );
	cout << primary.getName() << " attacked " << secondary.getName() << " and dealt " << dmg << " damage!" << endl;
	if ( secondary.isDead() )
	{	
		primary.victory( secondary );
		return;
	}
	dmg = max( 0, secondary.getAtk() - primary.getDef() );
	primary.setHP( primary.getHP() - dmg );
	cout << secondary.getName() << " attacked " << primary.getName() << " and dealt " << dmg << " damage!" << endl;
}

void GameEngine::combat( CharBase &primary, CharBase &secondary )
{
  	int turnCount = 0;
  	while ( !primary.isDead() && !secondary.isDead() )
  	{
    		attack( primary, secondary );
    		turnCount++;
  	}	
  	return;
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

void CharBase::load( string name, int hp, int atk, int def, int lvl, int xp, string victoryQuote )
{
	this->name = name;
	this->hp = hp;
	this->atk = atk;
	this->def = def;
	this->lvl = lvl;
	this->xp = xp;
	this->victoryQuote = victoryQuote;
}

bool CharBase::isDead()
{
	if( hp <= 0 )
		return true;
	else
		return false;
}

void CharBase::victory( CharBase &enemy )
{
	cout << name << " has defeated " << enemy.getName() << '!' << endl << victoryQuote << endl << endl;
	setXP( getXP() + enemy.getXP() );
	lvlUp();
}

void CharBase::defeat()
{
	cout << name << " has died!" << endl << "GAME OVER" << endl << endl;
}

void CharBase::lvlUp()
{
		
}
