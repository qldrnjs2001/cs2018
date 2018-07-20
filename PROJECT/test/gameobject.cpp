#include "stdafx.h"
#include "../../engine/irrlicht/include/irrlicht.h"
#include "../../engine/tge_sprite.h"
#include "../../engine/tge.h"
#include "gameObject.h"

namespace cs2018prj
{
	void _Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr)
	{
		pObj->m_vPos = _pos;
		pObj->m_dbSpeed = _dbspeed;
		pObj->m_dbAngle = 0;
		pObj->m_dbWorkTick = 0;
		pObj->m_nFSM = 0;
		pObj->m_pSprite = pSpr;
		pObj->m_bActive = false;
		pObj->m_pTarget = NULL;
		pObj->m_pWeapon = NULL;
	}

	namespace playerObject
	{
		void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr)
		{
			_Init(pObj, _pos, _dbspeed, pSpr);
			pObj->m_fpApply = cs2018prj::playerObject::Apply;
			pObj->m_fpRender = cs2018prj::playerObject::Render;
		}

		void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
		{
			switch (pObj->m_nFSM)
			{
			case 0:
				break;
			case 1:
				pObj->m_bActive = true;
				pObj->m_nFSM = 10;
			case 10:
				pObj->m_nFSM++;
				break;
			case 11:  // stop
				if (TGE::input::g_KeyTable[VK_SPACE])
				{
					pObj->m_nFSM = 20;
				}
				{
					if (TGE::input::g_KeyTable[VK_UP])
					{
						pObj->m_vPos.Y -= pObj->m_dbSpeed * _deltaTick;
					}
					if (TGE::input::g_KeyTable[VK_DOWN])
					{
						pObj->m_vPos.Y += pObj->m_dbSpeed * _deltaTick;
					}
					if (TGE::input::g_KeyTable[VK_LEFT])
					{
						pObj->m_vPos.X -= pObj->m_dbSpeed * _deltaTick;
					}
					if (TGE::input::g_KeyTable[VK_RIGHT])
					{
						pObj->m_vPos.X += pObj->m_dbSpeed * _deltaTick;
					}
					if (TGE::input::g_KeyTable['F'])
					{
						if (pObj->m_pWeapon)
						{
							S_GAMEOBJECT *pWeapon = (S_GAMEOBJECT *)pObj->m_pWeapon;

							if (pWeapon->m_nFSM == 0)  // only sleep mode..
							{

								pWeapon->m_nFSM = 10;
								pWeapon->m_vPos.X = pObj->m_vPos.X;
								pWeapon->m_vPos.Y = pObj->m_vPos.Y;
								/*
								pWeapon = (S_GAMEOBJECT *)malloc(sizeof(S_GAMEOBJECT));
								attackObject::fire::Init(pWeapon, irr::core::vector2df(pObj->m_vPos.X, pObj->m_vPos.Y), 7, pWeapon->m_pSprite);
								pWeapon->m_translation = irr::core::vector2df(-1, -1);
								attackObject::fire::Activate(pWeapon);
								*/
								//cs2018prj::objMng::add(&objMng, pFireObj);
							}
						}
					}
				}
				break;
			case 20:  // move
			{
				irr::core::vector2df vTarget = irr::core::vector2df(TGE::input::g_cdMousePos.X, TGE::input::g_cdMousePos.Y);
				irr::core::vector2df vDir = vTarget - pObj->m_vPos;
				if (vDir.getLength() < 1)
				{
					pObj->m_nFSM = 0;  // change stop..
				}
				else
				{
					vDir.normalize();
					pObj->m_vPos += irr::core::vector2df(vDir.X * _deltaTick * pObj->m_dbSpeed, vDir.Y * _deltaTick * pObj->m_dbSpeed);
				}
			}
			break;
			case 100:  // player died
				pObj->m_bActive = false;
				pObj->m_nFSM = 101;
				break;
			case 101:
				break;
			default:
				break;
			}
		}

		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf)
		{
			if (pObj->m_bActive)
			{
				tge_sprite::put(pObj->m_pSprite, irr::core::round32(pObj->m_vPos.X + pObj->m_translation.X), irr::core::round32(pObj->m_vPos.Y + pObj->m_translation.Y), pTargetBuf);
			}
		}

		void Activate(S_GAMEOBJECT *pObj)
		{
			pObj->m_nFSM = 1;
		}
	}

	namespace enemyObject
	{
		void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr)
		{
			_Init(pObj, _pos, _dbspeed, pSpr);
			pObj->m_fpApply = cs2018prj::enemyObject::Apply;
			pObj->m_fpRender = cs2018prj::playerObject::Render;
		}

		void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
		{
			pObj->m_dbWorkTick += _deltaTick;

			switch (pObj->m_nFSM)
			{
			case 0:  // 

				break;
			case 10:  // waiting
			{
				pObj->m_bActive = true;
				pObj->m_nFSM++;
				pObj->m_dbWorkTick = 0;
			}
			break;
			case 11:  // searching
			{
				irr::core::vector2df _vdir(1, 0);
				_vdir *= pObj->m_dbSpeed;
				_vdir *= _deltaTick;
				_vdir.rotateBy(pObj->m_dbAngle);
				pObj->m_vPos += _vdir;
				if (pObj->m_dbWorkTick > 2)
				{
					pObj->m_dbAngle += 180;
					pObj->m_dbWorkTick = 0;
				}
				if (TGE::input::g_KeyTable['D'])
				{
					if (pObj->m_pWeapon)
					{
						S_GAMEOBJECT *pWeapon = (S_GAMEOBJECT *)pObj->m_pWeapon;

						if (pWeapon->m_nFSM == 0)  // only sleep mode..
						{
							pWeapon->m_nFSM = 10;
							pWeapon->m_vPos.X = pObj->m_vPos.X;
							pWeapon->m_vPos.Y = pObj->m_vPos.Y;
						}
					}
				}
			}
			break;
			case 20:  // chasing
				break;
			case 100:
				pObj->m_bActive = false;
				pObj->m_nFSM = 0;
				break;
			default:
				break;
			}
		}

		void Activate(S_GAMEOBJECT *pObj)
		{
			pObj->m_nFSM = 10;
		}
	}

	namespace attackObject
	{
		namespace beam
		{
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr)
			{
				_Init(pObj, _pos, _dbspeed, pSpr);
				pObj->m_fpApply = cs2018prj::attackObject::beam::Apply;
				pObj->m_fpRender = cs2018prj::playerObject::Render;
			}

			void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
			{
				pObj->m_dbWorkTick += _deltaTick;
				switch (pObj->m_nFSM)
				{
				case 0:
					break;
				case 10:
					pObj->m_bActive = true;
					pObj->m_nFSM++;
					pObj->m_dbWorkTick = 0;
					break;
				case 11:
				{
					if (pObj->m_dbWorkTick > 5)
					{
						pObj->m_nFSM = 100;
					}
					else
					{
						if (pObj->m_vPos.Y > 40)
							pObj->m_nFSM = 100;
						irr::core::vector2df _vdir(0, 1);
						_vdir *= pObj->m_dbSpeed;
						_vdir *= _deltaTick;
						pObj->m_vPos += _vdir;
						if (pObj->m_pTarget) {
							cs2018prj::S_GAMEOBJECT *pTarget = (cs2018prj::S_GAMEOBJECT *)pObj->m_pTarget;

							irr::core::vector2df a = irr::core::vector2df(pObj->m_vPos.X, pObj->m_vPos.Y);
							irr::core::vector2df b = irr::core::vector2df(pTarget->m_vPos.X, pTarget->m_vPos.Y);

							double fDist = a.getDistanceFrom(b);

							if (fDist < 3) {
								pObj->m_nFSM = 100;
								pTarget->m_nFSM = 100;
							}
							
						}
					}
				}
				break;
				case 100:
					pObj->m_bActive = false;
					pObj->m_nFSM = 0;
					break;
				default:
					break;
				}
			}

			void Activate(S_GAMEOBJECT *pObj)
			{
				pObj->m_nFSM = 10;
			}
		}

		namespace fire
		{
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr)
			{
				_Init(pObj, _pos, _dbspeed, pSpr);
				pObj->m_fpApply = cs2018prj::attackObject::fire::Apply;
				pObj->m_fpRender = cs2018prj::playerObject::Render;
			}

			void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
			{
				pObj->m_dbWorkTick += _deltaTick;
				switch (pObj->m_nFSM)
				{
				case 0:
					break;
				case 10:
					pObj->m_bActive = true;
					pObj->m_nFSM++;
					pObj->m_dbWorkTick = 0;
					break;
				case 11:
				{
					if (pObj->m_dbWorkTick > 5)
					{
						pObj->m_nFSM = 100;
					}
					else
					{
						if (pObj->m_vPos.Y < 5)
							pObj->m_nFSM = 100;
						irr::core::vector2df _vdir(0, -1);
						_vdir *= pObj->m_dbSpeed;
						_vdir *= _deltaTick;
						pObj->m_vPos += _vdir;
						if (pObj->m_pTarget) {
							cs2018prj::objMng::S_OBJECT_MNG *pTarget =
								(cs2018prj::objMng::S_OBJECT_MNG *)pObj->m_pTarget;

							irr::core::vector2df a = irr::core::vector2df(pObj->m_vPos.X, pObj->m_vPos.Y);
							for (int i = 0; i < pTarget->m_nIndex; i++)
							{
								irr::core::vector2df b = irr::core::vector2df(pTarget->m_pListObject[i]->m_vPos.X, pTarget->m_pListObject[i]->m_vPos.Y);

								double fDist = a.getDistanceFrom(b);
								if (fDist < 3) {
									pObj->m_nFSM = 100;
									pTarget->m_pListObject[i]->m_nFSM = 100;
								}
							}
						}
					}
				}
				break;
				case 100:
					pObj->m_bActive = false;
					pObj->m_nFSM = 0;
					break;
				default:
					break;
				}
			}

			void Activate(S_GAMEOBJECT *pObj)
			{
				pObj->m_nFSM = 10;
			}

		}
	}

	namespace objMng
	{
		void add(S_OBJECT_MNG *pObj, S_GAMEOBJECT *pGameObj)
		{
			pObj->m_pListObject[pObj->m_nIndex++] = pGameObj;
		}

		void applyAll(S_OBJECT_MNG *pObj, double _deltaTick)
		{
			for (int i = 0; i < pObj->m_nIndex; i++)
			{
				pObj->m_pListObject[i]->m_fpApply(pObj->m_pListObject[i], _deltaTick);
			}
		}

		void renderAll(S_OBJECT_MNG *pObj, CHAR_INFO *pBuf)
		{
			for (int i = 0; i < pObj->m_nIndex; i++)
			{
				pObj->m_pListObject[i]->m_fpRender(pObj->m_pListObject[i], pBuf);
			}
		}

		void clearAll(S_OBJECT_MNG *pObj)
		{
			for (int i = 0; i < pObj->m_nIndex; i++)
			{
				if (pObj->m_pListObject[i] != NULL)
				{
					free(pObj->m_pListObject[i]);
				}
			}
		}
	}
}