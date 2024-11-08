

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std; 

bool snakeGame;
const int width = 50;
const int height = 25; 
//User variables
int x, y, speed = 1;
int tailX[100], tailY[100], tailLength;
//Tail coords
int fposX, fposY, sposX, sposY;
//Target variables
int targetX, targetY;
//Game variables
int score; 
enum direction {STOP = 0, DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT};
direction dir;

void game_Setup() 
{
	snakeGame = true;
	dir = STOP;
	x = rand() % width;
	y = rand() % height; 
	targetX = rand() % width;
	targetY = rand() % height;

	if (x == targetX && y == targetY)
	{
		x = rand() % width;
		y = rand() % height;
		targetX = rand() % width;
		targetY = rand() % height;
	}
	score = 0;
}

void game_Window()
{
	system("cls");
	//Top wall
	for (int i = 0; i < width; i++)
	{
		cout << "*";
	}
	cout << endl; 

	//Side walls
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
			{
				cout << "*";
			}
			else if (i == y && j == x)
			{
				cout << "S";
			}
			else if (i == targetY && j == targetX)
			{
				cout << "O";
			}
			else  
			{
				bool tail = false;
				for (int k = 0; k < tailLength; k++)
				{
					if (j == tailX[k] && i == tailY[k])
					{
						cout << "s";
						tail = true;
					}
				}
				if (!tail)
				{
					cout << " ";
				}
			}
			
		}
		cout << endl;
	}

	//Bottom walls
	for (int i = 0; i < width; i++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "Score: " << score;

}

void game_Input()
{
	if (_kbhit()) 
	{
		switch (_getch()) 
		{
			case 'a':
				if (dir != DIR_RIGHT)
				{
					dir = DIR_LEFT;
				}
				break;
			case 's':
				if (dir != DIR_UP)
				{
					dir = DIR_DOWN;
				}
				break;
			case 'd':
				if (dir != DIR_LEFT)
				{
					dir = DIR_RIGHT;
				}
				break;
			case 'w':
				if (dir != DIR_DOWN)
				{
					dir = DIR_UP;
				}
				break;
			case '0':
				snakeGame = false;
				break;

		}	
	}
}

void game_Program()
{
	//Tail
	fposX = tailX[0];
	fposY = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < tailLength; i++)
	{
		sposX = tailX[i];
		sposY = tailY[i];
		tailX[i] = fposX;
		tailY[i] = fposY;
		fposX = sposX;
		fposY = sposY;
	}

	//Movement
	switch (dir)
	{
	case DIR_LEFT:
		x -= speed;
		break;
	case DIR_UP:
		y -= speed;
		break;
	case DIR_RIGHT:
		x += speed;
		break;
	case DIR_DOWN:
		y += speed;
		break;
	}
	
	//Snake border hit
	if (x < 0 || x > width - 1 || y < 0 || y > height - 1)
	{
		snakeGame = false;
	}

	//Snake tail hit
	for (int i = 0; i < tailLength; i++)
	{
		if (x == tailX[i] && y == tailY[i])
		{
			snakeGame = false;
		}
	}

	//Snake targets
	if (x == targetX && y == targetY)
	{
		targetX = rand() % width;
		targetY = rand() % height;
		score++;
		tailLength++;
	}
}

int main()
{
	game_Setup();
	while (snakeGame == true) 
	{
		game_Window();
		game_Input();
		game_Program();
		Sleep(30);
	}
}

