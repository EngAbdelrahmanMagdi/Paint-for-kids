#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;
	int length;
public:
	static int sqrID;
	CSquare(Point, int, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	void Save(ofstream& OutFile);
	virtual bool PointInShape(int x, int y) const;
};

#endif