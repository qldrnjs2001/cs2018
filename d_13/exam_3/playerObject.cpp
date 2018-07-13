#include "stdafx.h"
#include "playerObject.h"
#include "../../engine/tge.h"

namespace playerobject
{
	void Init(S_PlayerObject *pObj, int _sx, int _sy)
	{
		pObj->m_nKeyCount = 0;

		pObj->m_Position.X = _sx;
		pObj->m_Position.Y = _sy;

	}

	void move(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy)
	{
		int _check_x = pObj->m_Position.X + _dx;
		int _check_y = pObj->m_Position.Y + _dy;

		CHAR_INFO *pCi = TGE::getCharacter(pMapBuf, _check_x, _check_y);

		if (pCi->Attributes == 0x0007)
		{
			pObj->m_Position.X += _dx;
			pObj->m_Position.Y += _dy;
		}
	}

	int get(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy)
	{
		int _check_x = pObj->m_Position.X + _dx;
		int _check_y = pObj->m_Position.Y + _dy;

		CHAR_INFO *pCi = TGE::getCharacter(pMapBuf, _check_x, _check_y);

		if (pCi->Attributes == 0x0090)
		{
			pObj->m_nKeyCount++;
			TGE::setCharacter(pMapBuf, _check_x, _check_y, 0x20, 0x0007);
			return 1;
		}
		return 0;
	}

	int use(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy)
	{
		int _check_x = pObj->m_Position.X + _dx;
		int _check_y = pObj->m_Position.Y + _dy;

		CHAR_INFO *pCi = TGE::getCharacter(pMapBuf, _check_x, _check_y);

		int nRt = pCi->Attributes;

		if (pCi->Attributes == 0x00c0 || pCi->Attributes == 0x00a0) // door
		{
			pObj->m_nKeyCount--;
			TGE::setCharacter(pMapBuf, _check_x, _check_y, 0x20, 0x0007);
		}

		return nRt;
	}

	void DrawObject(S_PlayerObject *pObj, CHAR_INFO *pMapBuf)
	{
		TGE::setCharacter(pMapBuf, pObj->m_Position.X, pObj->m_Position.Y, 0x41, 0x0007);
	}
}
