// exam_13.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char _szBuf[8];

	for (int i = 0; i < 8; i++)
	{
		_szBuf[i] = getchar();
	}

	printf("%s\n", _szBuf);

    return 0;
}

