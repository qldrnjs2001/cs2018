// exam_5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void printArray(int a[])
{
	for (int i = 0; i < 5; i++)
	{
		printf_s("%d\n", a[i]);
	}
}

int main()
{
	int num[5];

	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &num[i]);
	}

	printArray(num);

	//int num_1[5] = { 1, 3, 5, 7, 9 };
	int num_1[] = { 1, 3, 5, 7, 9 }; // 위 아래 동일

	printArray(num_1);

    return 0;
}

