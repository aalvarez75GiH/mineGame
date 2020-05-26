#include <iostream>
#include "gameMap.h"
#include <fstream>

using namespace std;

gameMap::gameMap()
{
	gameLevel = 1;
	stateGame = 1;
	playerCell = NULL;
	enemyCell2 = NULL;
	enemyCell3 = NULL;
	enemyCell = NULL;
	isGameOver = false;
	loadMapFromFile();
}




void gameMap::drawMap()
{
	for (int i = 0; i < 15; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			cout<<cells[i][j].id;
		}
		
		cout<<endl;	
	
	
	}

}
//------------------------------------------------------------
void gameMap::setLevel(int gameLevelS)
{
	cout<<"gameLevel en la funcion setLevel es: "<<gameLevelS<<endl;
        gameLevel = gameLevelS;
	cout<<"gameLevel es ahora: "<<gameLevelS<<endl;

}
//------------------------------------------------------------



bool gameMap::setPlayerCell(int playerY,int playerX)
{

	cout<<"gameLevel en la funcion setPlayerCell es: "<<gameLevel<<endl;
	if (cells[playerY][playerX].wall() == false)
	{
		if (cells[playerY][playerX].win()== true)
		{
			if (playerCell != NULL)
			{
				playerCell->id = ' ';
			}
			playerCell = &cells[playerY][playerX];
			playerCell ->id =  '*';
			drawVictory();
			gameLevel = gameLevel + 1;
                        isGameOver = true;		
		}
		else
		{
			if (playerCell != NULL)
			{
				playerCell->id = ' ';
			}
			playerCell = &cells[playerY][playerX];
			playerCell ->id =  '3';
		}
		return true;
	}
	else
	{
		return false;
	}
	
}

bool gameMap::setEnemyCell(int enemyW,int enemyZ)
{
	cout<<"gameLevel en la funcion setEnemyCell es: "<<gameLevel<<endl;
	
	if (cells[enemyW][enemyZ].wall() == false)
	{
		if (enemyCell != NULL)
		{
			enemyCell->id = ' ';
		}
		enemyCell = &cells[enemyW][enemyZ];
	        enemyCell -> id = 'E';
		return true;
	}
	else
	{
	
	        return false;
	}
	
}

bool gameMap::setEnemyCell2(int enemyR,int enemyT)
{
        cout<<"gameLevel en la funcion setEnemyCell2 es: "<<gameLevel<<endl;

        if (cells[enemyR][enemyT].wall() == false)
        {
                if (enemyCell2 != NULL)
                {
                        enemyCell2->id = ' ';
                }
                enemyCell2 = &cells[enemyR][enemyT];
                enemyCell2 -> id = 'T';
                return true;
        }
        else
        {

                return false;
        }

}

bool gameMap::setEnemyCell3(int enemyF,int enemyG)
{
        cout<<"gameLevel en la funcion setEnemyCell3 es: "<<gameLevel<<endl;

        if (cells[enemyF][enemyG].wall() == false)
        {
                if (enemyCell3 != NULL)
                {
                        enemyCell3->id = ' ';
                }
                enemyCell3 = &cells[enemyF][enemyG];
                enemyCell3 -> id = 'C';
                return true;
        }
        else
        {

                return false;
        }

}


//------------------------------------------------------------------------------------
bool gameMap::mineSteppedL1(int PlayerY,int PlayerX,int enemyW,int enemyZ)
{
cout<<"mientras en mineStepped..."<<endl;
cout<<"Player -- X: "<<PlayerX<<" , "<<PlayerY<<endl;
cout<<"Enemy1  -- Z: "<<enemyZ<<" , "<<"W:"<<enemyW<<endl;

if (PlayerY == enemyW & PlayerX == enemyZ)
{
        stateGame = 8;
	isGameOver = true;
	return true;
} 

}

//---------------------------------------------------------------------------------------------------
bool gameMap::mineSteppedL2(int PlayerY,int PlayerX,int enemyW,int enemyZ,int enemyR, int enemyT)
{
cout<<"mientras en mineStepped..."<<endl;
cout<<"Player -- X: "<<PlayerX<<" , "<<PlayerY<<endl;
cout<<"Enemy1  -- Z: "<<enemyZ<<" , "<<"W:"<<enemyW<<endl;
cout<<"Enemy2  -- R: "<<enemyR<<" , "<<"R:"<<enemyT<<endl;

if (PlayerY == enemyW & PlayerX == enemyZ ||PlayerY == enemyR & PlayerX == enemyT)
{
        cout<<"Pasando por mineStepped2...";
	stateGame = 8;
	isGameOver = true;
        return true;
}

}
// ----------------------------------------------------------------------------------------------------
bool gameMap::mineSteppedL3(int PlayerY,int PlayerX,int enemyW,int enemyZ,int enemyR, int enemyT,int enemyF,int enemyG)
{
cout<<"mientras en mineStepped..."<<endl;
cout<<"Player -- X: "<<PlayerX<<" , "<<PlayerY<<endl;
cout<<"Enemy1  -- Z: "<<enemyZ<<" , "<<"W:"<<enemyW<<endl;
cout<<"Enemy2  -- R: "<<enemyR<<" , "<<"R:"<<enemyT<<endl;
cout<<"Enemy3  -- F: "<<enemyF<<" , "<<"G:"<<enemyG<<endl;

if (PlayerY == enemyW & PlayerX == enemyZ ||PlayerY == enemyR & PlayerX == enemyT || PlayerY == enemyF & PlayerX == enemyG)
{
        cout<<"Pasando por mineStepped2...";
	stateGame = 8;
	isGameOver = true;
        return true;
}
}
// ----------------------------------------------------------------------------------------------------
void gameMap::loadMapFromFile()
{

string line;
int r = 0;

	cout<<"gameLevel en la funcion loadMapFromFile es: "<<gameLevel<<endl;

if (gameLevel == 1)
{
	//cout<<"Level en loadMapFromFile:  "<<level<<endl;
	ifstream gameFReaded("gameLevel1.txt");
	if (gameFReaded.is_open())
	{
		while(getline(gameFReaded,line))
		{
			for(int i = 0;i<line.length();i++)
			{
				if (line[i] == '0')
				{
					cells[r][i].id = ' ';
				}
				else
				{
					cells[r][i].id = line[i];
				}
			} 
			
			r++;
		}
	}
	else
	{
	cout<<"FATAL ERROR LOADING LEVEL 1"<<endl;
	}
}
else if (gameLevel == 2)
{
	cout<<"Nivel 2"<<endl;
	ifstream gameFReaded("gameLevel2.txt");
	if (gameFReaded.is_open())
	{
		while(getline(gameFReaded,line))
		{
			for(int i = 0;i<line.length();i++)
                        {
                                if (line[i] == '0')
                                {
                                        cells[r][i].id = ' ';
                                }
                                else
                                {
                                        cells[r][i].id = line[i];
                                }
                        }

                        r++;
                }
        }
	else
        {
		cout<<"FATAL ERROR LOADING LEVEL 2"<<endl;
        }
}
//-------------------------------------------------------------------
else if (gameLevel == 3)
{
        cout<<"Nivel 3"<<endl;
        ifstream gameFReaded("gameLevel3.txt");
        if (gameFReaded.is_open())
        {
                while(getline(gameFReaded,line))
                {
                        for(int i = 0;i<line.length();i++)
                        {
                                if (line[i] == '0')
                                {
                                        cells[r][i].id = ' ';
                                }
                                else
                                {
                                        cells[r][i].id = line[i];
                                }
                        }

                        r++;
                }
        }
        else
        {
                cout<<"FATAL ERROR LOADING LEVEL 3"<<endl;
        }
}

//-------------------------------------------------------------------
}

void gameMap::drawIntro()
{
string line;



        ifstream introFile("introFile.txt");
        if (introFile.is_open())
        {
                while(getline(introFile,line))
                {
			cout<<line<<endl;
                }
        }
        else
        {
        cout<<"COULD NOT LOAD INTRO!!"<<endl;
        }

	cout<<"Press any key and start playing :)"<<endl;
}

void gameMap::drawVictory()
{
string line;



        ifstream victory("victoryFile.txt");
        if (victory.is_open())
        {
                while(getline(victory,line))
                {
                        cout<<line<<endl;
                }
        }
        else
        {
        cout<<"COULD NOT LOAD VICTORY FILE!!"<<endl;
        }

        cout<<"Press any key and start Continue :)"<<endl;
}

void gameMap::drawDefeat()
{
string line;

ifstream defeat("defeatFile.txt");
        if (defeat.is_open())
        {
                while(getline(defeat,line))
                {
                        cout<<line<<endl;
                }
        }
        else
        {
        cout<<"COULD NOT LOAD Defeat File!!"<<endl;
        }

        cout<<"Press any key to continue..:)"<<endl;
	isGameOver = true;
	
}

