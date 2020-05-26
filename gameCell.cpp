#include "gameCell.h"


gameCell::gameCell()
{
	id = '0';
	idEnemy = 'E';
}

bool gameCell::wall()
{
	if (id == '|')
	{
		return true;
	}
	else
	{
		return false;
	}
}       


bool gameCell::win()
{
	if (id == '$')
        {
                return true;
        }
        else
        {
                return false;
        }
}





