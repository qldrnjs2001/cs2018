#include "stdafx.h"
#include "maptool.h"
#include "../../engine/tge.h"
#include "../../engine/tge_sprite.h"
using namespace TGE;


tge_sprite::S_SPRITE_OBJECT g_WorkSprObject;

void initMapTool(S_TGE_MAPTOOL *pObj)
{
	pObj->m_cdCurrentCursorPos.X = 40;
	pObj->m_cdCurrentCursorPos.Y = 12;

	pObj->m_wCurrentBrushCode = 0x20;
	pObj->m_wCurrentBrushAttr = 0x00e0;

	Init(&g_WorkSprObject);
}

int parseCmd(S_TGE_MAPTOOL *pObj, char *szCmdBuf)
{
	static char szTokenBuf[8][MAX_TOKEN_SIZE];

	doTokenize(szCmdBuf, szTokenBuf);

	if (!strcmp(szTokenBuf[0], "quit"))
	{
		return 0;
	}
	else if (!strcmp(szTokenBuf[0], "set"))
	{
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);
		WCHAR _code = strtol(szTokenBuf[3], NULL, 16);
		WORD _attr = strtol(szTokenBuf[4], NULL, 16);

		setCharacter(g_chiBuffer, _xpos, _ypos, _code, _attr);
	}
	else if (!strcmp(szTokenBuf[0], "moveCursor") || !strcmp(szTokenBuf[0], "moveCursorEnd"))
	{
		static COORD _oldPos = { -1, -1 };
		static WCHAR _oldCode = -1;
		static WORD _oldAttr = -1;

		if (!strcmp(szTokenBuf[0], "moveCursorEnd"))
		{
			_oldPos.X = -1;
		}
		else
		{
			if (_oldPos.X >= 0)  // �ʹ� ó��
			{
				setCharacter(g_chiBuffer, _oldPos.X, _oldPos.Y, _oldCode, _oldAttr);
			}

			_oldPos.X = pObj->m_cdCurrentCursorPos.X;
			_oldPos.Y = pObj->m_cdCurrentCursorPos.Y;  // ������ ����
			CHAR_INFO *oldInfo = getCharacter(g_chiBuffer, _oldPos.X, _oldPos.Y);
			_oldCode = oldInfo->Char.UnicodeChar;
			_oldAttr = oldInfo->Attributes;

			pObj->m_cdCurrentCursorPos.X = atoi(szTokenBuf[1]);
			pObj->m_cdCurrentCursorPos.Y = atoi(szTokenBuf[2]);
			WCHAR _code = (WCHAR)strtol(szTokenBuf[3], NULL, 16);
			WORD _attr = (WORD)strtol(szTokenBuf[4], NULL, 16);

			setCharacter(g_chiBuffer, pObj->m_cdCurrentCursorPos.X, pObj->m_cdCurrentCursorPos.Y, _code, _attr);
		}
	}
	else if (!strcmp(szTokenBuf[0], "clear"))
	{
		clearScreenBuffer(0x20, 0x0007);
	}
	else if (!strcmp(szTokenBuf[0], "changeBrush"))
	{
		WCHAR _code = (WCHAR)strtol(szTokenBuf[1], NULL, 16);
		WORD _attr = (WORD)strtol(szTokenBuf[2], NULL, 16);

		pObj->m_wCurrentBrushCode = _code;
		pObj->m_wCurrentBrushAttr = _attr;
	}
	else if (!strcmp(szTokenBuf[0], "saveB"))
	{
		saveBinary(g_chiBuffer, szTokenBuf[1]);
	}
	else if (!strcmp(szTokenBuf[0], "loadB"))
	{
		loadBinary(g_chiBuffer, szTokenBuf[1]);
	}
	else if (!strcmp(szTokenBuf[0], "getSprite"))
	{
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);
		int _width = atoi(szTokenBuf[3]);
		int _height = atoi(szTokenBuf[4]);

		get(&g_WorkSprObject, _xpos, _ypos, _width, _height);
	}
	else if (!strcmp(szTokenBuf[0], "putSprite"))
	{
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);

		put(&g_WorkSprObject, _xpos, _ypos);
	}
	else if (!strcmp(szTokenBuf[0], "saveSprite"))
	{
		tge_sprite::save(&g_WorkSprObject, szTokenBuf[1]);
	}
	else if (!strcmp(szTokenBuf[0], "loadSprite"))
	{
		tge_sprite::load(&g_WorkSprObject, szTokenBuf[1]);
	}

	return 1;
}