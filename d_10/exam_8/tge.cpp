#include "stdafx.h"

//80x25
#define SCREEN_BUF_SIZE 2000
#define SCREEN_WIDTH 80

CHAR_INFO g_chiBuffer[SCREEN_BUF_SIZE];

void setCusor(HANDLE handle, int x, int y)
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

void clearScreenBuffer(CHAR_INFO *pBuf)
{
	for (int i = 0; i < SCREEN_BUF_SIZE; i++)
	{
		pBuf[i].Char.UnicodeChar = 9643;
		pBuf[i].Attributes = 0x009f;
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

void drawBox(CHAR_INFO *pBuf, int _posx, int _posy, int _width, int _height)
{
	int x, y;

	for (y = 0; y < _height; y++)
	{
		for (x = 0; x < _width; x++)
		{
			setCharacter(pBuf, _posx + x, _posy + y, 0x20, 0x000f);
		}
	}
}

void drawTriangle(CHAR_INFO *pBuf, int _posx, int _posy, int _height)
{
	int x, y;

	for (y = 0; y < _height; y++)
	{
		for (x = 0; x < y; x++)
		{
			setCharacter(pBuf, _posx + x, _posy + y, 0x20, 0x000f);
		}
	}
}