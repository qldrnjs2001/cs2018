// exam_6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int arr[5] = { 1,2,3,4,5 };

	int *ptr = arr;

	printf_s("%d\n", arr[2]);
	printf_s("%d\n", *(ptr+2));
	printf_s("%d\n", *(arr+2));
	printf_s("%d\n", ptr[2]);  //모두 동일

	//arr = ptr + 2;  //error 배열명은 변수가 아니므로 자신의 값을 바꿀 수 없다.

    return 0;
}

