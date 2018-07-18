#include "stdafx.h"

namespace exam_2
{
	void OnGdiPlusSetup()
	{

	}
	void OnGdiPlusApply(double fDelta)
	{

	}
	void OnGdiPlusRender(double fDelta, Graphics *pGrp)
	{
		pGrp->Clear(Color(200, 200, 200));
		Pen penBlack(Color(0, 0, 0));

		pGrp->DrawLine(&penBlack, 160, 0, 160, 240);
		pGrp->DrawLine(&penBlack, 0, 120, 320, 120);

		/*
		1 0   1 2
		0 1   3 4
		*/
		// 행렬의 합 교환 법칙 성립

		/*
		1 0   1
		0 1   2   or   1 2
		*/
		// 행렬과 벡터의 곱 가능

		/*
		1 0  160     x       x + 160
		0 1  120  *  y   =   y + 120
		1 1   1      1
		*/
		// 행렬을 이용해서 좌표 변환

		//pGrp->TranslateTransform(160, 120);

		Gdiplus::Matrix _mat1(1, 0, 0, -1, 160, 120);
		pGrp->SetTransform(&_mat1);

		irr::core::vector2df rectPos(0, 32);

		pGrp->DrawRectangle(&penBlack, irr::core::round32(rectPos.X), irr::core::round32(rectPos.Y), 64, 64);
		plusEngine::printf(pGrp, rectPos.X, rectPos.Y, L"(%.2lf, %.2lf)", rectPos.X, rectPos.Y);

		pGrp->ResetTransform();
	}
	void OnGdiPlusFinish()
	{

	}
}