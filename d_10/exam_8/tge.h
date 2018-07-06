#pragma once

void setCusor(HANDLE handle, int x, int y);
void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr);
void clearScreenBuffer(CHAR_INFO *pBuf);
void updateBuffer(HANDLE handle, CHAR_INFO *pBuf);
void drawBox(CHAR_INFO *pBuf, int _posx, int _posy, int _width, int _height);

extern CHAR_INFO g_chiBuffer[];