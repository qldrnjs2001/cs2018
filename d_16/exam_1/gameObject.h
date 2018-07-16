#pragma once

namespace cs2018prj
{
	namespace playerObject
	{
		struct S_GAMEOBJECT
		{
			double m_dbSpeed;
			double m_posx, m_posy;
			void *m_pWeapon;
			tge_sprite::S_SPRITE_OBJECT *m_pSprite;
			irr::core::vector2df m_translation;  // 위치 기준으로 다시 이동
			int m_nFSM;
			bool m_bActive;
			
		};

		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
	}

	namespace ailenObject
	{
		struct S_GAMEOBJECT
		{
			double m_dbSpeed;
			double m_posx, m_posy;
			tge_sprite::S_SPRITE_OBJECT *m_pSprite;
			irr::core::vector2df m_vDir;
			irr::core::vector2df m_translation;  // 위치 기준으로 다시 이동
			double m_dbWorkTick;
			cs2018prj::playerObject::S_GAMEOBJECT *m_pTargetObj;
			void *m_pWeapon;
			int m_nFSM;
			bool m_bActive;
		};

		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
	}

	namespace attackObject_claw
	{
		struct S_GAMEOBJECT
		{
			double m_dbSpeed;
			double m_posx, m_posy;
			tge_sprite::S_SPRITE_OBJECT *m_pSprite;
			irr::core::vector2df m_vDir;
			irr::core::vector2df m_translation;  // 위치 기준으로 다시 이동
			double m_dbWorkTick;
			cs2018prj::playerObject::S_GAMEOBJECT *m_pTargetObj;
			int m_nFSM;
			bool m_bActive;
		};

		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
	}

	namespace attackObject_flameBurster
	{
		struct S_GAMEOBJECT
		{
			double m_dbSpeed;
			double m_posx, m_posy;
			tge_sprite::S_SPRITE_OBJECT *m_pSprite;
			irr::core::vector2df m_vDir;
			irr::core::vector2df m_translation;  // 위치 기준으로 다시 이동
			double m_dbWorkTick;
			void *m_pTargetObj;
			int m_nFSM;
			bool m_bActive;
		};

		void Init(S_GAMEOBJECT *pObj, double _x, double _y, double _dbspeed, tge_sprite::S_SPRITE_OBJECT *pSpr);
		void Apply(S_GAMEOBJECT *pObj, double _deltaTick);
		void Render(S_GAMEOBJECT *pObj, CHAR_INFO *pTargetBuf);
	}
}