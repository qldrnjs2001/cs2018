// exam_4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
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
		updateBuffer(hStdOut, g_chiBuffer);
	}

    return 0;
}

