// exam_1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/tge.h"
#include "../../engine/tge_sprite.h"
#include "gameobject.h"


int main()
{

	HANDLE hStdout = NULL;
	TGE::startTGE(&hStdout);

	CHAR_INFO *pBackBuffer = TGE::CreateScreenBuffer();
	CHAR_INFO *pMapDataBuffer = TGE::CreateScreenBuffer();

	//resource loading
	TGE::loadBinary(pMapDataBuffer, "../../pub_res/lv1.map");

	tge_sprite::S_SPRITE_OBJECT sprMainInWhite;
	tge_sprite::Init(&sprMainInWhite);
	tge_sprite::load(&sprMainInWhite, "../../pub_res/miw.spr");

	tge_sprite::S_SPRITE_OBJECT sprAilen;
	tge_sprite::Init(&sprAilen);
	tge_sprite::load(&sprAilen, "../../pub_res/alien.spr");

	tge_sprite::S_SPRITE_OBJECT sprClaw;
	tge_sprite::Init(&sprClaw);
	tge_sprite::load(&sprClaw, "../../pub_res/cross.spr");

	tge_sprite::S_SPRITE_OBJECT sprFlame;
	tge_sprite::Init(&sprFlame);
	tge_sprite::load(&sprFlame, "../../pub_res/flameBurster.spr");

	//create game object
	cs2018prj::playerObject::S_GAMEOBJECT playerObj;
	cs2018prj::attackObject_claw::S_GAMEOBJECT ailenClaw;
	cs2018prj::ailenObject::S_GAMEOBJECT ailenObj;
	cs2018prj::attackObject_flameBurster::S_GAMEOBJECT fireObj;

	cs2018prj::playerObject::Init(&playerObj, 10, 10, 5, &sprMainInWhite);
	playerObj.m_translation = irr::core::vector2df(-1, -3);
	playerObj.m_pWeapon = &fireObj;

	cs2018prj::attackObject_claw::Init(&ailenClaw, 50, 8, 5, &sprClaw);
	ailenClaw.m_translation = irr::core::vector2df(-1, -2);
	ailenClaw.m_pTargetObj = &playerObj;

	cs2018prj::ailenObject::Init(&ailenObj, 50, 8, 5, &sprAilen);
	ailenObj.m_translation = irr::core::vector2df(-1, -3);
	ailenObj.m_pTargetObj = &playerObj;
	ailenObj.m_pWeapon = &ailenClaw;

	cs2018prj::attackObject_flameBurster::Init(&fireObj, 0, 0, 10, &sprFlame);
	fireObj.m_translation = irr::core::vector2df(-1, -1);
	fireObj.m_pTargetObj = &ailenObj;

	bool _bLoop = true;
	static int _nFSM = 0;
	UINT64 _oldTick = TGE::util::GetTimeMs64();

	while (_bLoop)
	{
		UINT64 _curTick = TGE::util::GetTimeMs64();
		UINT64 _deltaTick = _curTick - _oldTick;
		_oldTick = _curTick;

		double _dbDeltaTick = (double)(_deltaTick) / 1000.0;

		//SetConsoleCursorPosition(hStdout,{ 40, 1 });

		static char szCmdBuf[128];
		//입력 처리 
		switch (_nFSM)
		{
		case 0:
			if (TGE::input::g_KeyTable[VK_RETURN])
			{
				_nFSM = 1;
				TGE::input::setEditMode();
			}
			break;
		case 1: //동기  모드
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, 26);
			printf_s("                                                 ]");
			TGE::setCursor(hStdout, 0, 26);
			printf_s("[cmd >");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			_nFSM = 0;
			TGE::input::setNormalMode();
			TGE::input::g_KeyTable[VK_RETURN] = 0;
			_oldTick = TGE::util::GetTimeMs64();

			break;
		}
		//커멘드 처리..
		{
			char szTokenBuf[8][64];
			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0)
			{
				if (!strcmp(szTokenBuf[0], "quit"))
				{
					_bLoop = false;
				}
				else if (!strcmp(szTokenBuf[0], "claw"))
				{
					ailenClaw.m_nFSM = 10;  // wake up
					ailenClaw.m_posx = atoi(szTokenBuf[1]);
					ailenClaw.m_posy = atoi(szTokenBuf[2]);
				}
				else if (!strcmp(szTokenBuf[0], "fire"))
				{
					fireObj.m_nFSM = 10;  // wake up
					fireObj.m_posx = playerObj.m_posx;
					fireObj.m_posy = playerObj.m_posy - 2;
					fireObj.m_pTargetObj = &ailenObj;
				}
			}
			szCmdBuf[0] = 0x00;
		}

		//ai
		cs2018prj::playerObject::Apply(&playerObj, _dbDeltaTick);
		cs2018prj::ailenObject::Apply(&ailenObj, _dbDeltaTick);
		cs2018prj::attackObject_claw::Apply(&ailenClaw, _dbDeltaTick);
		cs2018prj::attackObject_flameBurster::Apply(&fireObj, _dbDeltaTick);

		//랜더링 전처리
		TGE::copyScreenBuffer(pBackBuffer, pMapDataBuffer);
		cs2018prj::playerObject::Render(&playerObj, pBackBuffer);
		cs2018prj::ailenObject::Render(&ailenObj, pBackBuffer);
		cs2018prj::attackObject_claw::Render(&ailenClaw, pBackBuffer);
		cs2018prj::attackObject_flameBurster::Render(&fireObj, pBackBuffer);

		//랜더 (화면 갱신)
		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuffer);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	free(pBackBuffer);
	free(pMapDataBuffer);

	tge_sprite::Release(&sprMainInWhite);
	tge_sprite::Release(&sprAilen);
	tge_sprite::Release(&sprClaw);
	tge_sprite::Release(&sprFlame);
	
	/*
	free(sprAilen.m_pSpriteBuf);
	free(sprMainInWhite.m_pSpriteBuf);
	free(sprClaw.m_pSpriteBuf);
	*/

	TGE::endTGE();

	return 0;

}