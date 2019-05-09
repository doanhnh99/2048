#include "random.h"

int random(int b[])
{
	srand(time(0));
	int temp = rand() % 5;
	if (b[temp] % 2 == 0) return 2;
	else return 4;

}