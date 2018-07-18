#include "stdafx.h"

namespace exam_4
{
	void OnGdiPlusSetup()
	{

	}
	double fAngle = 0;
	void OnGdiPlusApply(double fDelta)
	{
		fAngle += fDelta * 45;
	}
	void OnGdiPlusRender(double fDelta, Graphics *pGrp)
	{
		pGrp->Clear(Color(200, 200, 200));
		Pen penBlack(Color(0, 0, 0));
		Pen penRed(Color(255, 0, 0));

		pGrp->DrawLine(&penBlack, 160, 0, 160, 240);
		pGrp->DrawLine(&penBlack, 0, 120, 320, 120);

		Matrix _mat1(1, 0, 0, 1, 160, 120);
		pGrp->SetTransform(&_mat1);

		{
			/*
			Matrix _mat2;
			_mat2.Rotate(45);

			_mat1.Multiply(&_mat2);  // _mat2 *= _mat1;

			pGrp->SetTransform(&_mat1);
			*/
			Matrix _tmpMat;
			pGrp->GetTransform(&_tmpMat);

			//pGrp->RotateTransform(fAngle);
			//pGrp->TranslateTransform(-32, -32);
			Matrix _trMat, _rtMat;
			_trMat.Translate(-32, -32);
			_rtMat.Rotate(45);
			
			_mat1.Multiply(&_rtMat);
			_mat1.Multiply(&_trMat);

			pGrp->SetTransform(&_mat1);

			irr::core::vector2df rectPos(0, 0);

			pGrp->DrawRectangle(&penBlack, irr::core::round32(rectPos.X), irr::core::round32(rectPos.Y), 64, 64);
			plusEngine::printf(pGrp, rectPos.X, rectPos.Y, L"(%.2lf, %.2lf)", rectPos.X, rectPos.Y);

			pGrp->SetTransform(&_tmpMat);
		}

		{
			irr::core::vector2df rectPos(0, 0);

			pGrp->DrawRectangle(&penRed, irr::core::round32(rectPos.X), irr::core::round32(rectPos.Y), 64, 64);
			plusEngine::printf(pGrp, rectPos.X, rectPos.Y, L"(%.2lf, %.2lf)", rectPos.X, rectPos.Y);
		}

		pGrp->SetTransform(&Matrix(1, 0, 0, 1, 0, 0)); // reset 과 같음 단위행렬을 곱해주는것
													   //pGrp->ResetTransform();
	}
	void OnGdiPlusFinish()
	{

	}
}