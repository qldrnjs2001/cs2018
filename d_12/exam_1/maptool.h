#pragma once

void initMapTool();
int parseCmd(char *szCmdBuf);

extern COORD g_cdCurrentCursorPos;
extern COORD _oldPos;

extern WCHAR g_wCurrentBrushCode;
extern WORD g_wCurrentBrushAttr;