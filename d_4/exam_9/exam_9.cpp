// exam_9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[32];
	scanf_s("%s", word, sizeof(word));
	printf_s("입력한 문자열은 : %s\n", word);
    return 0;
}

