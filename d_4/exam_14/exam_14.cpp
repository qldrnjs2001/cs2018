// exam_14.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[32];

	bool meet = false;

	scanf_s("%s", word, sizeof(word));

	int i = 0;

	for (i = 0; i < sizeof(word) / sizeof(char); i++)
	{
		if (meet == false) {
			if (word[i] == '@')
				meet = true;
		}
		else if (meet == true) {
			if (word[i] == '@')
				meet = false;
			if(meet == true)
				word[i] = '*';
		}
	}

	printf_s("%s", word);

    return 0;
}

