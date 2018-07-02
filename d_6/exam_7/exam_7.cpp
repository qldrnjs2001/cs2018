// exam_7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

//void ary_prn(int ap[])
void ary_prn(int *ap, int an)
{
	for (int i = 0; i < an; i++)
	{
		printf_s("%d ", *(ap + i));
	}
	printf_s("\n");
}  //함수 안에서 포인터를 가지고 배열의 크기를 구할 수 없다. 배열이 인자로 넘어가면 read only

void ary_input(int *ap)
{
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", ap + i);
	}
	
}

double ary_avg(int *ap)
{
	int i, tot = 0;
	double avg;

	for (i = 0; i < 5; i++)
	{
		tot += ap[i];
	}

	avg = tot / 5.0;

	return avg;
}
int sum(int a, int b)
{
	return a + b;
}

int ary_max(int *ap, int an)
{
	int max = ap[0];

	for (int i = 1; i < an; i++)
	{
		if (max < ap[i])
		{
			max = ap[i];
		}
	}

	return max;
}

int ary_min(int *ap, int an)
{
	int min = ap[0];

	for (int i = 1; i < an; i++)
	{
		if (min > ap[i])
		{
			min = ap[i];
		}
	}

	return min;
}

int main()
{
	int ary[5] = { 10, 20, 30, 40, 50 };

	ary_prn(ary, sizeof(ary)/sizeof(ary[0]));

	printf_s("%lf\n", ary_avg(ary));

	printf_s("max : %d\n", ary_max(ary, sizeof(ary)/sizeof(ary[0])));
	printf_s("min : %d\n", ary_min(ary, sizeof(ary) / sizeof(ary[0])));

    return 0;
}

