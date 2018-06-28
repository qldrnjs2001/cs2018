// exam_13.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void _switch(char a, char b)
{
	char tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	char word[32];
	char tmp;
	int index = 0;

	scanf_s("%s", word, sizeof(word));
	
	for (int i = 0; i < sizeof(word) / sizeof(char); i++)
	{
		if (word[i] == NULL)
		{
			index = i - 1;
			break;
		}
	}

	for (int j = index; j >= 0; j--)
	{
		printf("%c", word[j]);
	}

	printf("\n");

	for (int k = 0; k < index/2; k++)
	{
		tmp = word[k];
		word[k] = word[index - k];
		word[index - k] = tmp;
		//_switch(word[k], word[index - k]);
	}

	printf("%s", word);

    return 0;
}
