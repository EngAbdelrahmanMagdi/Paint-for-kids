#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point P1, P2 ;
	int radius;
	
	
public:
	CHexagon(Point _P1, Point _P2, GfxInfo FigureGfxInfo);

	
	virtual void DrawMe(GUI* pOut) const;
	virtual bool PointInShape(int x, int y) const ;

};

#endif