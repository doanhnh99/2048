#include <iostream>
#include <fstream>
#include<SFML\Graphics.hpp>
#include<SFML/Audio.hpp>
#include <ctime>
#include "Move.h"
#include "random.h"
#include "init.h"
#include "checkWin.h"
#include "checkGameOver.h"
#include "convert.h"

using namespace std;
using namespace sf;


#define width  1200
#define height  600

RenderWindow window(VideoMode(width, height), "name window");



void LoadText(int score)
{
	Font font;
	if (!font.loadFromFile("Xcelsion.ttf"))
	{
		cout << "Error Loading file " << endl;
	}

	Text text;

	text.setFont(font);
	string temp = to_string(score);
	text.setString(to_string(score));
	text.setCharacterSize(50);
	text.setPosition(935.1, 110.5f);
	text.setFillColor(sf::Color::Cyan);
	window.draw(text);
}

void LoadMaxScore(int score)
{
	Font font;
	if (!font.loadFromFile("Xcelsion.ttf"))
	{
		cout << "Error Loading file " << endl;
	}

	Text text;

	text.setFont(font);
	string temp = to_string(score);
	text.setString(to_string(score));
	text.setCharacterSize(80);
	text.setPosition(800, 350.69);
	text.setFillColor(sf::Color::Black);
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
			LoadImg(convert(a[i][j]), 300 + j * 105.1, 100.1 + i * 105.1);
		}
	}
}



int main()
{
	int a[4][4];
	init(a);
	int b[5] = { 2, 3, 6, 8, 10 };
	int sum = 0;
	int checkWinGame = 0;
	int checkOverGame = 0;
	int MaxScore = 0;

	srand(time(NULL));
	int x = rand() % 4, y = rand() % 4;
	a[x][y] = 2;
	Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite sprite(texture);
	
	// Music
	sf::Music music;
	if (!music.openFromFile("media.io_Gianna-Rino-Gaetano.wav"))
	{
		cout << "Error " << endl;
	}

	music.setVolume(50.f);
	music.play();
	


	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
			{
				window.close();
			}
			
			if (checkWinGame == 1)
			{
				window.close();
			}

			if (checkGameOver(a))
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				Left(a, sum);
				x = rand() % 4; y = rand() % 4;
				if (a[x][y] == 0) a[x][y] = random(b);
				if (checkWin(a))
				{
					checkWinGame = 1;
					MaxScore = sum;
				}

				if (checkGameOver(a))
				{
					checkOverGame = 1;
					MaxScore = sum;
				}
					
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				Right(a, sum);
				x = rand() % 4; y = rand() % 4;
				if (a[x][y] == 0) a[x][y] = random(b);
				if (checkWin(a))
				{
					checkWinGame = 1;
					MaxScore = sum;
				}

				if (checkGameOver(a))
				{
					checkOverGame = 1;
					MaxScore = sum;
				}
					
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				Up(a, sum);
				x = rand() % 4; y = rand() % 4;
				if (a[x][y] == 0) a[x][y] = random(b);
				if (checkWin(a))
				{
					checkWinGame = 1;
					MaxScore = sum;
				}

				if (checkGameOver(a))
				{
					checkOverGame = 1;
					MaxScore = sum;
					
				}
					
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				Down(a, sum);
				x = rand() % 4; y = rand() % 4;
				if (a[x][y] == 0) a[x][y] = random(b);
				
				if (checkWin(a))
				{
					checkWinGame = 1;
					MaxScore = sum;
				}

				if (checkGameOver(a))
				{
					checkOverGame = 1;
					MaxScore = sum;

				}
			}

			int tempPoint;
			
			

			ifstream in("MaxScore.txt");
			int initPoint;
			in >> initPoint;
			in.close();


			if (MaxScore > 0 && MaxScore > initPoint)
			{
				ofstream on("MaxScore.txt");
				initPoint = MaxScore;
				on << initPoint;
				on.close();
			}
			

			//render
				window.draw(sprite);
				renderImage(a);
				LoadImg("a.jpg", 850.5f, 50.52f);
				LoadImg("MaxScore.jpg", 850.5f, 250.1f);
				LoadText(sum);
				LoadMaxScore(initPoint);
				/*if (MaxScore > 0 && MaxScore > initPoint)
				{

				}*/

				window.display();
		}

	}
}
