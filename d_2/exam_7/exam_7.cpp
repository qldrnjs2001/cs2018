// exam_7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int main()
{
	char a;

	//a = 65;
	//a = 'A'; - same result

	scanf_s("%c", &a, sizeof(a)); //scanf_s 마지막 인수 부분에 sizeof() 버퍼 크기 지정해줘야함.

	printf("%d, %c\n", a, a);

    return 0;
}

