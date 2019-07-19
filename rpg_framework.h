#include <iostream>
#include <string>

class Char_base {
	public:
		int hp, atk, def, lvl;		
		std::string name;
		Char_base();
		Char_base( std::string tempName );
		void setHP( int tempHP );
		void setAtk( int tempAtk );
		void setDef( int tempDef );
		void setLevel( int tempLvl );
		int getHP();
		int getAtk();
		int getDef();
		int getLevel();
		bool isDead();
		void victory();
		void attack( Char_base &other );
		void load( int tempHP, int tempAtk, int tempDef, int tempLvl );
};

class Player: public Char_base{
	public:
		Player();
		Player( std::string tempName );
};

class Enemy: public Char_base{
	public:
		Enemy();
		Enemy( std::string tempName );
};

bool combat1();
bool combat2();
bool combat3();
bool level();
