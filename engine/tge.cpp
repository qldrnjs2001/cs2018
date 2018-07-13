#include "stdafx.h"

//80x25
#include "tge.h"

namespace TGE
{
	CHAR_INFO g_chiBuffer[SCREEN_BUF_SIZE];

	void setCursor(HANDLE handle, int x, int y)
	{
		COORD _pos;
		_pos.X = x;
		_pos.Y = y;
		SetConsoleCursorPosition(handle, _pos);
	}

	void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr)
	{
		pBuf[(80 * y) + x].Char.UnicodeChar = code;
		pBuf[(80 * y) + x].Attributes = attr;
	}

	CHAR_INFO *getCharacter(CHAR_INFO *pBuf, int x, int y)
	{
		return &(pBuf[(80 * y) + x]);
	}

	CHAR_INFO *CreateScreenBuffer()
	{
		return (CHAR_INFO *)malloc(sizeof(CHAR_INFO) * SCREEN_BUF_SIZE);
	}
	

	void clearScreenBuffer(WCHAR _wCode, WORD _wAttr)
	{
		CHAR_INFO *pBuf = TGE::g_chiBuffer;

		clearScreenBuffer(pBuf, _wCode, _wAttr);
	}

	void clearScreenBuffer(CHAR_INFO *pBuf, WCHAR _wCode, WORD _wAttr)
	{
		for (int i = 0; i < SCREEN_BUF_SIZE; i++)
		{
			pBuf[i].Char.UnicodeChar = _wCode;  //9643;
			pBuf[i].Attributes = _wAttr;  //0x009f;
		}
	}

	void CopyScreenBuffer(CHAR_INFO *pBufdest, CHAR_INFO *pBufsrc)
	{
		memcpy_s(pBufdest, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pBufsrc, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));
	}

	void updateBuffer(HANDLE handle, CHAR_INFO *pBuf)
	{
		COORD coordBufSize;
		COORD coordBufferCoord;

		coordBufSize.X = 80;
		coordBufSize.Y = 25;
		coordBufferCoord.X = 0;
		coordBufferCoord.Y = 0;

		SMALL_RECT destRect;
		destRect.Top = 0;
		destRect.Left = 0;
		destRect.Bottom = coordBufSize.Y + coordBufSize.Y - 1;
		destRect.Right = coordBufSize.X + coordBufSize.X - 1;

		WriteConsoleOutput(handle, pBuf, coordBufSize, coordBufferCoord, &destRect);
	}

	void drawBox(int _posx, int _posy, int _width, int _height, WCHAR code, WORD attr)
	{
		int x, y;

		for (y = 0; y < _height; y++)
		{
			for (x = 0; x < _width; x++)
			{
				setCharacter(TGE::g_chiBuffer, _posx + x, _posy + y, code, attr);
			}
		}
	}

	void drawTriangle(int _posx, int _posy, int _height, WCHAR code, WORD attr)
	{
		int x, y;

		for (y = 0; y < _height; y++)
		{
			for (x = 0; x < y; x++)
			{
				setCharacter(TGE::g_chiBuffer, _posx + x, _posy + y, code, attr);
			}
		}
	}

	void drawLineH(int _x, int _y, int nLength, WCHAR code, WORD attr)
	{
		for (int i = 0; i < nLength; i++)
		{
			setCharacter(TGE::g_chiBuffer, _x + i, _y, code, attr);
		}
	}

	void drawLineV(int _x, int _y, int nLength, WCHAR code, WORD attr)
	{
		for (int i = 0; i < nLength; i++)
		{
			setCharacter(TGE::g_chiBuffer, _x, _y+i, code, attr);
		}
	}

	void drawLineC(int _x1, int _y1, int _x2, int _y2, WCHAR code, WORD attr)
	{
		int x, y;

		for (x = _x1; x <= _x2; x++)
		{
			y = (int)((_y2 - _y1) / (_x2 - _x1))*(x - _x1) + _y1;
			setCharacter(TGE::g_chiBuffer, x, y, code, attr);
		}
	}

	int doTokenize(char *szBuf, char szBufToken[8][MAX_TOKEN_SIZE])
	{
		char *szpTemp;
		char *pNextToken = NULL;
		const char *pszDelimiter = " ";

		szpTemp = strtok_s(szBuf, pszDelimiter, &pNextToken);

		int _nTokenIndex = 0;

		while (szpTemp != NULL)
		{
			strcpy_s(szBufToken[_nTokenIndex], sizeof(szBufToken[_nTokenIndex]), szpTemp);
			_nTokenIndex++;

			szpTemp = strtok_s(NULL, pszDelimiter, &pNextToken);
		}

		return _nTokenIndex;
	}

	int loadBinary(CHAR_INFO *pBuf, const char *szFileName)
	{
		FILE *fp;
		fopen_s(&fp, szFileName, "r");

		fread_s(pBuf, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), sizeof(CHAR_INFO), SCREEN_BUF_SIZE, fp);

		fclose(fp);

		return 0;
	}

	int saveBinary(CHAR_INFO *pBuf, const char *szFileName)
	{
		FILE *fp;
		fopen_s(&fp, szFileName, "w");

		fwrite(pBuf, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), 1, fp);

		fclose(fp);

		return 0;
	}

	//sprite print
	void putSprite(int posx, int posy, int destw, int desth, int srcw, int srch, CHAR_INFO *pDest, CHAR_INFO *pSrc)
	{
		//dsetw, h 출력될 버퍼의 넓이, 높이
		//srcw, h 출력할 버퍼의 넓이, 높이

		int _x;
		int _y;
		_x = posx;
		_y = posy;
		int src_buf_size = srcw * srch;
		int nStep = 0;
		int _i = 0;
		for (int i = 0; i < src_buf_size; i++)
		{
			nStep = i / srcw;
			pDest[_i + (nStep * SCREEN_WIDTH) + (_y*SCREEN_WIDTH + _x)] = pSrc[i];
			_i++;
			_i %= srcw;
		}
	}

	void putSprite(int posx, int posy, int srcw, int srch, CHAR_INFO *pDest, CHAR_INFO *pSrc)
	{
		putSprite(posx, posy, SCREEN_WIDTH, 25, srcw, srch, pDest, pSrc);
	}

	namespace input {
		char g_KeyTable[1024];
		DWORD _oldInputMode;
		HANDLE hStdin;
		COORD g_cdMousePos;

		DWORD WINAPI MyThreadFunction(LPVOID lpParam)
		{
			hStdin = GetStdHandle(STD_INPUT_HANDLE);
			DWORD _NumRead;
			INPUT_RECORD irInBuf[128];

			GetConsoleMode(hStdin, &_oldInputMode);
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

			while (1)
			{
				ReadConsoleInput(hStdin, irInBuf, 128, &_NumRead);

				for (DWORD i = 0; i < _NumRead; i++)
				{
					if (irInBuf[i].EventType == KEY_EVENT)
					{
						if (irInBuf[i].Event.KeyEvent.bKeyDown)
						{
							g_KeyTable[irInBuf[i].Event.KeyEvent.wVirtualKeyCode] = 1;
						}
						else
						{
							g_KeyTable[irInBuf[i].Event.KeyEvent.wVirtualKeyCode] = 0;
						}
					}
					else if (irInBuf[i].EventType == MOUSE_EVENT)
					{
						g_cdMousePos = { irInBuf[i].Event.MouseEvent.dwMousePosition.X, irInBuf[i].Event.MouseEvent.dwMousePosition.Y };
					}

				}
				Sleep(1);
			}

			SetConsoleMode(hStdin, _oldInputMode);

			return 0;
		}

		void setEditMode()
		{
			SetConsoleMode(hStdin, _oldInputMode);
		}

		void setNormalMode()
		{
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
		}
	}

	DWORD dwThreadId_ReadInput;
	HANDLE hThread_ReadInput;

	void startTGE(HANDLE *phStdout)
	{
		*phStdout = GetStdHandle(STD_OUTPUT_HANDLE);

		TGE::clearScreenBuffer(0x20, 0x0090);

		hThread_ReadInput = CreateThread(NULL, 0, input::MyThreadFunction, NULL, 0, &dwThreadId_ReadInput);
	}

	void endTGE()
	{

	}

	namespace util 
	{
		UINT64 GetTimeMs64()
		{
			FILETIME ft;
			LARGE_INTEGER li;

			GetSystemTimeAsFileTime(&ft);
			li.LowPart = ft.dwLowDateTime;
			li.HighPart = ft.dwHighDateTime;

			UINT64 ret_value = li.QuadPart;
			ret_value -= 116444736000000000LL;
			ret_value /= 10000;

			return ret_value;
		}
	}
}