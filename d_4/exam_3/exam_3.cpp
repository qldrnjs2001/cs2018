// exam_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

double avg(int a[])
{
	int i;
	int total = 0;
	double avg = 0;

	for (i = 0; i < 5; i++)
	{
		total += a[i];
	}

	avg = (double)total / 5;

	return avg;
}

int main()
{
	int ages[5];	
	int i;

	for (i = 0; i < 5; i++)
	{
		scanf_s("%d", &ages[i]);
	}

	printf_s("%lf", avg(ages));

    return 0;
}

