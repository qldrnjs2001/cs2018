// exam_7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	FILE *fp;
	char ch;
	
	fopen_s(&fp, "a.txt", "r");  // fp = fopen("a.txt", "r");

	if (fp == NULL)
	{
		printf_s("failure open file\n");
	}
	else
	{
		/*
		ch = fgetc(fp);
		//ch = fgetc(stdin);
		printf_s("input character : %c\n", ch);
		*/

		while (1)
		{
			ch = fgetc(fp);
			if (ch == EOF)
			{
				break;
			}
			else
				printf_s("%c", ch);
		}
		printf_s("\n");

		fclose(fp);
	}

    return 0;
}

