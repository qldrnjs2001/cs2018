// exam_8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char animal[5][16];
	int animal_num = 0;

	char szCmdBuf[32];

	while (1)
	{
		printf_s("input command>");
		gets_s(szCmdBuf, sizeof(szCmdBuf));

		if (strcmp(szCmdBuf, "quit") == 0)
		{
			break;
		}
		else if (strcmp(szCmdBuf, "add") == 0)
		{
			printf_s("what is added animal?");
			gets_s(animal[animal_num], 16);
			animal_num++;
		}
		else if (strcmp(szCmdBuf, "list") == 0)
		{
			printf_s("print your animal\n");
			for (int i = 0; i < animal_num; i++)
			{
				printf_s("%8s\n", animal[i]);
			}
		}
		else
		{
			printf_s("%s is not registed command\n", szCmdBuf);
		}
	}

	printf_s("quit the program.\n");

	return 0;
}

