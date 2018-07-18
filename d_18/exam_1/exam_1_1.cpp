#include "stdafx.h"

namespace exam_1
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
	}
	void OnGdiPlusFinish()
	{

	}
}