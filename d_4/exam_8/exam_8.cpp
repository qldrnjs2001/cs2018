// exam_8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	//char word[] = { 'l', 'o', 'v', 'e', '\x00' };
	char word[] = "love";

	int word_size = sizeof(word) / sizeof(char);

	for (int i = 0; i < word_size; i++)
	{
		printf_s("%c", word[i]);
	}
	printf_s("\n");

	printf_s("%s\n", word);

    return 0;
}

