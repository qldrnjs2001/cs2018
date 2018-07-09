// homework.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
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
		setCursor(hStdOut, 0, 0);
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
		else if (!strcmp(szTokenBuf[0], "set"))
		{
			int _xpos = atoi(szTokenBuf[1]);
			int _ypos = atoi(szTokenBuf[2]);
			int _code = strtol(szTokenBuf[3], NULL, 16);  // 문자형 16진수로 변환
			int _attr = strtol(szTokenBuf[4], NULL, 16);

			setCharacter(g_chiBuffer, _xpos, _ypos, _code, _attr);
		}
		else if (!strcmp(szTokenBuf[0], "clear"))
		{
			clearScreenBuffer(0x2e, 0x0007);
		}
		else if (!strcmp(szTokenBuf[0], "save"))
		{
			FILE *fp;
			fopen_s(&fp, szTokenBuf[1], "w");

			for (int i = 0; i < 2000; i++)
			{
				fprintf_s(fp, "%d %d\n", g_chiBuffer[i].Char.UnicodeChar, g_chiBuffer[i].Attributes);
			}

			fclose(fp);
		}
		else if (!strcmp(szTokenBuf[0], "load"))
		{
			FILE *fp;
			fopen_s(&fp, szTokenBuf[1], "r");

			int n = 0;
			static char szLTokenBuf[8][16];
			while (fgets(szCmdBuf, sizeof(szCmdBuf), fp) != NULL)
			{
				//printf_s("%d %s", n, szCmdBuf);
				doTokenize(szCmdBuf, szLTokenBuf);
				WCHAR _wCode = atoi(szLTokenBuf[0]);
				WORD _wAttr = atoi(szLTokenBuf[1]);

				g_chiBuffer[n].Char.UnicodeChar = _wCode;
				g_chiBuffer[n].Attributes = _wAttr;
				n++;
			}

			/*  간단한 코드
			for (int i = 0; i < 2000; i++)
			{
			fscanf_s(fp, "%d %d\n", &g_chiBuffer[i].Char.UnicodeChar, &g_chiBuffer[i].Attributes);
			}
			*/

			fclose(fp);
		}
		// lineV 3 4 8 0x20 0x00c0  -  x y 좌표 선 길이 문자 색(세로선)
		else if (!strcmp(szTokenBuf[0], "lineV"))
		{
			int _xpos = atoi(szTokenBuf[1]);
			int _ypos = atoi(szTokenBuf[2]);
			int _nLength = atoi(szTokenBuf[3]);
			int _code = strtol(szTokenBuf[4], NULL, 16);  // 문자형 16진수로 변환
			int _attr = strtol(szTokenBuf[5], NULL, 16);

			drawLineV(_xpos, _ypos, _nLength, _code, _attr);
		}
		// lineH 3 4 8 0x20 0x00c0  -  x y 좌표 선 길이 문자 색(가로선)
		else if (!strcmp(szTokenBuf[0], "lineH"))
		{
			int _xpos = atoi(szTokenBuf[1]);
			int _ypos = atoi(szTokenBuf[2]);
			int _nLength = atoi(szTokenBuf[3]);
			int _code = strtol(szTokenBuf[4], NULL, 16);  // 문자형 16진수로 변환
			int _attr = strtol(szTokenBuf[5], NULL, 16);

			drawLineH(_xpos, _ypos, _nLength, _code, _attr);
		}
		// lineC 0 0 10 0x20 0x00c0  -  시작점 x y 좌표 높이 문자 색(삼각형)
		else if (!strcmp(szTokenBuf[0], "lineC"))
		{
			int _x1 = atoi(szTokenBuf[1]);
			int _y1 = atoi(szTokenBuf[2]);
			int _x2 = atoi(szTokenBuf[3]);
			int _y2 = atoi(szTokenBuf[4]);
			int _code = strtol(szTokenBuf[5], NULL, 16);  // 문자형 16진수로 변환
			int _attr = strtol(szTokenBuf[6], NULL, 16);

			drawLineC(_x1, _y1, _x2, _y2, _code, _attr);
		}
		// drawBox 0 0 10 10 0x20 0x00c0  -  시작점 x y 좌표 넓이 높이 문자 색(사각형)
		else if (!strcmp(szTokenBuf[0], "drawBox"))
		{
			int _xpos = atoi(szTokenBuf[1]);
			int _ypos = atoi(szTokenBuf[2]);
			int _nWidth = atoi(szTokenBuf[3]);
			int _nLength = atoi(szTokenBuf[4]);
			int _code = strtol(szTokenBuf[5], NULL, 16);  // 문자형 16진수로 변환
			int _attr = strtol(szTokenBuf[6], NULL, 16);

			drawBox(_xpos, _ypos, _nWidth, _nLength, _code, _attr);
		}
		// drawTri 0 0 10 0x20 0x00c0  -  시작점 x y 좌표 높이 문자 색(삼각형)
		else if (!strcmp(szTokenBuf[0], "drawTri"))
		{
			int _xpos = atoi(szTokenBuf[1]);
			int _ypos = atoi(szTokenBuf[2]);
			int _nLength = atoi(szTokenBuf[3]);
			int _code = strtol(szTokenBuf[4], NULL, 16);  // 문자형 16진수로 변환
			int _attr = strtol(szTokenBuf[5], NULL, 16);

			drawTriangle(_xpos, _ypos, _nLength, _code, _attr);
		}
		updateBuffer(hStdOut, g_chiBuffer);
	}

    return 0;
}

