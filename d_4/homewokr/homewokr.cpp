// homewokr.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int i = 0, j = 0, k = 0;

	for (i = 0; i < 5; i++)
	{
		for (j = 4; j > i; j--)
		{
			printf(" ");
		}

		for (k = 0; k <= i + (i * 1); k++)
		{
			printf("*");
		}

		printf("\n");
	}

    return 0;
}

