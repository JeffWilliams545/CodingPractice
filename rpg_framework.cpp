//Author - Jeffrey Williams
//Coding challenge from edabit.com rpg_framwork

#include "rpg_framework.h"

using namespace std;

int main( int argc, char* argv[] )
{
	combat1();
	combat2();
	combat3();
	level();
	return 1;
}

Char_base::Char_base( string tempName )
{
	name = tempName;
}

Char_base::Char_base()
{
}

void Char_base::setHP( int tempHp )
{
	hp = tempHp;
}

void Char_base::setAtk( int tempAtk )
{
	atk = tempAtk;
}

void Char_base::setDef( int tempDef )
{
	def = tempDef;
}

void Char_base::setLevel( int tempLvl )
{
	lvl = tempLvl;
}

int Char_base::getHP()
{
	return hp;
}

int Char_base::getAtk()
{
	return atk;
}

int Char_base::getDef()
{
	return def;
}

int Char_base::getLevel()
{
	return lvl;
}

bool Char_base::isDead()
{
	if( hp <= 0 )
		return true;
	else
		return false;
}

void Char_base::victory()
{
	cout << "yay" << endl;
}

Player::Player( string tempName )
{
	name = tempName;
}

Player::Player()
{
}

Enemy::Enemy( string tempName )
{
	name = tempName;
}

Enemy::Enemy()
{
}

bool combat1()
{
  	Player p;
  	p.load( 20, 5, 1, 1 );
  	Enemy e;
  	e.load( 10, 3, 1, 1 );
  	int turnCount = 0;
  	while ( !p.isDead() && !e.isDead() )
  	{
    		p.attack( e );
    		e.attack( p );
    		turnCount++;
  	}
  	cout << turnCount << endl;
  	return ( !p.isDead() && turnCount == 3 );
}

bool combat2()
{
  	Player p;
  	p.load( 20, 5, 1, 1 );
  	Enemy e( "Goblin" );
  	e.load( 10, 3, 1, 1 );
  	Enemy e2( "Tiny Goblin" );
  	e2.load( 10, 3, 1, 1 );
  	int turnCount = 0;
  	cout << p.name << ": " << p.getHP() << "hp" << endl;
  	cout << e.name << ": " << e.getHP() << "hp" << endl;
  	cout << e2.name << ": " << e2.getHP() << "hp" << endl;
  	while ( !p.isDead() && !e.isDead() && !e2.isDead() )
  	{
    		if ( !e.isDead() )
    			p.attack( e );
    		else
    			p.attack( e2 );
    		e.attack( p );
    		e2.attack( p );
    		turnCount++;
  	}
  	cout << turnCount << endl;
  	return ( !p.isDead() && turnCount == 6 );
}

bool level()
{
  	Player p;
  	p.load( 20, 5, 1, 1 );
  	Enemy e( "Gold Slime" );
  	e.load( 1, 0, 0, 20 );
  	int turnCount = 0;
  	cout << p.name << ": " << p.getHP() << "hp" << endl;
  	cout << e.name << ": " << e.getHP() << "hp" << endl;
  	while ( !p.isDead() && !e.isDead() )
  	{
    		p.attack( e );
    		e.attack( p );
    		turnCount++;
  	}
  	cout << turnCount << endl;
  	return ( !p.isDead() && p.getLevel() == 2 && turnCount == 1 );
}

bool combat3()
{
	Player p;
	p.load( 5, 2, 1, 1 );
	Enemy e( "Giant" );
	e.load( 200, 300, 25, 30 );
	int turnCount = 0;
	cout << p.name << ": " << p.getHP() << "hp" << endl;
	cout << e.name << ": " << e.getHP() << "hp" << endl;
	while ( !p.isDead() && !e.isDead() )
	{
		p.attack( e );
		e.attack( p );
    		turnCount++;
  	}
  	cout << turnCount << endl;
  	return ( p.isDead() && turnCount == 1 );
}

void Char_base::attack( Char_base &other )
{
 	if ( isDead() )
		return;
	int dmg = max( 1, getAtk() - other.getDef() );
	other.setHP( other.getHP() - dmg );
	cout << name << " attacked " << other.name << " and dealt " << dmg << " damage!" << endl;
	if ( other.isDead() )
	{
		cout << name << " won!" << endl;
		victory();
	}
}

void Char_base::load( int tempHP, int tempAtk, int tempDef, int tempLvl )
{
	setHP( tempHP );
	setAtk( tempAtk );
	setDef( tempDef );
	setLevel( tempLvl );
	cout << "hp: " << getHP() << endl;
	cout << "atk: " << getAtk() << endl;
	cout << "def: " << getDef() << endl;
	cout << "lvl: " << getLevel() << endl;
}
