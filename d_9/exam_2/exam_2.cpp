// exam_2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


struct profile
{
	int age;
	int height;
	const char *np;
};

struct student
{
	profile pf;
	int num;
	double grade;
};
int main()
{
	student s1;

	s1.pf.np = "안철수";
	s1.pf.age = 55;
	s1.pf.height = 170;
	s1.num = 50;
	s1.grade = 9.0;

	profile pf2 = { 23, 187, "안희정"};
	printf_s("%8d %8d %s\n", pf2.age, pf2.height, pf2.np);

	student s2 = { { 23, 187, "안희정" },
		50, 9.0
	};

	printf_s("%8d %8d\n", s2.num, s2.pf.height);

    return 0;
}

