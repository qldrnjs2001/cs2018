﻿#pragma once

namespace cs2018prj
{
	struct S_GAMEOBJECT
	{
		double m_dbSpeed;
		irr::core::vector2df m_vPos;
		double m_dbAngle;
		double m_dbWorkTick;
		void *m_pWeapon;
		tge_sprite::S_SPRITE_OBJECT *m_pSprite;
		irr::core::vector2df m_translation;
		int m_nFSM;
		int m_rnd;
		bool m_bActive;
		void *m_pTarget;
		void(*m_fpApply)(S_GAMEOBJECT *, double);
		void(*m_fpRender)(S_GAMEOBJECT *, CHAR_INFO *);
		void(*m_fpClone)(S_GAMEOBJECT *pObj);
	};

	namespace playerObject
	{
		struct S_SUBOBJECT
		{

		};

		void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
		void Activate(S_GAMEOBJECT *pObj);
	}

	namespace enemyObject
	{
		struct S_SUBOBJECT
		{

		};

		void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Activate(S_GAMEOBJECT *pObj);
		void createRandomInt(S_GAMEOBJECT *pObj);

	}

	namespace attackObject
	{
		namespace beam
		{
			struct S_SUBOBJECT
			{
			};

			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
			void Activate(S_GAMEOBJECT *pObj);
		}

		namespace fire
		{
			void Init(S_GAMEOBJECT *pObj, irr::core::vector2df _pos, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
			void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
			void Activate(S_GAMEOBJECT *pObj);
		}
	}

	namespace objMng
	{
		struct S_OBJECT_MNG
		{
			S_GAMEOBJECT *m_pListObject[1024];
			int m_nIndex;

		};

		void add(S_OBJECT_MNG *pObj, S_GAMEOBJECT *pGameObj);
		void applyAll(S_OBJECT_MNG *pObj, double _deltaTick);
		void renderAll(S_OBJECT_MNG *pObj, CHAR_INFO *pBuf);
		void clearAll(S_OBJECT_MNG *pObj);
	}
}