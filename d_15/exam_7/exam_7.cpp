// exam_7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/irrlicht/include/irrlicht.h"
#include "../../engine/tge.h"

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);



	TGE::endTGE();

    return 0;
}

