#pragma once

namespace playerobject
{
	struct S_PlayerObject
	{
		int m_nKeyCount;
		COORD m_Position;
	};

	void Init(S_PlayerObject *pObj, int _sx, int _sy);

	void move(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy);

	int get(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy);

	int use(S_PlayerObject *pObj, CHAR_INFO *pMapBuf, int _dx, int _dy);

	void DrawObject(S_PlayerObject *pObj, CHAR_INFO *pMapBuf);


}
