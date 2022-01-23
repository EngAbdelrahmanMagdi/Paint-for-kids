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
	CSquare();
	CSquare(Point, int, GfxInfo);
	virtual void DrawMe(GUI*) const;
	void Save(ofstream&);
	void Load(ifstream&);
	virtual bool PointInShape(int,int) const;
	bool Resize(float factor, GUI* pGUI);
};

#endif