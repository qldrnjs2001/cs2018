// exam_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"

using namespace TGE;

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	clearScreenBuffer(0x2e, 0x0007);
	updateBuffer(hStdout, g_chiBuffer);

	static char szBuf[32];
	static char szBufToken[8][16];	

	while (1)
	{
		COORD _cursor;
		_cursor.X = 0;
		_cursor.Y = 26;

		SetConsoleCursorPosition(hStdout, _cursor);
		printf_s("                                                                                         ");
		SetConsoleCursorPosition(hStdout, _cursor);
		printf_s("cmd>");
		

		gets_s(szBuf, sizeof(szBuf));

		doTokenize(szBuf, szBufToken);

		if (strcmp(szBufToken[0], "quit") == 0)
		{
			printf_s("quit this program\n");
			break;
		}
		// setchar 3 4 0x20 0x00e0  -  x y 좌표 문자 색
		else if (strcmp(szBufToken[0], "setchar") == 0)
		{
			int _xpos = atoi(szBufToken[1]);
			int _ypos = atoi(szBufToken[2]);
			int _code = strtol(szBufToken[3], NULL, 16);  // 문자형 16진수로 변환
			int _attr = strtol(szBufToken[4], NULL, 16);

			setCharacter(g_chiBuffer, _xpos, _ypos, _code, _attr);
		}
		// buffer reset
		else if (strcmp(szBufToken[0], "clear") == 0)
		{
			clearScreenBuffer(0x2e, 0x0007);
		}
		// lineV 3 4 8 0x20 0x00c0  -  x y 좌표 선 길이 문자 색(세로선)
		else if (strcmp(szBufToken[0], "lineV") == 0)
		{
			int _xpos = atoi(szBufToken[1]);
			int _ypos = atoi(szBufToken[2]);
			int _nLength = atoi(szBufToken[3]);
			int _code = strtol(szBufToken[4], NULL, 16);  // 문자형 16진수로 변환
			int _attr = strtol(szBufToken[5], NULL, 16);

			drawLineV(_xpos, _ypos, _nLength, _code, _attr);
		}
		// lineH 3 4 8 0x20 0x00c0  -  x y 좌표 선 길이 문자 색(가로선)
		else if (strcmp(szBufToken[0], "lineH") == 0)
		{
			int _xpos = atoi(szBufToken[1]);
			int _ypos = atoi(szBufToken[2]);
			int _nLength = atoi(szBufToken[3]);
			int _code = strtol(szBufToken[4], NULL, 16);  // 문자형 16진수로 변환
			int _attr = strtol(szBufToken[5], NULL, 16);

			drawLineH(_xpos, _ypos, _nLength, _code, _attr);
		}
		updateBuffer(hStdout, g_chiBuffer);
	}

    return 0;
}

