// exam_6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>

char cTileMap[64] = {
					1, 1, 1, 1, 1, 1, 1, 1,
					3, 0, 0, 0, 0, 0, 0, 1,
					1, 1, 1, 1, 1, 0, 0, 1,
					1, 0, 0, 0, 0, 0, 0, 1,
					1, 0, 2, 0, 1, 0, 0, 3,
					1, 0, 2, 0, 1, 0, 0, 3,
					1, 0, 0, 0, 1, 0, 0, 1,
					1, 1, 1, 1, 1, 1, 1, 1
					};

int myCharacter = 9;
int myLocation = 21;
int key;

int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf_s("%d", cTileMap[i * 8 + j]);
		}
		printf_s("\n");
	}

	while (1)
	{
		if (kbhit())
		{
			switch (key)
			{
			case 72: //up

			case 75: //left

			case 77: //right

			case 80: //down
			default:
				break;
			}
		}
	}

    return 0;
}

