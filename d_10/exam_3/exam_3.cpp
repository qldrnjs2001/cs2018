// exam_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	const double pi = 3.14;
	// pi = 3.141592; error - const 값 상수화 변경 불가

	int num = 0;
	const int *pNumReadOnly = NULL;
	//int const *pNum = &num;
	num = 5;

	pNumReadOnly = &num;  // 주소값은 대입이 된다. 주소값을 쓰지 못하는게 아니다

	printf_s("%.2lf %d\n", pi, *pNumReadOnly);

	//*pNumReadOnly = 7;
	//*pNum = 8;
	num = 7;
	printf_s("%d\n", num);

    return 0;
}

