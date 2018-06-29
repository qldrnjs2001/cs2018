// exam_4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

int main()
{
	char szCmd[32];
	char cBufQueue[256];
	int nHead = 0;

	while (1)
	{
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0)
		{
			printf_s("Quit program.\n");
			break;
		}
		else if (strcmp("insert", szCmd) == 0)
		{
			printf_s("input data : ");
			char _tmp;
			scanf_s("%c", &_tmp, 1);
			scanf_s("%c", &_tmp, 1);
			printf_s("data : %c\n", _tmp);
			cBufQueue[nHead++] = _tmp;
		}
		else if (strcmp("delete", szCmd) == 0)
		{
			if (nHead == 0)
			{
				printf_s("empty queue\n");
			}
			else
			{
				printf_s("output data : %c\n", cBufQueue[0]);
				for (int i = 0; i < nHead; i++)
				{
					cBufQueue[i] = cBufQueue[i + 1];
				}
				nHead--;
				printf_s("queue pointer : %d\n", nHead);
			}
		}
		else if (strcmp("dump", szCmd) == 0)
		{
			//cBufStack[nStackPointer] = NULL;
			//printf_s("%s\n", cBufStack);

			for (int i = 0; i < nHead; i++)
			{
				printf_s("%c ", cBufQueue[i]);
			}
			printf_s("\n");
		}


		//printf_s("입력하신 커맨드는 : %s 입니다.\n", szCmd);

	}

	return 0;
}

