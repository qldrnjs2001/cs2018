// exam_4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

struct profile
{
	char name[20];
	double grade;
	int english;
};

void input_data(profile *pStaff)
{
	printf_s("이름, 학점, 영어점수를 입력하세요.\n");

	for (int i = 0; i < 5; i++)
	{
		scanf_s("%s %lf %d", pStaff[i].name, 20, &(pStaff[i].grade), &(pStaff[i].english));
	}
}

void elite(profile *pStaff)
{
	printf_s("\n");

	for (int i = 0; i < 5; i++)
	{
		if (pStaff[i].english >= 900 && pStaff[i].grade >= 4.0)
		{
			printf_s("%s, %.1lf, %d\n", pStaff[i].name, pStaff[i].grade, pStaff[i].english);
		}
	}
}

void english_elite(profile *pStaff)
{
	profile *pMax;
	pMax = &(pStaff[0]);

	for (int i = 0; i < 5; i++)
	{
		if (pMax->english < pStaff[i].english)
		{
			pMax = &(pStaff[i]);
		}
	}
	
	printf_s("영어점수이 가장 높은 사람은 %s입니다.\n", pMax->name);
}

void grade_elite(profile *pStaff)
{
	profile *pMax;
	pMax = &(pStaff[0]);

	for (int i = 0; i < 5; i++)
	{
		if (pMax->grade < pStaff[i].grade)
		{
			pMax = &(pStaff[i]);
		}
	}

	printf_s("학점이 가장 높은 사람은 %s입니다.\n", pMax->name);
}

int main()
{
	profile new_staff[5];

	input_data(new_staff);
	elite(new_staff);
	english_elite(new_staff);
	grade_elite(new_staff);

    return 0;
}

