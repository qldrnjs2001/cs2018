// exam_4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void str_get(char (*str)[80])
{
	for (int i = 0; i < 5; i++)
	{
		gets_s(str[i], 80);
	}
}

void str_prn(char (*str)[80])
{
	for (int i = 0; i < 5; i++)
	{
		printf_s("%s\n", str[i]);
	}
} 

int main()
{
	char str_ary[5][80];

	printf_s("다섯 개의 문장을 입력하세요.\n");

	str_get(str_ary);
	
	printf_s("입력된 문장은...\n");

	str_prn(str_ary);

    return 0;
}

