// exam_1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num, num_1;
	int *ptr;

	num = 3;
	ptr = &num;

	printf_s("%d %d\n", num, *&num);

	printf_s("%d %d\n", *ptr, ptr);

	*ptr = 5;
	printf_s("%d %d\n", *ptr, ptr);
	printf_s("%d %d\n", num, &num);

	int address;

	scanf_s("%d", &address);
	printf_s("%d %d\n", address, *(int *)address);


    return 0;
}

