#include "stdafx.h"

//80x25
#define SCREEN_BUF_SIZE 2000
#define SCREEN_WIDTH 80

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

	void clearScreenBuffer(WCHAR _wCode, WORD _wAttr)
	{
		CHAR_INFO *pBuf = TGE::g_chiBuffer;

		for (int i = 0; i < SCREEN_BUF_SIZE; i++)
		{
			pBuf[i].Char.UnicodeChar = _wCode;  //9643;
			pBuf[i].Attributes = _wAttr;  //0x009f;
		}
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

	int doTokenize(char *szBuf, char szBufToken[8][16])
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
}