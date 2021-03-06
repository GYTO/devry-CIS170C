// ---------------------------------------------------
// Programming Assignment:  CP1
// Developer:				Roman Kovtun
// Date Written:			03/18/2018
// Purpose:					Course Project
// ---------------------------------------------------


#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// initiate game features
int x, y, posFruitX, posFruitY, score;
int snakeTailX[100], snakeTailY[100];
int numTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton snakeDir;
bool gameOver;
const int width = 40;
const int height = 10;


// initiate start of the game
void Setup()
{
	gameOver = false;
	snakeDir = STOP;
	x = width / 2;
	y = height / 2;
	posFruitX = rand() % width;
	posFruitY = rand() % height;
	score = 0;
}

// initiate the logic
void Logic()
{
	int prevPosX = snakeTailX[0];
	int prevPosY = snakeTailY[0];
	int prevPos2X, prevPos2Y;
	snakeTailX[0] = x;
	snakeTailY[0] = y;
	for (int position = 1; position < numTail; position++)
	{
		prevPos2X = snakeTailX[position];
		prevPos2Y = snakeTailY[position];
		snakeTailX[position] = prevPosX;
		snakeTailY[position] = prevPosY;
		prevPosX = prevPos2X;
		prevPosY = prevPos2Y;
	}
	switch (snakeDir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	for (int position = 0; position < numTail; position++)
	{
		if (snakeTailX[position] == x && snakeTailY[position] == y)
		{
			gameOver = true;
		}
	}

	if (x == posFruitX && y == posFruitY)
	{
		score += 10;
		posFruitX = rand() % width;
		posFruitY = rand() % height;
		numTail++;
	}
}

// initiate the borders for the game
void Draw()
{
	system("cls");
	for (int border = 0; border < width + 2; border++)
	{
		cout << "#";
	}
	cout << endl;

	for (int hBorder = 0; hBorder < height; hBorder++)
	{
		for (int wBorder = 0; wBorder < width; wBorder++)
		{
			if (wBorder == 0)
			{
				cout << "#";
			}

			if (hBorder == y && wBorder == x)
			{
				cout << "O";
			}
			else if (hBorder == posFruitY && wBorder == posFruitX)
			{
				cout << "%";
			}
			else
			{
				bool print = false;
				for (int position = 0; position < numTail; position++)
				{
					if (snakeTailX[position] == wBorder && snakeTailY[position] == hBorder)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
				{
					cout << " ";
				}
			}
			if (wBorder == width - 1)
			{
				cout << "#";
			}
		}
		cout << endl;
	}

	for (int border = 0; border < width + 2; border++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score:" << score << endl;
	cout << "To control the snake press W, A, S, D" << endl;
	cout << "To stop the game press X key" << endl;
}

// initiate the buttons
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			snakeDir = LEFT;
			break;
		case 'd':
			snakeDir = RIGHT;
			break;
		case 'w':
			snakeDir = UP;
			break;
		case 's':
			snakeDir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

// initiate entire game
int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		// Speed of the game
		Sleep(100);
	}
	return 0;
}