// exam_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void gugudan(int num)
{
	int i = 0;
	for (i = 1; i <= 9; i++)
	{
		printf_s("%d * %d = %d\n", num, i, num * i);
	}
}

int main()
{
	int i;
	
	for (i = 1; i <= 9; i++)
	{
		gugudan(i);
	}

    return 0;
}

