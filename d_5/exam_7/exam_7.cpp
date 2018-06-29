// exam_7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

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
	case 'u':
		return cTileMap[myLocation(myLocationX, myLocationY - 1)];
	case 'd':
		return cTileMap[myLocation(myLocationX, myLocationY + 1)];
	case 'l':
		return cTileMap[myLocation(myLocationX - 1, myLocationY)];
	case 'r':
		return cTileMap[myLocation(myLocationX + 1, myLocationY)];

	default:
		break;
	}
}

bool findKey = false;
bool pickUpKey = false;

int cPlayMap[64];

int myCharacter = 9;
int myLocationX, myLocationY;

int main()
{
	myLocationX = 5;
	myLocationY = 2;

	char cmd[32];

	while (1)
	{
		printf_s("command>");
		scanf_s("%s", &cmd, sizeof(cmd));

		if (strcmp("quit", cmd) == 0)
		{
			printf_s("quit this game.\n");
			break;
		}
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
				if (direction(dir) == 1)
				{
					printf_s("there is wall!");
				}
				else if (direction(dir) == 2)
				{
					printf_s("find KEY!\n");
					findKey = true;
				}
				else if (direction(dir) == 3)
				{
					if (pickUpKey)
					{
						printf_s("SUCCESS escaping this room!\n");
					}
					else
					{
						printf_s("must need key..\n");
					}
				}
				else
				{
					myLocationY--;
				}

			}
			else if (dir == 'd')
			{
				if (direction(dir) == 1)
				{
					printf_s("there is wall!");
				}
				else
				{
					myLocationY++;
				}
			}
			else if (dir == 'l')
			{
				if (direction(dir) == 1)
				{
					printf_s("there is wall!");
				}
				else
				{
					myLocationX--;
				}
			}
			else if (dir == 'r')
			{
				if (direction(dir) == 1)
				{
					printf_s("there is wall!");
				}
				else
				{
					myLocationX++;
				}
			}
		}

	}

	return 0;

}