// exam_8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "tge.h"

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	clearScreenBuffer(g_chiBuffer);

	drawBox(g_chiBuffer, 3, 3, 5, 3);
	drawBox(g_chiBuffer, 10, 5, 2, 5);

	updateBuffer(hStdout, g_chiBuffer);

    return 0;
}

