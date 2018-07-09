// exam_5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	HANDLE hStdin;
	DWORD fdwSaveOldMode;  // 모드 초기화를 위한 백업 설정
	DWORD cNumRead, fdwMode;
	INPUT_RECORD irlnBuf[128];  // 다중입력 지원을 받기 위해 임시저장 버퍼

	hStdin = GetStdHandle(STD_INPUT_HANDLE);

	GetConsoleMode(hStdin, &fdwSaveOldMode);  // 현재 모드 저장

	// 마우스 모드 설정
	fdwMode = ENABLE_EXTENDED_FLAGS;
	SetConsoleMode(hStdin, fdwMode);  // 에디터모드 비활성화

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;  // 마우스 모드 활성화
	SetConsoleMode(hStdin, fdwMode);

	bool bLoop = true;

	while (bLoop)
	{
		ReadConsoleInput(hStdin, irlnBuf, sizeof(irlnBuf)/sizeof(INPUT_RECORD), &cNumRead);  // 사용자 입력 기다림 blocking

		for (DWORD i = 0; i < cNumRead; i++)
		{
			switch (irlnBuf[i].EventType)
			{
			case KEY_EVENT:
			{
				if (irlnBuf->Event.KeyEvent.bKeyDown)
				{
					printf_s("key pressed : %d\n", irlnBuf[i].Event.KeyEvent.wVirtualKeyCode);
				}
				else
				{
					if (irlnBuf[i].Event.KeyEvent.wVirtualKeyCode == 81)
					{
						bLoop = false;
					}
					printf_s("key released : %d\n", irlnBuf[i].Event.KeyEvent.wVirtualKeyCode);
				}
			}
			break;
			case MOUSE_EVENT:
			{
				if (irlnBuf[i].Event.MouseEvent.dwButtonState == 1)
				{
					printf_s("%d %d\n", irlnBuf[i].Event.MouseEvent.dwMousePosition.X, irlnBuf[i].Event.MouseEvent.dwMousePosition.Y);
				}
				//printf("%d %d\n", irlnBuf[i].Event.MouseEvent.dwButtonState, irlnBuf[i].Event.MouseEvent.dwEventFlags);
			}
			break;
			default:
				break;
			}
		}
	}

	SetConsoleMode(hStdin, fdwSaveOldMode);

    return 0;
}

