// exam_1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"

using namespace TGE;

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	clearScreenBuffer(0x2e, 0x0007);

	drawLineH(5, 5, 20, 0x20, 0x00c0);
	
	drawLineV(5, 10, 20, 0x20, 0x00c0);

	drawLineC(8, 5, 15, 10, 0x20, 0x00c0);

	updateBuffer(hStdout, TGE::g_chiBuffer);

    return 0;
}

