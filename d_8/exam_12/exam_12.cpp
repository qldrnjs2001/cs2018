// exam_12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	const char *szMsg = "hello world";
	char *pTmp;

	pTmp = (char *)malloc(7);

	//strcpy_s(pTmp, strlen(szMsg) + 1, szMsg);

	memcpy(pTmp, szMsg + 4, 6);  // 일부분만 copy 하는 함수
	pTmp[6] = 0x00;

	printf_s("%s\n", pTmp);

	free(pTmp);

    return 0;
}

