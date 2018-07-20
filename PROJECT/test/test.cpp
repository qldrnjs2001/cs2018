#include "stdafx.h"
#include "../../engine/tge.h"
#include "../../engine/tge_sprite.h"
#include "gameobject.h"

bool gameOver = false;

void _loadSprite(tge_sprite::S_SPRITE_OBJECT *spr, const char *szFileName)
{
	tge_sprite::Init(spr);
	tge_sprite::load(spr, szFileName);
}

int main()
{
	int checkEli = 0;

	HANDLE hStdout = NULL;
	TGE::startTGE(&hStdout);

	CHAR_INFO *pMapDataBuffer = TGE::CreateScreenBuffer();
	CHAR_INFO *pBackBuffer = TGE::CreateScreenBuffer();

	TGE::loadBinary(pMapDataBuffer, "../../pub_res/prj_res/space.map");

	tge_sprite::S_SPRITE_OBJECT sprShip, sprUFO, sprFire, sprBeam;

	_loadSprite(&sprShip, "../../pub_res/prj_res/spaceShip.spr");
	_loadSprite(&sprUFO, "../../pub_res/prj_res/ufo.spr");
	_loadSprite(&sprBeam, "../../pub_res/prj_res/beam.spr");
	_loadSprite(&sprFire, "../../pub_res/prj_res/missile.spr");

	cs2018prj::objMng::S_OBJECT_MNG objMng = { 0 };
	cs2018prj::objMng::S_OBJECT_MNG enemyMng = { 0 };
	cs2018prj::objMng::S_OBJECT_MNG beamMng = { 0 };

	cs2018prj::S_GAMEOBJECT *objPlayer, *objFire;
	cs2018prj::S_GAMEOBJECT *objEnemy[1024] = {};
	cs2018prj::S_GAMEOBJECT *objBeam[1024] = {};

	objPlayer = (cs2018prj::S_GAMEOBJECT *)malloc(sizeof(cs2018prj::S_GAMEOBJECT));

	cs2018prj::playerObject::Init(objPlayer, irr::core::vector2df(25, 30), 7, &sprShip);
	cs2018prj::playerObject::Activate(objPlayer);
	objPlayer->m_translation = irr::core::vector2df(-1, -3);

	for (int i = 0; i < 3; i++)
	{
		objEnemy[i] = (cs2018prj::S_GAMEOBJECT *)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
		cs2018prj::enemyObject::Init(objEnemy[i], irr::core::vector2df((SCREEN_WIDTH / 3 * i) + 3, 10), 3, &sprUFO);
		objEnemy[i]->m_translation = irr::core::vector2df(-1, -3);
		cs2018prj::enemyObject::Activate(objEnemy[i]);
		cs2018prj::objMng::add(&enemyMng, objEnemy[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		objBeam[i] = (cs2018prj::S_GAMEOBJECT *)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
		cs2018prj::attackObject::beam::Init(objBeam[i], irr::core::vector2df(objEnemy[i]->m_vPos.X, objEnemy[i]->m_vPos.Y), 10, &sprBeam);
		objBeam[i]->m_translation = irr::core::vector2df(2, 0);
		cs2018prj::objMng::add(&beamMng, objBeam[i]);
		objBeam[i]->m_pTarget = objPlayer;
		objEnemy[i]->m_pWeapon = objBeam[i];
	}

	objFire = (cs2018prj::S_GAMEOBJECT *)malloc(sizeof(cs2018prj::S_GAMEOBJECT));

	cs2018prj::attackObject::fire::Init(objFire, irr::core::vector2df(0, 0), 10, &sprFire);
	objFire->m_translation = irr::core::vector2df(1, -4);
	objFire->m_pTarget = &enemyMng;

	objPlayer->m_pWeapon = objFire;

	cs2018prj::objMng::add(&objMng, objPlayer);
	cs2018prj::objMng::add(&objMng, objFire);

	bool _bLoop = true;
	static int _nFSM = 0;
	UINT64 _oldTick = TGE::util::GetTimeMs64();

	while (_bLoop)
	{
		UINT64 _curTick = TGE::util::GetTimeMs64();
		UINT64 _deltaTick = _curTick - _oldTick;
		_oldTick = _curTick;

		double _dbDeltaTick = (double)(_deltaTick) / 1000.0;

		static char szCmdBuf[128];
		//입력 처리 
		switch (_nFSM) {
		case 0:
			if (TGE::input::g_KeyTable[VK_RETURN]) {
				_nFSM = 1;
				TGE::input::setEditMode();
			}
			break;
		case 1: //동기  모드
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, SCREEN_HEIGHT + 1);
			printf_s("                                                 ]");
			TGE::setCursor(hStdout, 0, SCREEN_HEIGHT + 1);
			printf_s("[cmd >");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			_nFSM = 0;
			TGE::input::setNormalMode();
			break;
		}
		//커멘드 처리..
		{
			char szTokenBuf[8][64];
			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0) {
				if (!strcmp(szTokenBuf[0], "quit")) {
					_bLoop = false;
				}
				else if (!strcmp(szTokenBuf[0], "fire")) {
					cs2018prj::S_GAMEOBJECT *pFireObj;
					pFireObj = (cs2018prj::S_GAMEOBJECT *)malloc(sizeof(cs2018prj::S_GAMEOBJECT));
					cs2018prj::attackObject::fire::Init(pFireObj, irr::core::vector2df(objPlayer->m_vPos.X, objPlayer->m_vPos.Y), 7, &sprFire);
					pFireObj->m_translation = irr::core::vector2df(-1, -1);
					cs2018prj::attackObject::fire::Activate(pFireObj);
					cs2018prj::objMng::add(&objMng, pFireObj);
				}
			}
			szCmdBuf[0] = 0x00;
		}

		//ai
		
		for (int i = 0; i < 3; i++)
		{
			cs2018prj::enemyObject::createRandomInt(objEnemy[i]);
		}
		
		cs2018prj::objMng::applyAll(&objMng, _dbDeltaTick);
		cs2018prj::objMng::applyAll(&enemyMng, _dbDeltaTick);
		cs2018prj::objMng::applyAll(&beamMng, _dbDeltaTick);

		

		//랜더링 전처리

		TGE::copyScreenBuffer(pBackBuffer, pMapDataBuffer);

		cs2018prj::objMng::renderAll(&objMng, pBackBuffer);
		cs2018prj::objMng::renderAll(&enemyMng, pBackBuffer);
		cs2018prj::objMng::renderAll(&beamMng, pBackBuffer);


		//랜더 (화면 갱신)
		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuffer);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

		//game over
		if (gameOver)
			break;

		//game win
		for (int i = 0; i < 3; i++)
		{
			if (enemyMng.m_pListObject[i]->m_bActive == false)
			{
				checkEli++;
			}
		}
		if (checkEli == 3)
		{
			break;
		}
		else
		{
			checkEli = 0;

		}
	}

	cs2018prj::objMng::clearAll(&objMng);
	cs2018prj::objMng::clearAll(&enemyMng);
	cs2018prj::objMng::clearAll(&beamMng);

	free(pBackBuffer);
	free(pMapDataBuffer);

	free(sprShip.m_pSpriteBuf);
	free(sprUFO.m_pSpriteBuf);
	free(sprFire.m_pSpriteBuf);
	free(sprBeam.m_pSpriteBuf);

	TGE::endTGE();

	return 0;

}