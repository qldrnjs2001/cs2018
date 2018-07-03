// exam_5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int g_nCounter = 0;

void count()
{
	printf_s("%d\n", ++g_nCounter);
}

void decount()
{
	printf_s("%d\n", --g_nCounter);
}

void reset()
{
	g_nCounter = 0;
	printf_s("%d\n", g_nCounter);
}

int main()
{
	char szCmdBuf[32];

	while (1)
	{
		printf_s("input command>");
		gets_s(szCmdBuf, sizeof(szCmdBuf));

		if (strcmp(szCmdBuf, "quit") == 0)
		{
			break;
		}
		else if (strcmp(szCmdBuf, "count") == 0)
		{
			count();
		}
		else if (strcmp(szCmdBuf, "decount") == 0)
		{
			decount();
		}
		else if (strcmp(szCmdBuf, "reset") == 0)
		{
			reset();
		}
		else
		{
			printf_s("%s is not registed command\n", szCmdBuf);
		}
	}

	printf_s("quit the program.\n");

	return 0;
}
