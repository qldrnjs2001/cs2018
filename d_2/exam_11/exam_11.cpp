// exam_11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf("int size : %d\n", sizeof(int));
	printf("char size : %d\n", sizeof(char));
	printf("double size : %d\n", sizeof(double));
	printf("float size : %d\n", sizeof(float));

	int tmp = 0;

	printf("int size : %d\n", sizeof(tmp));

	char a = 255;
	unsigned char b = a;

	printf("%d %d\n", a, b);
    return 0;
}

