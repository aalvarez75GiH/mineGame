#include <iostream>
#include "gameEnemy.h"
using namespace std;


gameEnemy::gameEnemy()
{
   
   int w;
   int z;
   int r;
   int t;
   int f;
   int g;
}

void gameEnemy::setLocationEnemy1()
{
		//Enemy1: 
		srand (time(NULL));
		int random1 = rand() % 12 + 1;
		w = random1;
		
		//Enemy1; 
		int random2 = rand() % 8 + 1;
		z = random2;
		
	//w = 9;
	//z = 1;

}
void gameEnemy::setLocationEnemy2()
{


                //Enemy2;
               int  random1 = rand() % 12 + 1;
                r = random1;

                 //Enemy2;
                int random2 = rand() % 8 + 1;
                t = random2;

}

void gameEnemy::setLocationEnemy3()
{


                //Enemy2;
               int  random1 = rand() % 12 + 1;
                f = random1;

                 //Enemy2;
                int random2 = rand() % 8 + 1;
                g = random2;

}

