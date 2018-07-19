#include "stdafx.h"
// cjson read example

void exam1()
{
	char szBuf[1024] = { 0 };
	FILE *fp;
	fopen_s(&fp, "test.json", "rt");

	fread_s(szBuf, 1024, 1024, 1, fp);

	puts(szBuf);

	cJSON *pRoot = cJSON_Parse(szBuf);

	cJSON *pName = cJSON_GetObjectItemCaseSensitive(pRoot, "name");
	cJSON *pDistance = cJSON_GetObjectItemCaseSensitive(pRoot, "distance");
	cJSON *pNCode = cJSON_GetObjectItemCaseSensitive(pRoot, "national_code");
	cJSON *pComm = cJSON_GetObjectItemCaseSensitive(pRoot, "comm");

	cJSON *pItem = cJSON_GetObjectItemCaseSensitive(pRoot, "item");
	cJSON *pWeapon = cJSON_GetObjectItemCaseSensitive(pItem, "weapon");

	// array
	cJSON *pEtc = cJSON_GetObjectItemCaseSensitive(pRoot, "etc");
	cJSON *pEtc_0 = cJSON_GetArrayItem(pEtc, 0);
	cJSON *pEtc_1 = cJSON_GetArrayItem(pEtc, 1);

	// print parsing result
	printf_s("parsing result\n");
	printf_s("%s, %lf %d %d\n", pName->valuestring, pDistance->valuedouble, pNCode->valueint, pComm->valueint);

	printf_s("weapon is %s\n", pWeapon->valuestring);
	printf_s("attack point is %d\n", cJSON_GetObjectItemCaseSensitive(pItem, "ap")->valueint);

	printf_s("%d, %s\n", pEtc_0->valueint, pEtc_1->valuestring);

	fclose(fp);
}