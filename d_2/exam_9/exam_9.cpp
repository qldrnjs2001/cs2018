// exam_9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int pi = (int)3.14; // 형 변환 type casting - 강제적으로 형을 변환 (int)double형데이터 -> int형 데이터로 변환

	double _pi = (int)3.14; // 형 변환 후 int형 3이 대입되서 3.000000의 double형 데이터가 된다.

	printf("%lf %lf", 3.14, _pi);

    return 0;
}

