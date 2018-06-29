// exam_5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//add 문자열 버퍼에 입력
//del 특정 위치 문자 삭제
//ins 특정 위치 문자 삽입

#include "stdafx.h"
#include <string.h>

int main()
{
	char szCmd[32];
	char cBuf[256];
	int nLength = 0;

	while (1)
	{
		printf_s("command>");
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0)
		{
			printf_s("Quit program.\n");
			break;
		}
		else if (strcmp("add", szCmd) == 0)
		{
			char add_char[32];
			int add_char_length = 0;
			char tmp;

			printf("add string>");
			scanf_s("%c", &tmp, 1);
			scanf_s("%s", &add_char, sizeof(add_char));

			for (int i = 0; i < sizeof(add_char); i++)
			{
				if (add_char[i] == NULL)
					break;
				add_char_length++;
			}

			for (int i = 0; i < add_char_length; i++)
			{
				cBuf[nLength] = add_char[i];
				nLength++;
			}

			printf_s("%s added.\n", add_char);
		}
		else if (strcmp("insert", szCmd) == 0)
		{
			int ins_index = 0;
			char ins_char;
			char tmp;
			printf_s("insert index>");
			scanf_s("%c", &tmp, 1);
			scanf_s("%d", &ins_index, sizeof(int));
			printf_s("insert character>");
			scanf_s("%c", &tmp, 1);
			scanf_s("%c", &ins_char, sizeof(ins_char));

			for (int i = nLength; i > ins_index; i--)
			{
				cBuf[i] = cBuf[i - 1];
			}
			cBuf[ins_index] = ins_char;
			nLength++;
			printf_s("insert %c in index %d.\n", ins_char, ins_index);
		}
		else if (strcmp("delete", szCmd) == 0)
		{
			int del_index = 0;
			char tmp;
			printf_s("delete index>");
			scanf_s("%c", &tmp, 1);
			scanf_s("%d", &del_index, sizeof(int));

			for (int i = del_index; i < nLength; i++)
			{
				cBuf[i] = cBuf[i + 1];
			}
			nLength--;
			printf_s("delete character in index %d.\n", del_index);
		}
		else if (strcmp("dump", szCmd) == 0)
		{
			for (int i = 0; i < nLength; i++)
			{
				printf_s("%c", cBuf[i]);
			}
			printf_s("\n");
		}
		else
		{
			printf_s("input command is %s\n", szCmd);
		}
	}
    return 0;
}

