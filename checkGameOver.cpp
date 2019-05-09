#include "checkGameOver.h"

bool checkElement(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (a[i][j] == 0) return false;
	}
	return true;
}

bool checkGameOver(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (checkElement(a))
			{
				if (((i >= 0 && i <= 2) && (a[i][j] != a[i][j + 1] && a[i][j] != a[i + 1][j])) || (i = 3 && a[i][j] != a[i][j + 1])) return true;
			}
	}
	return false;
}