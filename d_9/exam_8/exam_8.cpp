// exam_8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	FILE *fp;
	fopen_s(&fp, "b.txt", "w");

	char ch;

	fputc('a', fp);

	if (fp == NULL)
	{
		printf_s("failure open file\n");
		return 1;
	}
	printf_s("input data :\n");
	while (1)
	{
		ch = getchar();
		if (ch == EOF)
			break;
		fputc(ch, fp);
	}

	fclose(fp);

    return 0;
}

