// exam_7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[] = {2, 8, 15, 1, 8, 10, 5, 19, 19, 3, 5, 6, 6, 2, 8, 2, 12, 16, 3, 8, 17,
				12, 5, 3, 14, 13, 3, 2, 17, 19, 16, 8, 7, 12, 19, 10, 13, 8, 20,
				16, 15, 4, 12, 3, 14, 14, 5, 2, 12, 14, 9, 8, 5, 3, 18, 18, 20, 4};
	int num = 0;
	int cnt = 0;
	int ary_size = sizeof(ary) / sizeof(int);

	printf_s("찾기를 원하는 숫자를 입력하세요(1~20) : ");
	scanf_s("%d", &num);

	for (int i = 0; i < ary_size; i++)
	{
		if (ary[i] == num)
			cnt++;
	}

	printf_s("숫자 %d는 배열에 %d개 있습니다.", num, cnt);

    return 0;
}

