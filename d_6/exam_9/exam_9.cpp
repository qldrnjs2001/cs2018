// exam_9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char *fruit = (char *)"strawberry";  // exam_8의 대입 변환 다 가능하게 됨

	printf_s("%s\n", fruit);

	printf_s("%s\n", fruit + 2);

	printf_s("%s\n", &fruit[2]);

	//fruit[3] = 'o';  // error 액세스 위반

	char fruit2[] = "strawberry";
	fruit2[3] = 'o';

	printf_s("%s\n", fruit2);

    return 0;
}

