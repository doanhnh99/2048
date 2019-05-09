#include "convert.h"

string convert(int number)
{
	switch (number)
	{
	case 0:return "0.png";
	case 2: return "2.jpg";
	case 4: return "4.jpg";
	case 8: return "8.jpg";
	case 16: return "16.jpg";
	case 32: return "32.jpg";
	case 64: return "64.jpg";
	case 128: return "128.jpg";
	case 256: return "256.jpg";
	case 512: return "512.jpg";
	case 1024: return "1024.jpg";
	case 2048: return "2048.jpg";
	default:
	{
		cout << "Error convert";
		system("pause");
	}

	}
}