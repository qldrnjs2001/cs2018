// exam_6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int arr[] = { 1, 2, 3 };

	int int_size = sizeof(int);
	//int arrElement_size = sizeof(arr[0]);  //배열의 첫번째 값을 넣어도 그 형을 알 수 있기 때문에 이렇게도 쓴다.
	int array_size = sizeof(arr) / int_size; // sizeof는 바이트 값을 반환하기 때문에

	printf_s("%d\n", array_size);

	for (int i = 0; i < array_size; i++)
	{
		printf_s("%d", arr[i]);
	}

	printf_s("\n");

    return 0;
}

