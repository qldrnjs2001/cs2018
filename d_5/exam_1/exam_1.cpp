// exam_1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
//d_4 복습 

/*  */  //사이의 문자 공백 표시

#include "stdafx.h"


int main()
{
	char word[32];

	bool meet = false;

	scanf_s("%s", word, sizeof(word));

	for (int i = 0; i < sizeof(word) / sizeof(char); i++)
	{
		if (meet == false) {
			if (word[i] == '*' && word[i - 1] == '/')
				meet = true;
		}
		else if (meet == true) {
			if (word[i] == '*' && word[i + 1] == '/')
				meet = false;
			if (meet == true)
				word[i] = ' ';
		}
	}

	printf_s("%s", word);

    return 0;
}

