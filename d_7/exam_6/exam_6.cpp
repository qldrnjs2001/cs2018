// exam_6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int a_num[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	int i, j;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf_s("%4d", num[j][i]);  // 쉽게 좌표로 따지면 y x 순서
		}
		printf_s("\n");
	}

	printf_s("\n");

	int k, l;

	for (k = 0; k < 3; k++)
	{
		for (l = 0; l < 4; l++)
		{
			printf_s("%4d", a_num[k*4+l]);  // 쉽게 좌표로 따지면 y x 순서
		}
		printf_s("\n");
	}

    return 0;
}

