// exam_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"
#include "maptool.h"

using namespace TGE;

S_TGE_MAPTOOL g_MapToolObject;
enum { MODE_BRUSH_DRAW = 0, MODE_CMD_INPUT = 1, MODE_BRUSH_MOVE = 2 };

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode;

	GetConsoleMode(hStdin, &fdwOldMode);

	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	initMapTool(&g_MapToolObject);

	static char szCmdBuf[32];

	clearScreenBuffer(0x2e, 0x0007);
	updateBuffer(hStdout, g_chiBuffer);

	int nFSM = MODE_BRUSH_DRAW;
	setCursor(hStdout, 0, 0);
	setCursor(hStdout, 0, 26);

	while (1)
	{
		static char szCmdBuf[32];

		switch (nFSM)
		{
		case MODE_BRUSH_DRAW:
		{
			// 비동기 키입력 처리
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];

			ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++)
			{
				if (irInputBuf[i].EventType == KEY_EVENT)
				{
					if (irInputBuf[i].Event.KeyEvent.bKeyDown)
					{
						setCursor(hStdout, 0, 0);
						setCursor(hStdout, 0, 26);
						printf_s("                                                                               ]");
						setCursor(hStdout, 0, 26);
						printf_s("[ draw mode %d", irInputBuf[i].Event.KeyEvent.wVirtualScanCode);
						//u72 d80 l75 r77
						switch (irInputBuf[i].Event.KeyEvent.wVirtualScanCode)
						{
						case 28:
							nFSM = MODE_CMD_INPUT;
							SetConsoleMode(hStdin, fdwOldMode);
							break;
						case 50:  // m key - brush move mode
							nFSM = MODE_BRUSH_MOVE;
							SetConsoleMode(hStdin, fdwOldMode);
							break;
						case 72:  // up
							g_MapToolObject.m_cdCurrentCursorPos.Y -= 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x", 
								g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							break;
						case 80:  // down
							g_MapToolObject.m_cdCurrentCursorPos.Y += 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x",
								g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							break;
						case 75:  // left
							g_MapToolObject.m_cdCurrentCursorPos.X -= 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x",
								g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							break;
						case 77:  // right
							g_MapToolObject.m_cdCurrentCursorPos.X += 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x",
								g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							break;
						default:
							break;
						}
					}
				}
			}
		}
		break;
		case MODE_CMD_INPUT:
		{
			// 스크립트 입력 처리
			setCursor(hStdout, 0, 0);
			setCursor(hStdout, 0, 26);
			printf_s("[                                                                              ]");
			setCursor(hStdout, 0, 26);
			printf_s("[cmd > ");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			nFSM = 0;
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		}
		break;
		case MODE_BRUSH_MOVE:
		{
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];

			ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++)
			{
				if (irInputBuf[i].EventType == KEY_EVENT)
				{
					if (irInputBuf[i].Event.KeyEvent.bKeyDown)
					{
						setCursor(hStdout, 0, 0);
						setCursor(hStdout, 0, 26);
						printf_s("                                                                               ]");
						setCursor(hStdout, 0, 26);
						printf_s("[ move mode %d", irInputBuf[i].Event.KeyEvent.wVirtualScanCode);
						//u72 d80 l75 r77
						switch (irInputBuf[i].Event.KeyEvent.wVirtualScanCode)
						{
						case 28:
							nFSM = MODE_CMD_INPUT;
							SetConsoleMode(hStdin, fdwOldMode);
							break;
						case 32:  // m key - brush draw mode
							nFSM = MODE_BRUSH_DRAW;
							strcpy_s(szCmdBuf, 32, "moveCursorEnd");
							break;
						case 72:
						{
							g_MapToolObject.m_cdCurrentCursorPos.Y -= 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x",
								g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;
						case 80:
						{
							g_MapToolObject.m_cdCurrentCursorPos.Y += 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x",
								g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;
						case 75:
						{
							g_MapToolObject.m_cdCurrentCursorPos.X -= 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x",
								g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;
						case 77:
						{
							g_MapToolObject.m_cdCurrentCursorPos.X += 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x",
								g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y, g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;
						default:
							break;
						}
					}
				}
			}
		}
		break;
		default:
			break;
		}

		// 커맨드 파싱
		if (!parseCmd(&g_MapToolObject, szCmdBuf))
			break;

		//setCharacter(g_chiBuffer, g_cdCurrentCursorPos.X, g_cdCurrentCursorPos.Y, 0x20, 0x00e0);

		updateBuffer(hStdout, g_chiBuffer);
	}

    return 0;
}

