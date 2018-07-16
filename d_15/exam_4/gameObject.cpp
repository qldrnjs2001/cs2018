#include "stdafx.h"
#include "../../engine/irrlicht/include/irrlicht.h"
#include "../../engine/tge_sprite.h"
#include "../../engine/tge.h"
#include "gameObject.h"

namespace cs2018prj
{
	namespace playerObject
	{
		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _speed, tge_sprite::S_SPRITE_OBJECT *pSpr)
		{
			pObj->m_posx = _x;
			pObj->m_posy = _y;
			pObj->m_dbSpeed = _speed;
			pObj->m_nFSM = 0;
			pObj->m_pSprite = pSpr;
			//pObj->m_Spr = _spr;
		}

		void Apply(S_GAMEOBJECT *pObj, double _deltaTick)
		{
			if (TGE::input::g_KeyTable[VK_UP])
			{
				pObj->m_posy -= pObj->m_dbSpeed * _deltaTick;
			}
			if (TGE::input::g_KeyTable[VK_DOWN])
			{
				pObj->m_posy += pObj->m_dbSpeed * _deltaTick;
			}
			if (TGE::input::g_KeyTable[VK_LEFT])
			{
				pObj->m_posx -= pObj->m_dbSpeed * _deltaTick;
			}
			if (TGE::input::g_KeyTable[VK_RIGHT])
			{
				pObj->m_posx += pObj->m_dbSpeed * _deltaTick;
			}

			switch (pObj->m_nFSM)
			{
			case 0:  // stop
				if (TGE::input::g_KeyTable[VK_SPACE])
				{
					pObj->m_nFSM = 10;
				}
				break;
			case 10:  // move
			{
				irr::core::vector2df vTarget = irr::core::vector2df(TGE::input::g_cdMousePos.X, TGE::input::g_cdMousePos.Y);
				irr::core::vector2df vCurpos = irr::core::vector2df(pObj->m_posx, pObj->m_posy);
				irr::core::vector2df vDir = vTarget - vCurpos;
				if (vDir.getLength() < 1)
				{
					pObj->m_nFSM = 0;  // change stop..
				}
				else
				{
					vDir.normalize();
					pObj->m_posx += vDir.X * _deltaTick *pObj->m_dbSpeed;
					pObj->m_posy += vDir.Y * _deltaTick *pObj->m_dbSpeed;
				}

			}
			break;
			default:
				break;
			}
		}

		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf)
		{
			//TGE::setCharacter(pTargetBuf, pObj->m_posx, pObj->m_posy, pObj->m_Spr.Char.UnicodeChar, pObj->m_Spr.Attributes);
			tge_sprite::put(pObj->m_pSprite, irr::core::round32(pObj->m_posx), irr::core::round32(pObj->m_posy), pTargetBuf);
		}
	}
}