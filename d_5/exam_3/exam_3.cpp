// exam_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

// stack - push, pop

#include "stdafx.h"
#include <string.h>

int main()
{
	char szCmd[32];
	char cBufStack[256];
	int nStackPointer = 0;

	while (1)
	{
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0)
		{
			printf_s("Quit program.\n");
			break;
		}
		else if (strcmp("push", szCmd) == 0)
		{
			printf_s("input data : ");
			char _tmp;
			scanf_s("%c", &_tmp, 1);
			scanf_s("%c", &_tmp, 1);
			printf_s("data : %c\n", _tmp);
			cBufStack[nStackPointer] = _tmp;
			nStackPointer++;
		}
		else if (strcmp("pop", szCmd) == 0)
		{
			if (nStackPointer == 0)
			{
				printf_s("stack pointer is 0\n");
			}
			else
			{
				printf_s("output data : %c\n", cBufStack[nStackPointer - 1]);
				nStackPointer--;
				printf_s("stack pointer : %d\n", nStackPointer);
			}	
		}
		else if (strcmp("dump", szCmd) == 0)
		{
			//cBufStack[nStackPointer] = NULL;
			//printf_s("%s\n", cBufStack);

			for (int i = 0; i < nStackPointer; i++)
			{
				printf_s("%c ", cBufStack[i]);
			}
			printf_s("\n");
		}


		//printf_s("입력하신 커맨드는 : %s 입니다.\n", szCmd);

	}

	return 0;
}

