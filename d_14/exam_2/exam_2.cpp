// exam_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"
#include "../../engine/tge_sprite.h"

int x_upperBounder = 77;
int x_lowerBounder = 0;
int y_upperBounder = 22;
int y_lowerBounder = 3;

struct S_GAME_OBJECT
{
	COORD m_cdPosition;
	tge_sprite::S_SPRITE_OBJECT m_SpriteObject;
	int m_nFSM;
};

void Apply(S_GAME_OBJECT *pObj)
{
	//S_GAME_OBJECT *pObj = &crossObj;

	switch (pObj->m_nFSM)
	{
	case 0:
		pObj->m_nFSM = 10;
		break;
	case 10:
		if (pObj->m_cdPosition.X < x_upperBounder)
		{
			pObj->m_cdPosition.X += 1;
		}
		else
		{
			x_upperBounder -= 6;
			pObj->m_nFSM = 20;
		}
		break;
	case 20:
		if (pObj->m_cdPosition.Y < y_upperBounder)
		{
			pObj->m_cdPosition.Y += 1;
		}
		else
		{
			y_upperBounder -= 3;
			pObj->m_nFSM = 30;
		}
		break;
	case 30:
		if (pObj->m_cdPosition.X > x_lowerBounder)
		{
			pObj->m_cdPosition.X -= 1;
		}
		else
		{
			x_lowerBounder += 6;
			pObj->m_nFSM = 40;
		}
		break;
	case 40:
		if (pObj->m_cdPosition.Y > y_lowerBounder)
		{
			pObj->m_cdPosition.Y -= 1;
		}
		else
		{
			y_lowerBounder += 3;
			pObj->m_nFSM = 10;
		}
		break;
	default:
		break;
	}
}

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode;
	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	TGE::clearScreenBuffer(0x20, 0x0090);

	CHAR_INFO *pBackDataBuff = TGE::CreateScreenBuffer();
	TGE::loadBinary(pBackDataBuff, "../../pub_res/1.map");

	CHAR_INFO *pBackBuff = TGE::CreateScreenBuffer();

	S_GAME_OBJECT crossObj = {0};

	tge_sprite::load(&(crossObj.m_SpriteObject), "../../pub_res/cross.spr");

	bool _bLoop = true;
	static int _nFSM = 0;
	while (_bLoop)
	{
		static char szCmdBuf[128];

		//ai
		Sleep(10);

		Apply(&crossObj);
		
		memcpy_s(pBackBuff, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pBackDataBuff, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));

		tge_sprite::put(&(crossObj.m_SpriteObject), crossObj.m_cdPosition.X, crossObj.m_cdPosition.Y, pBackBuff);

		memcpy_s(TGE::g_chiBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pBackBuff, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));

		//랜더 (화면 갱신)
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	SetConsoleMode(hStdin, fdwOldMode);

	free(pBackBuff);

	return 0;
}