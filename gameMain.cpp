#include <iostream>
#include "gamePlayer.h"
#include "gameCell.h"
#include "gameMap.h"
#include "gameEnemy.h"

using namespace std;
int main()
{
bool flag;
int numLevels = 4;
int gameLevelX =1;
	gameMap mapa;
	gamePlayer jugador1;
        gameEnemy enemy1; 
        gameEnemy enemy2; 
        gameEnemy enemy3; 
	mapa.drawIntro();
	mapa.setLevel(gameLevelX);
while (mapa.stateGame != 8)
{
cout<<"nivel de juego papa2: "<<mapa.gameLevel<<endl;

	switch (mapa.gameLevel)
	{
		case 1:
			cout<<"Probando GITHUB"<<endl;
                        cout<<"esta entrando en case 1"<<endl;
			mapa.drawMap();
			cout<<"Utiliza (w)=arriba,(a)Izquierda,(s)Abajo,(d)Derecha,(q)Quit..."<<endl;
			mapa.isGameOver = false;
			while (mapa.isGameOver == false)
			{
				cout<<"Estado de isGameOver despues de entrar al while: "<<mapa.isGameOver<<endl;
                                        //aqui el objeto jugador1 llama a la funcion callInput declarada en gamePlayer.h
                enemy1.setLocationEnemy1();
                enemy2.setLocationEnemy2();
                jugador1.callInput();
                cout<<"Enemy1  -- W:"<<enemy1.z<<" , "<<"Z:"<<enemy1.w<<endl;
                cout<<"Enemy2  -- R:"<<enemy2.r<<" , "<<"T:"<<enemy2.t<<endl;
                cout<<"Player -- X:"<<jugador1.x<<" , "<<"Y:"<<jugador1.y<<endl;
                
                if (mapa.mineSteppedL1(jugador1.y,jugador1.x,enemy1.w,enemy1.z))
                {
                        cout<<"estan en la misma posicion..."<<endl;
        		//mapa.gameLevel = 8;
                        cout<<"Estado de gameState despues de perder: "<<mapa.stateGame<<endl;
			//mapa.isGameOver = true;
			cout<<"Estado de isGameOver despues de llegar de la nube: "<<mapa.isGameOver<<endl;
                }
                else
                {
                        //mapa.setLevel();      
                        cout<<"NO estan en la misma posicion..."<<endl;
                        switch (mapa.setPlayerCell(jugador1.y,jugador1.x))
                        {
                                case true:
                                        if (mapa.setEnemyCell(enemy1.w,enemy1.z))
                                        {
                                                mapa.drawMap();
                                        }
                                        else
                                        {
                                                mapa.drawMap();
						cout<<"Enemy cant move, there is a wall..."<<endl;
                                        }
                                        break;
				case false:

                                        jugador1.keepPos();
                                        mapa.drawMap();
                                        break;
                        }

                }
        cout<<"Estado de isGameOver antes de subir al while de isGameOver: "<<mapa.isGameOver<<endl;
        }
        cout<<"Nivel: "<<mapa.gameLevel<<endl;
        mapa.loadMapFromFile();
        jugador1.x = 1;
        jugador1.y = 1;
        cout<<"Estado de gameLevel antes de subir al while de gameLevel: "<<mapa.gameLevel<<endl;
	cout<<"Siempre Case 1"<<endl;
cout<<"nivel de juego papa: "<<mapa.gameLevel<<endl;

break;						

		
		case 2:	
			cout<<"esta entrando en case 2"<<endl;
				mapa.drawMap();
				cout<<"Utiliza (w)=arriba,(a)Izquierda,(s)Abajo,(d)Derecha,(q)Quit..."<<endl;
				mapa.isGameOver = false;
				while (mapa.isGameOver == false)
				{
					cout<<"Estado de isGameOver despues de entrar al while: "<<mapa.isGameOver<<endl;
					//aqui el objeto jugador1 llama a la funcion callInput declarada en gamePlayer.h
		enemy1.setLocationEnemy1();
		enemy2.setLocationEnemy2();
		jugador1.callInput();
		cout<<"Enemy1  -- W:"<<enemy1.z<<" , "<<"Z:"<<enemy1.w<<endl;
		cout<<"Enemy2  -- R:"<<enemy2.r<<" , "<<"T:"<<enemy2.t<<endl;
		cout<<"Player -- X:"<<jugador1.x<<" , "<<"Y:"<<jugador1.y<<endl;
	        	
		if (mapa.mineSteppedL2(jugador1.y,jugador1.x,enemy1.w,enemy1.z,enemy2.r,enemy2.t)||mapa.mineSteppedL2(jugador1.y,jugador1.x,enemy1.w,enemy1.z,enemy2.r,enemy2.t))
		{
                        cout<<"estan en la misma posicion..."<<endl;
        		//mapa.gameLevel = 8;
                        cout<<"Estado de gameState despues de perder: "<<mapa.stateGame<<endl;
			//mapa.isGameOver = true;
			cout<<"Estado de isGameOver despues de llegar de la nube: "<<mapa.isGameOver<<endl;
		}
		else
		{
			//mapa.setLevel();	
			cout<<"NO estan en la misma posicion..."<<endl;
			switch (mapa.setPlayerCell(jugador1.y,jugador1.x))
			{
				case true:	
					if (mapa.setEnemyCell(enemy1.w,enemy1.z))
					{
						mapa.drawMap();
					}
					else
					{
						mapa.drawMap();
						cout<<"Enemy cant move, there is a wall..."<<endl;
					}
					//----------------------------------------------------------
					if (mapa.setEnemyCell2(enemy2.r,enemy2.t))
					{
						mapa.drawMap();
					}
					else
					{
						mapa.drawMap();
						cout<<"Enemy cant move, there is a wall..."<<endl;
					}
					//------------------------------------------------------------
					break;
					case false: 
				
					jugador1.keepPos();
					mapa.drawMap();
					break;
			}
			
		}
	cout<<"Estado de isGameOver antes de subir al while de isGameOver: "<<mapa.isGameOver<<endl;
	}//while isGameOver
	cout<<"Nivel: "<<mapa.gameLevel<<endl;
	mapa.loadMapFromFile();
	jugador1.x = 1;
	jugador1.y = 1;
	cout<<"Estado de gameLevel antes de subir al while de gameLevel: "<<mapa.gameLevel<<endl;

cout<<"Siempre Case 2"<<endl;
break;
//----------------------------case 3 -----------------------------------------------------
case 3: 
     cout<<"esta entrando en case 3"<<endl;
                                mapa.drawMap();
                                cout<<"Utiliza (w)=arriba,(a)Izquierda,(s)Abajo,(d)Derecha,(q)Quit..."<<endl;
                                mapa.isGameOver = false;
                                while (mapa.isGameOver == false)
                                {
                                        cout<<"Estado de isGameOver despues de entrar al while: "<<mapa.isGameOver<<endl;
                                        //aqui el objeto jugador1 llama a la funcion callInput declarada en gamePlayer.h
                enemy1.setLocationEnemy1();
                enemy2.setLocationEnemy2();
                enemy3.setLocationEnemy3();
                jugador1.callInput();
                cout<<"Enemy1  -- W:"<<enemy1.z<<" , "<<"Z:"<<enemy1.w<<endl;
                cout<<"Enemy2  -- R:"<<enemy2.r<<" , "<<"T:"<<enemy2.t<<endl;
                cout<<"Enemy3  -- F:"<<enemy3.f<<" , "<<"G:"<<enemy2.g<<endl;
                cout<<"Player -- X:"<<jugador1.x<<" , "<<"Y:"<<jugador1.y<<endl;
                
                if (mapa.mineSteppedL3(jugador1.y,jugador1.x,enemy1.w,enemy1.z,enemy2.r,enemy2.t,enemy3.f,enemy3.g) || (mapa.mineSteppedL3(jugador1.y,jugador1.x,enemy1.w,enemy1.z,enemy2.r,enemy2.t,enemy3.f,enemy3.g)))
                {
                        cout<<"estan en la misma posicion..."<<endl;
                        //mapa.gameLevel = 8;
                        cout<<"Estado de gameState despues de perder: "<<mapa.stateGame<<endl;
                        //mapa.isGameOver = true;
                        cout<<"Estado de isGameOver despues de llegar de la nube: "<<mapa.isGameOver<<endl;
                }
                else
                {
                        //mapa.setLevel();      
                        cout<<"NO estan en la misma posicion..."<<endl;
                        switch (mapa.setPlayerCell(jugador1.y,jugador1.x))
                        {
                                case true:
                                        if (mapa.setEnemyCell(enemy1.w,enemy1.z))
                                        {
                                                mapa.drawMap();
                                        }
                                        else
                                        {
                                                mapa.drawMap();
                                                cout<<"Enemy cant move, there is a wall..."<<endl;
                                        }
                                        //----------------------------------------------------------
                                        if (mapa.setEnemyCell2(enemy2.r,enemy2.t))
                                        {
                                                mapa.drawMap();
                                        }
                                        else
                                        {
                                                mapa.drawMap();
                                                cout<<"Enemy cant move, there is a wall..."<<endl;
                                        }
                                        //------------------------------------------------------------
                                        if (mapa.setEnemyCell3(enemy3.f,enemy3.g))
                                        {
                                                mapa.drawMap();
                                        }
                                        else
                                        {
                                                mapa.drawMap();
                                                cout<<"Enemy cant move, there is a wall..."<<endl;
                                        }
                                        //------------------------------------------------------------
                                        break;
                                        case false:

                                        jugador1.keepPos();
                                        mapa.drawMap();
                                        break;
                        }

                }
        cout<<"Estado de isGameOver antes de subir al while de isGameOver: "<<mapa.isGameOver<<endl;
        }
        cout<<"Nivel: "<<mapa.gameLevel<<endl;
        mapa.loadMapFromFile();
        jugador1.x = 1;
        jugador1.y = 1;
        cout<<"Estado de gameLevel antes de subir al while de gameLevel: "<<mapa.gameLevel<<endl;
cout<<"Siempre Case 3"<<endl;
break;
case 4: cout<<"Ya he ganado"<<endl;
	mapa.stateGame = 8;
	break;
//----------------------------------------------------------------------------------------

}//switch (mapa gameLevel)
} //while mapaGameLevel

if (mapa.gameLevel == 4)
{
	mapa.drawVictory();

}
else if (mapa.gameLevel < 4 && mapa.stateGame == 8) 
{
	
	mapa.drawDefeat();

}

return 0;
}

