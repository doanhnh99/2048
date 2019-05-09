#include <iostream>
#include<SFML\Graphics.hpp>
#include<SFML/Audio.hpp>
#include <ctime>
#include "Move.h"

using namespace std;
using namespace sf;



int random(int b[])
{
	srand(time(0));
	int temp = rand() % 5;
	if (b[temp] % 2 == 0) return 2;
	else return 4;

}

const int width = 1200;
const int height = 600;

RenderWindow window(VideoMode(width, height), "name window");

void init(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			a[i][j] = 0;
	}
}

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

void LoadText(int xxx)
{
	Font font;
	if (!font.loadFromFile("Xcelsion.ttf"))
	{
		cout << "Error Loading file " << endl;
	}

	Text text;

	text.setFont(font);
	//string temp = to_string(x);
	text.setString(to_string(xxx));
	text.setCharacterSize(50);
	text.setPosition(935.1, 110.5f);
	text.setFillColor(sf::Color::Red);
	window.draw(text);

}

void LoadImg(string url, double x = 0, double y = 0)
{
	Texture texture;
	texture.loadFromFile(url);
	Sprite sprite(texture);
	sprite.setPosition(x, y);
	window.draw(sprite);
}

void renderImage(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			LoadImg(convert(a[i][j]), 400.1 + j * 105.1, 100.1 + i * 105.1);
		}
	}
}

void print(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

bool checkWin(int a[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			if (a[i][j] == 16) return true;
	}

	return false;

}

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
				if (a[i][j] != a[i][j + 1] || a[i][j] != a[i + 1][j]) return true;
			}
	}
	return false;
}


/*void Right(int a[][4])
{


	for (int row = 0; row < 4; row++)
	{
		vector<int> tmp1;
		vector<int> tmp2;
		for (int i = 3; i > -1; i--)
		{
			if (a[row][i] != 0)
			{
				tmp1.push_back(a[row][i]);
			}
		}

		if (tmp1.size() > 0)
		{
			for (int i = 0; i < tmp1.size() - 1; i++)
			{
				if (tmp1[i] == tmp1[i + 1] && tmp1[i] != 0)
				{
					tmp1[i] *= 2;
					tmp1[i + 1] = 0;
					sum += tmp1[i];
				}
			}

			for (int i = 0; i < tmp1.size(); i++)
			{
				if (tmp1[i] != 0) tmp2.push_back(tmp1[i]);
			}


			if (tmp2.size() < 4)
				for (int i = 0; i < 4; i++)
				{
					if (3 - i < tmp2.size())
						a[row][i] = tmp2[3 - i]; else a[row][i] = 0;
				}
		}

	}
}


void Down(int a[][4])
{


	for (int col = 0; col < 4; col++)
	{
		vector<int> tmp1;
		vector<int> tmp2;
		for (int i = 3; i > -1; i--)
		{
			if (a[i][col] != 0)
			{
				tmp1.push_back(a[i][col]);
			}
		}

		if (tmp1.size() > 0)
		{
			for (int i = 0; i < tmp1.size() - 1; i++)
			{
				if (tmp1[i] == tmp1[i + 1] && tmp1[i] != 0)
				{
					tmp1[i] *= 2;
					tmp1[i + 1] = 0;
					sum += tmp1[i];
				}
			}

			for (int i = 0; i < tmp1.size(); i++)
			{
				if (tmp1[i] != 0) tmp2.push_back(tmp1[i]);
			}


			if (tmp2.size() < 4)
				for (int i = 0; i < 4; i++)
				{
					if (3 - i < tmp2.size())
						a[i][col] = tmp2[3 - i]; else a[i][col] = 0;
				}
		}

	}
}


void Left(int a[][4])
{

	for (int row = 0; row < 4; row++)
	{
		vector<int> tmp1;
		vector<int> tmp2;
		for (int i = 0; i < 4; i++)
		{
			if (a[row][i] != 0)
			{
				tmp1.push_back(a[row][i]);
			}
		}

		if (tmp1.size() > 0)
		{
			for (int i = 0; i < tmp1.size() - 1; i++)
			{
				if (tmp1[i] == tmp1[i + 1] && tmp1[i] != 0)
				{
					tmp1[i] *= 2;
					tmp1[i + 1] = 0;
					sum += tmp1[i];
				}
			}

			for (int i = 0; i < tmp1.size(); i++)
			{
				if (tmp1[i] != 0) tmp2.push_back(tmp1[i]);
			}


			if (tmp2.size() < 4)
				for (int i = 0; i < 4; i++)
				{
					if (i < tmp2.size())
						a[row][i] = tmp2[i]; else a[row][i] = 0;
				}
		}

	}

}


void Up(int a[][4])
{

	for (int col = 0; col < 4; col++)
	{
		vector<int> tmp1;
		vector<int> tmp2;
		for (int i = 0; i < 4; i++)
		{
			if (a[i][col] != 0)
			{
				tmp1.push_back(a[i][col]);
			}
		}

		if (tmp1.size() > 0)
		{
			for (int i = 0; i < tmp1.size() - 1; i++)
			{
				if (tmp1[i] == tmp1[i + 1] && tmp1[i] != 0)
				{
					tmp1[i] *= 2;
					tmp1[i + 1] = 0;
					sum += tmp1[i];
				}
			}

			for (int i = 0; i < tmp1.size(); i++)
			{
				if (tmp1[i] != 0) tmp2.push_back(tmp1[i]);
			}


			if (tmp2.size() < 4)
				for (int i = 0; i < 4; i++)
				{
					if (i < tmp2.size())
						a[i][col] = tmp2[i]; else a[i][col] = 0;
				}
		}

	}

}*/

int main()
{
	int a[4][4];
	init(a);
	int b[5] = { 2, 3, 6, 8, 10 };
	int sum = 0;
	int checkWinGame = 0;

	srand(time(NULL));
	int x = rand() % 4, y = rand() % 4;
	a[x][y] = 2;
	Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite sprite(texture);
	



	sf::Music music;
	if (!music.openFromFile("media.io_Gianna-Rino-Gaetano.wav"))
	{
		cout << "Error " << endl;
	}

	music.setVolume(50.f);
	//music.play();
	//music.pause();

	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
			{
				window.close();
			}
			
			/*if (checkWin(a))
			{
				window.clear();
				Texture texture1;
				texture1.loadFromFile("youwin.jpg");
				Sprite sprite(texture1);
				window.draw(sprite);
				window.display();
			}*/

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				Left(a, sum);
				if (checkWin(a)) break;
				x = rand() % 4; y = rand() % 4;
				if (a[x][y] == 0) a[x][y] = random(b);
				if (checkWin(a)) 
					checkWinGame = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				Right(a, sum);
				if (checkWin(a)) break;
				x = rand() % 4; y = rand() % 4;
				if (a[x][y] == 0) a[x][y] = random(b);
				if (checkWin(a)) 
					checkWinGame = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				Up(a, sum);
				if (checkWin(a)) break;
				x = rand() % 4; y = rand() % 4;
				if (a[x][y] == 0) a[x][y] = random(b);
				if (checkWin(a)) 
					checkWinGame = 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				Down(a, sum);
				if (checkWin(a)) break;
				x = rand() % 4; y = rand() % 4;
				if (a[x][y] == 0) a[x][y] = random(b);
				if (checkWin(a))
					checkWinGame = 1;
					break;
			}

			
			//render
				if (checkWinGame == 1) break;

				window.draw(sprite);
				renderImage(a);
				LoadImg("a.jpg", 850.5f, 50.52f);
				LoadText(sum);
				window.display();
			

		}

	}
}
