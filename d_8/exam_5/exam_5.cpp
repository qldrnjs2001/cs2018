// exam_5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void foo()
{
	printf_s("i'm foo\n");
}

void bar()
{
	printf_s("i'm bar\n");
}

int main()
{
	void(*fp)();

	fp = foo;
	fp();

	fp = bar;
	fp();

    return 0;
}

