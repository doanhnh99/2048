#include "checkWin.h"

bool checkWin(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (a[i][j] == 2048) return true;
	}

	return false;

}