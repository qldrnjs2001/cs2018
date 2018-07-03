// exam_7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>


bool findKey = false;
bool pickUpKey = false;
bool gameOver = false;

int cPlayMap[64];

int myCharacter = 9;
int myLocationX, myLocationY;

int cTileMap[64] = {
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 1, 0, 0, 3,
	1, 0, 2, 0, 1, 0, 0, 3,
	1, 0, 0, 0, 1, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1
};

const char *TileSet[] = {
	"  ",
	"▦",
	"±",
	"■",
	"  ",
	"  ",
	"  ",
	"  ",
	"  ",
	"♀",
};

int myLocation(int x, int y)
{
	return x + y * 8;
}

int direction(char d)
{
	switch (d)
	{
	case 'w':
		return cTileMap[myLocation(myLocationX, myLocationY - 1)];
	case 's':
		return cTileMap[myLocation(myLocationX, myLocationY + 1)];
	case 'a':
		return cTileMap[myLocation(myLocationX - 1, myLocationY)];
	case 'd':
		return cTileMap[myLocation(myLocationX + 1, myLocationY)];

	default:
		break;
	}
}

void eventCheck(int dir, char move)
{
	if (dir == 1)
	{
		printf_s("there is wall!\n");
	}
	else if (dir == 2)
	{
		printf_s("find KEY!\n");
		findKey = true;
	}
	else if (dir == 3)
	{
		if (pickUpKey)
		{
			printf_s("SUCCESS escaping this room!\n");
			cTileMap[47] = 0;
			cTileMap[39] = 0;
			myLocationX++;
			gameOver = true;
		}
		else
		{
			printf_s("must need key..\n");
		}
	}
	else
	{
		if (move == 'w')
		{
			myLocationY--;
		}
		else if (move == 's')
		{
			myLocationY++;
		}
		else if (move == 'a')
		{
			myLocationX--;
		}
		else if (move == 'd')
		{
			myLocationX++;
		}
	}

}

void dump()
{
	for (int i = 0; i < 64; i++)
		cPlayMap[i] = cTileMap[i];

	cPlayMap[myLocation(myLocationX, myLocationY)] = myCharacter;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			printf_s("%s", TileSet[cPlayMap[y * 8 + x]]);
		}
		printf_s("\n");
	}
}

int main()
{
	myLocationX = 5;
	myLocationY = 2;

	char cmd[32];

	dump();

	while (1)
	{
		printf_s("command>");
		scanf_s("%s", &cmd, sizeof(cmd));

		if (strcmp("quit", cmd) == 0)
		{
			printf_s("quit this game.\n");
			break;
		}
		/*
		else if (strcmp("dump", cmd) == 0)
		{
			for (int i = 0; i < 64; i++)
				cPlayMap[i] = cTileMap[i];

			cPlayMap[myLocation(myLocationX, myLocationY)] = myCharacter;

			for (int y = 0; y < 8; y++)
			{
				for (int x = 0; x < 8; x++)
				{
					printf_s("%s", TileSet[cPlayMap[y * 8 + x]]);
				}
				printf_s("\n");
			}
		}
		else if (strcmp("move", cmd) == 0)
		{
			{char tmp; scanf_s("%c", &tmp, 1); }
			char dir;

			printf_s("enter your direction>");

			scanf_s("%c", &dir, 1);

			if (dir == 'u')
			{
				eventCheck(direction(dir), dir);
			}
			else if (dir == 'd')
			{
				eventCheck(direction(dir), dir);
			}
			else if (dir == 'l')
			{
				eventCheck(direction(dir), dir);
			}
			else if (dir == 'r')
			{
				eventCheck(direction(dir), dir);
			}
		}
		*/
		else if (strcmp("pickup", cmd) == 0)
		{
			if (findKey)
			{
				printf_s("pick up the key!\n");
				pickUpKey = true;
				cTileMap[42] = 0;
				dump();
			}
			else
			{
				printf_s("you dont find the key..\n");
			}
		}
		else if (strcmp("w", cmd) == 0)
		{
			char dir;
			dir = *cmd;
			eventCheck(direction(dir), dir);
			dump();
		}
		else if (strcmp("s", cmd) == 0)
		{
			char dir;
			dir = *cmd;
			eventCheck(direction(dir), dir);
			dump();
		}
		else if (strcmp("a", cmd) == 0)
		{
			char dir;
			dir = *cmd;
			eventCheck(direction(dir), dir);
			dump();
		}
		else if (strcmp("d", cmd) == 0)
		{
			char dir;
			dir = *cmd;
			eventCheck(direction(dir), dir);
			dump();
		}
		else
		{
			printf_s("not existed command.\n");
		}


		if (gameOver)
			break;

	}

	return 0;

}