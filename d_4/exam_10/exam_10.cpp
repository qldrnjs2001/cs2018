// exam_10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[32];

	int i = 0;

	scanf_s("%s", word, sizeof(word));

	while (1)
	{
		if (word[i] == NULL)  // 0x00, \x00 = NULL
			break;

		i++;
	}

	printf_s("%d", 'Z');
	printf_s("%s단어의 길이는 %d입니다.\n", word, i);
	//97 122 65 90
    return 0;
}

