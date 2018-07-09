// exam_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"

using namespace TGE;

int main()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	static char szCmdBuf[32];
	static char szTokenBuf[8][16];

	clearScreenBuffer(0x2e, 0x0007);
	updateBuffer(hStdOut, g_chiBuffer);
	
	while (1)
	{
		setCursor(hStdOut, 0, 26);
		printf_s("                                                                              ]");
		setCursor(hStdOut, 0, 26);
		printf_s("[cmd>");

		gets_s(szCmdBuf, sizeof(szCmdBuf));

		doTokenize(szCmdBuf, szTokenBuf);

		if (!strcmp(szTokenBuf[0], "quit"))
		{
			printf_s("quit this program\n");
			break;
		}
		updateBuffer(hStdOut, g_chiBuffer);
	}
    return 0;
}

