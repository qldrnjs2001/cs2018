// exam_12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char strBuf[64];

	//scanf_s("%s", strBuf, 64);
	gets_s(strBuf, sizeof(strBuf));

	//printf_s("input string : %s\n", strBuf);
	puts("input string : ");
	puts(strBuf);  // puts 자동 개행처리

	printf_s("string input : ");
	char _c;
	_c = getchar();  // enter 받을 때까지 입력 안됌, 한글자만 받음
	putchar(_c);  // 자동 개행 처리 안됌
	putchar('\n');


    return 0;
}

