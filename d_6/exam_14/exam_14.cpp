// exam_14.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int a;
	char szBuf[64];
	scanf_s("%s", szBuf, 64);
	scanf_s("%d", &a);
    
	printf("%d %s\n", a, szBuf);
	
	return 0;
}

