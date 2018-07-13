// exam_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"
#include "playerObject.h"

using namespace TGE;
using namespace playerobject;
/*
// player object 
COORD g_cdPlayerPos;
int g_nInven_keyCount;
*/
S_PlayerObject g_gamePlayer;

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode;
	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	CHAR_INFO *pBackScreenBuffer = CreateScreenBuffer();
	CHAR_INFO *pMapDataBuffer = CreateScreenBuffer();


	loadBinary(pMapDataBuffer, "../../pub_res/1.map");

	Init(&g_gamePlayer, 5, 5);
	//g_cdPlayerPos.X = 5;
	//g_cdPlayerPos.Y = 5;

	bool _bLoop = true;
	static int _nFSM = 0;

	while (_bLoop)
	{
		static char szCmdBuf[128];
		// 입력처리
		switch (_nFSM)
		{
		case 0:  // 비동기 모드
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];

			ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++)
			{
				if (irInputBuf[i].EventType == KEY_EVENT)
				{
					if (irInputBuf[i].Event.KeyEvent.bKeyDown)
					{
						switch (irInputBuf[i].Event.KeyEvent.wVirtualKeyCode)
						{
						case VK_RETURN:  // 커맨드 입력 모드
							_nFSM = 1;
							SetConsoleMode(hStdin, fdwOldMode);
							break;
						case VK_UP:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 0 -1");
							break;
						case VK_DOWN:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 0 1");
							break;
						case VK_LEFT:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move -1 0");
							break;
						case VK_RIGHT:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 1 0");
							break;
						}
					}
				}
			}
			break;
		case 1:  // 동기 모드
			setCursor(hStdout, 0, 0);
			setCursor(hStdout, 0, 26);
			printf_s("[                                                                              ]");
			setCursor(hStdout, 0, 26);
			printf_s("[cmd > ");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			_nFSM = 0;
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			break;
		default:
			break;
		}

		// 커맨드 처리
		{
			char szTokenBuf[8][32];
			if (doTokenize(szCmdBuf, szTokenBuf) > 0)
			{
				if (!strcmp(szTokenBuf[0], "quit"))
				{
					_bLoop = false;
				}
				else if (!strcmp(szTokenBuf[0], "move"))
				{
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					move(&g_gamePlayer, pMapDataBuffer, _dx, _dy);
				}
				else if (!strcmp(szTokenBuf[0], "use"))
				{
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					switch (use(&g_gamePlayer, pMapDataBuffer, _dx, _dy))
					{
					case 0x00c0:
						printf_s("open the door.");
						break;
					case 0x00a0:
						printf_s("success escape the room.\n");
						_bLoop = false;
						break;
					default:
						printf_s("there is not door.");
						break;
					}
				}
				else if (!strcmp(szTokenBuf[0], "get"))
				{
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					if (get(&g_gamePlayer, pMapDataBuffer, _dx, _dy) == 1)
					{
						printf_s("find key!");
					}
					else
					{
						printf_s("there is nothing.");
					}
				}
				else if (!strcmp(szTokenBuf[0], "drop"))
				{

				}
				else if (!strcmp(szTokenBuf[0], "teleport"))
				{
					int _x = atoi(szTokenBuf[1]);
					int _y = atoi(szTokenBuf[2]);

					//g_cdPlayerPos.X = _x;
					//g_cdPlayerPos.Y = _y;
				}
			}
			szCmdBuf[0] = 0x00;
		}

		// clear buffer
		memcpy_s(pBackScreenBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pMapDataBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));


		// 오브젝트 처리
		DrawObject(&g_gamePlayer, pBackScreenBuffer);


		// 랜더 (화면 갱신)
		memcpy_s(g_chiBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pBackScreenBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));
		updateBuffer(hStdout, g_chiBuffer);
	}

	free(pBackScreenBuffer);
	free(pMapDataBuffer);

	return 0;
}

