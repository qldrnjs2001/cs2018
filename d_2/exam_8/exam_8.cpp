// exam_8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char strTemp[5] = "한글";
	//char strTemp[5];
	//strTemp = "한글";

	printf("%s\n", strTemp);

	scanf_s("%s", &strTemp, sizeof(strTemp));

	printf("%s\n", strTemp);

    return 0;
}

