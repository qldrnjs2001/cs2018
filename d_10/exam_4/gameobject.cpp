#include "stdafx.h"

struct _S_GAMEOBJECT
{
	char m_szName[16];
	int m_nHp;
};

double g_dbPi = 3.14;

void CreateObject(_S_GAMEOBJECT **ppObj, const char *pName, int nHp)
{
	*ppObj = (_S_GAMEOBJECT *)malloc(sizeof(_S_GAMEOBJECT));
	(*ppObj)->m_nHp = nHp;

	strcpy_s((*ppObj)->m_szName, sizeof((*ppObj)->m_szName), pName);
}

void dumpObject(_S_GAMEOBJECT *pObj)
{
	printf_s("%16s %4d\n", pObj->m_szName, pObj->m_nHp);
}