// exam_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	printf_s("%d %d\n", ary, ary + 1);
	printf_s("%d %d\n", &ary, &ary + 1);  // &ary + 1 은 전체 배열 주소값을 모두 넘어간다. 즉 배열 안의 다음 주소값이 아닌 배열 전체의 다음 주소값을 가리킴

	int *ptr = NULL;

	printf_s("%d %d\n", ptr, &ptr);

    return 0;
}

