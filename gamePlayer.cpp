#include <iostream>
#include "gamePlayer.h"

using namespace std;


gamePlayer::gamePlayer()
{

	x = 1;
	y = 1;
}

void gamePlayer::callInput()
{
char userInput = ' ';
cin>>userInput;

switch (userInput)

{
	case 'w':
		lx = x;
		ly = y;
		y = y - 1;
		break;
	case 'd':
		lx = x;
		ly = y;
		x = x + 1;
		break;
	case 's': 
		lx = x;
		ly = y;
		y = y + 1;
		break;
	case 'a': 
		lx = x;
		ly = y;
		x = x - 1;
		break;
	case 'q':
		break;
		
		

}

cout<<"Player Last Coordinates: "<<lx<<","<<ly<<endl;
}


void gamePlayer::keepPos()
{
	y = ly;
	x = lx;
}
