// exam_5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	int *ptr;

	ptr = &arr[0];
	printf_s("%u\n", ptr);
	printf_s("%d\n", *ptr);

	/*ptr = &arr[0] + 4;
	printf_s("%u\n", ptr);
	printf_s("%d\n", *ptr);*/

	for (int i = 0; i < 5; i++)
	{
		//printf_s("%d\n", *(&arr[0] + i));
		//printf_s("%d\n", arr[i]);  //동일
		printf_s("%d\n", *(arr + i));
		//printf_s("%d\n", *(ptr + i));
	}

	ptr = &arr[2];

	for (int i = 0; i < 3; i++)
	{
		printf_s("%d\n", *(ptr + i));
	}

    return 0;
}

