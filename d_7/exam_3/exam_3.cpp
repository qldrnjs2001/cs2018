// exam_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void count()
{
	int a = 0;  // 지역 변수 단순히 함수 안에서 선언된 변수는 함수를 벗어나면 값이 초기화 됨
	a++;
	printf_s("%d\n", a);
}

void count2()
{
	static int a = 0;  // 함수를 벗어나도 함수 안에서 변경된 내용이 적용 됨, 구역 밖에서 접근 불가
	a++;
	printf_s("%d\n", a);
}

void count3(int *a)  // 포인터 참조를 이용해서 함수를 벗어나도 값에 영향을 주도록 만듬
{
	(*a)++;
	printf_s("%d\n", *a);
}

int main()
{
	count();
	count();

	count2();
	count2();

	int a = 0;
;
	count3(&a);
	count3(&a);

    return 0;
}

