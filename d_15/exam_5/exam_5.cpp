// exam_5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <Windows.h>


int main()
{
	UINT64 start_tick = GetTimeMs64();

	Sleep(500);

	UINT64 end_tick = GetTimeMs64();

	printf_s("%d", end_tick - start_tick);

    return 0;
}

