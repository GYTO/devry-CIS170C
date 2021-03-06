// ---------------------------------------------------------------
// Programming Assignment:	Course Project
// Developer:			    Roman Kovtun
// Date Written:			03/09/2018
// Purpose:					Snake Game 
// REFERENCE:				http://www.cplusplus.com/forum/general/128037/
// ---------------------------------------------------------------


#include "stdafx.h"
#include <iostream>
#include <vector>
#include "input.cpp"

using namespace std;

const int DIRECTION_LEFT = 1;
const int DIRECTION_RIGHT = 2;
const int DIRECTION_UP = 3;
const int DIRECTION_DOWN = 4;

// set the score
int SCORE = 0;

// setting the direction of the snake
int DIRECTION = DIRECTION_DOWN;

// set the size of the map
const int MAP_WIDTH = 50;
const int MAP_HEIGHT = 20;

// set snake body
const char SNAKE_BODY = '*';

// set array of type of food
const char FOOD_SYMBOLS[] = { '+', '@', '&', '$', '%'};

// set default location of the food
int FOOD_X = 0;
int FOOD_Y = 0;

// set food index
int FOOD_SYMBOL_NUM = 0;

// set the snake body stracture
struct snake_body
{
	int x;
	int y;
};

// set cells of snake body
vector<snake_body> snake;

// set creationg of the snake
void init_snake()
{
	for (int i(0); i < 5; i++)
	{
		snake_body body;
		body.x = -10;
		body.y = -10;

		snake.push_back(body);
	}

	snake[0].x = 5;
	snake[0].y = 3;
}

// set a check if snake eat itself
bool snake_eat_itself()
{
	int head_x = snake[0].x;
	int head_y = snake[0].y;

	for (int i(1); i < snake.size(); i++)
	{
		if (snake[i].x == head_x && snake[i].y == head_y)
		{
			return true;
		}
	}

	return false;
}

// set a check if snake overlaps with coordinates
bool if_snake_body(int x, int y) {
	for (int k(0); k < snake.size(); k++)
	{
		if (snake[k].y == y && snake[k].x == x)
		{
			return true;
		}
	}

	return false;
}

// set a check if coordinates have borders
bool is_map_border(int x, int y)
{
	return y == 0 || x == 0 || x == MAP_WIDTH || y == MAP_HEIGHT;
}

// set a check if coordinates have food in right place
bool is_food(int x, int y)
{
	return FOOD_X == x && FOOD_Y == y;
}

// set check if the snake ate the food
bool snake_ate_food()
{
	for (int i(0); i < snake.size(); i++)
	{
		if (snake[i].x == FOOD_X && snake[i].y == FOOD_Y)
		{
			return true;
		}
	}

	return false;
}

// set check if snake is our of borders
bool is_out_of_border()
{
	return snake[0].x == 0 || snake[0].y == 0 || snake[0].x == MAP_WIDTH || snake[0].y == MAP_HEIGHT;
}

// set random position of the food
void generate_food_coord()
{
	srand(time(0));

	FOOD_X = 3 + rand() % (MAP_WIDTH - 3);
	FOOD_Y = 3 + rand() % (MAP_HEIGHT - 3);
}

// set random food character
void generate_food_symbol() {
	FOOD_SYMBOL_NUM = rand() % sizeof(FOOD_SYMBOLS);
}

// set printed score
void print_score()
{
	printf("\n### SCORE: %d ###\n\n", SCORE);
}

// set draw snake body and map
void draw() {
	system("clear");

	for (int i(0); i <= MAP_HEIGHT; i++)
	{
		for (int j(0); j <= MAP_HEIGHT; j++)
		{
			if (is_map_border(j, i))
			{
				cout << '#' << flush;
			}
			else if (if_snake_body(j, i))
			{
				cout << SNAKE_BODY << flush;
			}
			else if (is_food(j, i))
			{
				cout << FOOD_SYMBOLS[FOOD_SYMBOL_NUM] << flush;
			}
			else
			{
				cout << ' ' << flush;
			}
		}

		cout << "\n";
	}

	print_score();
}

// set the movement of the snake and snake body

void move_snake()
{
	int _x = snake[0].x;
	int _y = snake[0].y;
	int last_x, last_y;

	switch (DIRECTION)
	{
	case DIRECTION_DOWN:	snake[0].y++; break;
	case DIRECTION_LEFT:	snake[0].x--; break;
	case DIRECTION_UP:		snake[0].y--; break;
	case DIRECTION_RIGHT:	snake[0].x++; break;
		default:break;
	}

	for (int i(1); i < snake.size(); i++)
	{
		last_x = snake[i].x;
		last_x = snake[i].y;

		snake[i].x = _x;
		snake[i].y = _y;

		_x = last_x;
		_y = last_y;
	}
}

// set key for 'ESC'
void exit() {
	input_off();

	printf("\n\n### THANK YOU FOR THE GAME, SEE YOU SOON ###\n\n");
}

int main()
{
	fd_set rfds;
	timeval timeout;

	timeout.tv_sec = 0;
	timeout.tv_usec = 0;

	input_on();

	generate_food_coord();
	generate_food_symbol();
	init_snake();

	while (true)
	{
		FD_ZERO(&rfds);
		FD_SET(STDIN_FILENO, &rfds);

		if (select(1, &rfds, NULL, NULL, &timeout) > 0 && FD_ISSET(STDIN_FILENO, &rfds)) {
			switch (getchar())
			{
			case 100:
			case 68: if (DIRECTION != DIRECTION_LEFT) DIRECTION = DIRECTION_RIGHT; break;

			case 83:
			case 115: if (DIRECTION != DIRECTION_UP)  DIRECTION = DIRECTION_DOWN; break;

			case 65:
			case 97: if (DIRECTION != DIRECTION_RIGHT) DIRECTION = DIRECTION_LEFT; break;

			case 119:
			case 87: if (DIRECTION != DIRECTION_DOWN)  DIRECTION = DIRECTION_UP; break;

			case 27: exit(); return 0;
			default:break;
			}
		}

		move_snake();

		if (snake_ate_food())
		{
			generate_food_coord();
			generate_food_symbol();

			snake_body snake_peace;
			snake_peace.x = snake[snake.size() - 1].x;
			snake_peace.y = snake[snake.size() - 1].y;

			snake.push_back(snake_peace);

			SCORE += 7;
		}

		if (is_out_of_border() || snake_eat_itself())
		{
			exit();
			break;
		}

		draw();

		usleep(100000);
	}

	input_off();
    return 0;
}

