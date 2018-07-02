// exam_8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char str1[80] = "dream1";  // 80byte
	char str2[] = "dream2";  // 7byte
	const char *str3 = "dream3";  // 7byte
	char *str4;

	printf_s("%s\n", str1);
	printf_s("%s\n", str2);
	printf_s("%s\n", str3);

	str3 = str2;

	printf_s("%s\n", str3);

	//str3[0] = 'D';  // error str3는 포인터이기때문에.. 배열 형식의 대입 안됨
	str4 = (char *)str3;  // 이 방법으로 type casting 후 변환
	str4[0] = 'D';
	printf_s("%s\n", str3);

	str2[0] = 'D';

	printf_s("%s\n", str2);

	//str2 = str1;  // error 문자열 포인터에만 주소값 대입 가능

	str4 = (char *)str3;

    return 0;
}

