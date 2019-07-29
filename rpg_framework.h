#include <iostream>	// For cout and cin, terminal input and output
#include <string>	// For string usage and avoiding dealing with arrays of chars
#include <vector>	// For vector usage and avoiding having to use pointers and arrays
#include <ctime>	// For time()
#include <cstdlib>	// For srand() and rand() 

class CharBase;
class Player;
class Enemy;

class GameEngine
{
	private:
		std::vector<Player> playerList;
		std::vector<Enemy> enemyList;
	public:
		void addPlayer( Player &player );
		void addEnemy( Enemy &enemy ); 
		void attack( CharBase &primary, CharBase &secondary );
		void combat( CharBase &primary, CharBase &secondary );
		int generateRandomInt( int high );
};

class CharBase
{
	protected:
		int hp, atk, def, xp, lvl;
		std::string name, victoryQuote;
	public:
		void setHP( int hp );
		void setAtk( int atk );
		void setDef( int def );
		void setLevel( int lvl );
		void setXP( int xp );
		void setName( std::string name );
		void setVictoryQuote( std::string victoryQuote );
		int getHP();
		int getAtk();
		int getDef();
		int getLevel();
		int getXP();
		std::string getName();
		std::string getVictoryQuote();

		void load( std::string name, int hp, int atk, int def, int xp, int lvl, std::string victoryQuote );
		bool isDead();
		void lvlUp();
		void victory( CharBase &enemy );
		void defeat();
};

class Player: public CharBase{
};

class Enemy: public CharBase{
};
