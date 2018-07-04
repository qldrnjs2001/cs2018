// exam_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void str_prn(const char **ptr_ary, int cnt)  // 다중 포인터 사용하는 경우 배열 포인터의 인자 넘겨줄 때
{
	int i;

	for (i = 0; i < cnt; i++)
	{
		printf_s("%s\n", ptr_ary[i]);
	}
}

int main()
{
	const char *ptr_ary[] = { "eagle", "tiger", "lion", "squirrel" };
	int cnt;

	cnt = sizeof(ptr_ary) / sizeof(ptr_ary[0]);

	str_prn(ptr_ary, cnt);

    return 0;
}

