// exam_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	char szCmd[32];

	while (1)
	{
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0)
		{
			printf_s("프로그램을 종료합니다.\n");
			break;
		}

		printf_s("입력하신 커맨드는 : %s 입니다.\n", szCmd);

	}

    return 0;
}

