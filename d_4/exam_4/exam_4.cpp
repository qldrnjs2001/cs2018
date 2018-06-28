// exam_4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

double largest_num(double a[])
{
	double largest = a[0];
	int i;

	for (i = 1; i < 5; i++)
	{
		if (a[i] > largest)
			largest = a[i];
	}

	return largest;
}

double smallest_num(double a[])
{
	double smallest = a[0];
	int i;

	for (i = 1; i < 5; i++)
	{
		if (a[i] < smallest)
			smallest = a[i];
	}

	return smallest;
}

int main()
{
	double a[5];
	int i;

	for (i = 0; i < 5; i++)
	{
		scanf_s("%lf", &a[i]);
	}

	printf_s("%lf\n", largest_num(a));
	printf_s("%lf\n", smallest_num(a));

    return 0;
}

