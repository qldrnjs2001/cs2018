// exam_11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

struct _S_GAMEOBJECT
{
	char m_szName[32];
	int m_nHp;
	int m_nMp;
	int m_nAttack;
	int m_nDefence;
};

void parsePlayerInfo(_S_GAMEOBJECT *pObj, char *szBuf)
{
	// edit 이름 100 50 6 3
	const char *delimitor = " ";
	char *_tmp;
	char *pToken;

	pToken = strtok_s(szBuf, delimitor, &_tmp);
	puts(pToken);
	pToken = strtok_s(NULL, delimitor, &_tmp);
	strcpy_s(pObj->m_szName, sizeof(pObj->m_szName), pToken);
	pToken = strtok_s(NULL, delimitor, &_tmp);
	pObj->m_nHp = atoi(pToken);  // 문자열을 숫자로 변형 대신 문자열이 숫자로 되어있어야한다.
	pToken = strtok_s(NULL, delimitor, &_tmp);
	pObj->m_nMp = atoi(pToken);
	pToken = strtok_s(NULL, delimitor, &_tmp);
	pObj->m_nAttack = atoi(pToken);
	pToken = strtok_s(NULL, delimitor, &_tmp);
	pObj->m_nDefence = atoi(pToken);
}

int main()
{
	char szBuf[128];
	_S_GAMEOBJECT player = { 0 };

	while (1)
	{
		printf_s("command > ");
		gets_s(szBuf, sizeof(szBuf));
		if (!strcmp("quit", szBuf))
		{
			printf_s("quit the game.\n");
			break;
		}
		else if (!strcmp("dump", szBuf))
		{
			printf_s("%12s%4d%4d%4d%4d\n", player.m_szName, player.m_nHp, player.m_nMp, player.m_nAttack, player.m_nDefence);
		}
		else if (!strncmp("edit", szBuf, 4))
		{
			parsePlayerInfo(&player, szBuf);
		}
		else if (!strncmp("save", szBuf, 4))
		{
			FILE *fp = NULL;
			fopen_s(&fp, "save.txt", "w");
			fprintf_s(fp, "edit %s %d %d %d %d\n", player.m_szName, player.m_nHp, player.m_nMp, player.m_nAttack, player.m_nDefence);
			fclose(fp);
		}
		else if (!strncmp("load", szBuf, 4))
		{
			FILE *fp = NULL;
			fopen_s(&fp, "save.txt", "r");

			fgets(szBuf, sizeof(szBuf), fp);
			parsePlayerInfo(&player, szBuf);

			fclose(fp);
		}
		else
		{
			printf_s("not exist command.\n");
		}
	}
    return 0;
}

