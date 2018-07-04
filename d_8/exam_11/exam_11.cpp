// exam_11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

// calloc - 0 으로 초기화
// realloc - 기억 공간 재할당(malloc 해제하고 재할당 받는게 낫다)

int main()
{
	//move n, move s, move 1, 3 - tokenizing - 구분자
	char strMsg[] = "move east and move north 3,4";
	char *pTmp;
	const char *pszDelimitor = " ,";

	char *pToken = strtok_s((char *)strMsg, pszDelimitor, &pTmp);

	while (pToken)
	{
		pToken = strtok_s(NULL, pszDelimitor, &pTmp);
		if (pToken == NULL)
			break;
		printf_s("%s\n", pToken);
	}

    return 0;
}

