// exam_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"

using namespace TGE;

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	loadBinary(g_chiBuffer, "../exam_2/1.map");

	updateBuffer(hStdout, g_chiBuffer);

    return 0;
}

