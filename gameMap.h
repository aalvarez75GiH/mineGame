#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "gameCell.h" 

class gameMap
{
	public:
		bool isGameOver = false;
		int gameLevel;
		int stateGame;
		gameMap();
		gameCell cells[15][10];
		gameCell* playerCell;
		gameCell* enemyCell;
		gameCell* enemyCell2;
		gameCell* enemyCell3;
		void drawMap();
		bool setPlayerCell(int playerY, int playerX);	
                bool setEnemyCell (int enemyZ, int enemyW);
                bool setEnemyCell2 (int enemyZ, int enemyW);
                bool setEnemyCell3 (int enemyF, int enemyG);
		bool mineSteppedL1(int PlayerY,int PlayerX,int enemyW,int enemyZ);
		bool mineSteppedL2(int PlayerY,int PlayerX,int enemyW,int enemyZ,int enemyR,int enemyT);
		bool mineSteppedL3(int PlayerY,int PlayerX,int enemyW,int enemyZ,int enemyR,int enemyT,int enemyF,int enemyG);
		void drawIntro();
                void drawVictory();
		void drawDefeat();
		void setLevel(int gameLavelS);
		void loadMapFromFile();

	protected: 
		
                 	
	
	private:
};

#endif //PLAYER_H
