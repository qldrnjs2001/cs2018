// exam_3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

struct score
{
	const char *pName;
	int kor, eng, mat;
};

int main()
{
	score a;
	score *sp = &a;

	printf_s("%8d %8d \n", sizeof(a), sizeof(sp));

	//(*sp).pName = "안철수";
	sp->pName = "안희정";
	sp->kor = 20;
	sp->eng = 30;
	sp->mat = 50;

	printf_s("%s\n", sp->pName);

    return 0;
}

