#include "stdafx.h"

namespace exam_6
{
	irr::core::vector2df vPos1 = irr::core::vector2df(64, 64);
	irr::core::vector2df vPos2 = irr::core::vector2df(64, 64);

	void OnGdiPlusSetup()
	{
	}
	void OnKeyDown(WORD keycode)
	{
		switch (keycode)
		{
		case VK_LEFT:
			vPos2 += irr::core::vector2df(-1, 0);
			break;
		case VK_RIGHT:
			vPos2 += irr::core::vector2df(1, 0);
			break;
			break;
		case VK_UP:
			vPos2 += irr::core::vector2df(0, -1);
			break;
		case VK_DOWN:
			vPos2 += irr::core::vector2df(0, 1);
			break;
		default:
			break;
		}
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

		//원점 이동
		pGrp->TranslateTransform(160, 120);

		irr::core::line2df line1(irr::core::vector2df(-64, -64), irr::core::vector2df(64, 64));
		irr::core::line2df line2(irr::core::vector2df(64, -64), vPos2);

		pGrp->DrawLine(&penBlack, line1.start.X, line1.start.Y, line1.end.X, line1.end.Y);
		pGrp->DrawLine(&penBlack, line2.start.X, line2.start.Y, line2.end.X, line2.end.Y);

		irr::core::vector2df colPt;

		if (line1.intersectWith(line2, colPt))
		{
			Matrix _tmp;
			pGrp->GetTransform(&_tmp);
			pGrp->TranslateTransform(colPt.X, colPt.Y);
			pGrp->DrawEllipse(&penBlack, -4, -4, 8, 8);
			plusEngine::printf(pGrp, 0, 0, L"%lf, %lf", colPt.X, colPt.Y);
			pGrp->SetTransform(&_tmp);
		}

		pGrp->ResetTransform();
	}
	void OnGdiPlusFinish()
	{

	}
}