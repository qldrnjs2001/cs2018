// exam_6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int useElec;
	double fTotal, fTax, fLastTotal;
	
	printf("전기 사용량을 입력하세요(kw) : ");
	scanf_s("%d", &useElec);

	fTotal = (useElec * 88.5) + 660;

	fTax = fTotal * 0.09;

	fLastTotal = fTotal + fTax;

	printf("전기 사용 요금은 %lf원입니다.\n", fLastTotal);

    return 0;
}

