#include "init.h"

void init(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			a[i][j] = 0;
	}
}