// exam_4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int num_1, num_2;

	printf("input -> ");
	scanf_s("%d %d", &num_1, &num_2); // 두 변수 사이 어떤 문자로 구분을 지을지 정할 수 있다.
	//scanf_s("%d,%d", &num_1, &num_2); (웬만하면 ' ' 공백 외에는 다른 문자 사용하지 말자)
	printf("result : %d, %d\n", num_1, num_2);

    return 0;
}

