// exam_5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int bonbong, bonus, total;
	double tax, real_income;

	printf("본봉과 보너스를 입력하세요:");
	scanf_s("%d %d", &bonbong, &bonus);

	total = bonbong + bonus;

	tax = total * 0.09;

	real_income = total - tax;

	printf("총수입액은 %d원입니다.\n", total);
	printf("세금은 %.2lf원입니다.\n", tax);
	printf("실입금액은 %.2lf원입니다.\n", real_income);

    return 0;
}

