#include <iostream>	// For cout and cin, terminal input and output
#include <string>	// For string usage and avoiding dealing with arrays of chars
#include <vector>	// For vector usage and avoiding having to use pointers and arrays
#include <ctime>	// For time()
#include <cstdlib>	// For srand() and rand() 
#include <unistd.h>	// For usleep( microseconds ) to add delay

class CharBase;
class Player;
class Enemy;

class GameEngine
{
	private:
		std::vector<Player> playerList;
		std::vector<Enemy> enemyList;
		void attack( Player &player, Enemy &enemy );
		int generateRandomInt( int high );
		void encounter();
		void toughEncounter();
		void camp();
	public:
		void addPlayer( Player &player );
		void addEnemy( Enemy &enemy );
		void combat( Player &player, Enemy &enemy );
		void menu();
};

class CharBase
{
	protected:
		int hp, atk, def, xp, lvl;
		std::string name, victoryQuote, defeatQuote;
	public:
		void setHP( int hp );
		void setAtk( int atk );
		void setDef( int def );
		void setLevel( int lvl );
		void setXP( int xp );
		void setName( std::string name );
		void setVictoryQuote( std::string victoryQuote );
		void setDefeatQuote( std::string defeatQuote );

		int getHP();
		int getAtk();
		int getDef();
		int getLevel();
		int getXP();
		std::string getName();
		std::string getVictoryQuote();
		std::string getDefeatQuote();

		void load( std::string name, int hp, int atk, int def, int xp, int lvl, std::string victoryQuote, std::string defeatQuote );
		bool isDead();
};

class Player: public CharBase
{
	public:
		void lvlUp();
		void victory( Enemy &enemy );
		void defeat( Enemy &enemy );
};

class Enemy: public CharBase
{
	public:
		Enemy( std::string name, int lvl );		
};
