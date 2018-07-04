// exam_11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

const char *strpWorldArea[32] = {
	"큰 방 한가운데 작은 탁자가 놓여있고 북쪽과 서쪽 동쪽에 문이 있다.",
	"북쪽에 출구가 보인다. 그렇지만 무섭게 생긴 개가 지키고있다.",
	"작은 정원 같은 곳이다. 누군가 파티를 했던 흔적이 있다. 개가 좋아할만한 뼈다귀들이 보인다.",
	""
};

const char *strpAreaAction[32] = {
	"탁자를 살펴보았지만 아무것도 없었다.",
	"출구로 나가려 했지만, 개가 달라들 것 같아 지나갈 수 가 없다.",
	"개가 좋아할만한 뼈다귀를 주었다.",
	"개에게 뼈다귀를 물려주었다.",
	"탈출에 성공했다."
};

bool bornChecker = false;
bool dogEatingBorn = false;
bool gameOver = false;

int g_nCurrentPos = 0;

int g_wayTable[32][4] = {
	{-1, 2, -1, 1},
	{-1, -1, 0, -1},
	{0, -1, -1, -1}  // 동서남북
};

void actionCheck(int currentPos)
{
	if (currentPos == 0)
	{
		printf_s("%s \n", strpAreaAction[0]);
	}
	else if (currentPos == 1)
	{
		if (bornChecker)
		{
			if (dogEatingBorn)
			{
				printf_s("%s \n", strpAreaAction[4]);
				gameOver = true;
			}
			else
			{
				printf_s("%s \n", strpAreaAction[3]);
				dogEatingBorn = true;
			}
		}
		else
		{
			printf_s("%s \n", strpAreaAction[1]);
		}
		
	}
	else if (currentPos == 2)
	{
		printf_s("%s \n", strpAreaAction[2]);
		bornChecker = true;
	}
}

int main()
{
	char szCmdBuf[32];

	while (1)
	{
		printf_s("command>");
		gets_s(szCmdBuf, sizeof(szCmdBuf));

		if (strcmp(szCmdBuf, "quit") == 0)
		{
			break;
		}
		else if (strcmp(szCmdBuf, "see") == 0)
		{
			printf_s("%s \n", strpWorldArea[g_nCurrentPos]);
		}
		else if (strcmp(szCmdBuf, "move") == 0)
		{
			int nDir;

			printf_s("방향을 입력하세요. 동서남북(0, 1, 2, 3) - > ");
			scanf_s("%d", &nDir);

			int new_pos = g_wayTable[g_nCurrentPos][nDir];

			if (new_pos == -1)
			{
				printf_s("갈 수 없습니다.\n");
			}
			else
			{
				printf_s("이동 합니다.\n");
				g_nCurrentPos = new_pos;
			}
		}
		else if (strcmp(szCmdBuf, "action") == 0)
		{
			actionCheck(g_nCurrentPos);
		}
		else
		{
			printf_s("%s is not registed command\n", szCmdBuf);
		}
		if (gameOver)
			break;
	}
    return 0;
}

