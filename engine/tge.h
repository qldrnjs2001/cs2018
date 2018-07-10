#pragma once

namespace TGE
{
	void setCursor(HANDLE handle, int x, int y);
	void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr);
	void clearScreenBuffer(WCHAR _wCode, WORD _wAttr);
	void updateBuffer(HANDLE handle, CHAR_INFO *pBuf);
	CHAR_INFO *getCharacter(CHAR_INFO *pBuf, int x, int y);

	// function
	void drawBox(int _posx, int _posy, int _width, int _height, WCHAR code, WORD attr);
	void drawTriangle(int _posx, int _posy, int _height, WCHAR code, WORD attr);
	void drawLineH(int _x, int _y, int nLength, WCHAR code, WORD attr);
	void drawLineV(int _x, int _y, int nLength, WCHAR code, WORD attr);
	void drawLineC(int _x1, int _y1, int _x2, int _y2, WCHAR code, WORD attr);

	// utility
	int doTokenize(char *szBuf, char szBufToken[8][16]);

	//file processing
	int loadBinary(CHAR_INFO *pBuf, const char *szFileName);
	int saveBinary(CHAR_INFO *pBuf, const char *szFileName);

	extern CHAR_INFO g_chiBuffer[];
}
