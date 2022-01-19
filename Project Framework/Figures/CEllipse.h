#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point topLeft;
	Point bottomRight;
public:
	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	//CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual bool PointInShape(int x, int y) const;
};

#endif