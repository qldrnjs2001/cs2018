// exam_12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[32];

	scanf_s("%s", word, sizeof(word));

	for (int i = 0; i < sizeof(word) / sizeof(char); i++)
	{
		if (word[i] == NULL)
			break;
		if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122))
			word[i] = '*';
	}

	printf("%s", word);

    return 0;
}

