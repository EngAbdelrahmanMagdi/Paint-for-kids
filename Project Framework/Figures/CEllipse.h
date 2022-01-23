#ifndef CELLIPSE_H
#define CELLIPSE_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point topLeft;
	Point bottomRight;
public:
	static int ElpsID;
	CEllipse(Point, Point, GfxInfo FigureGfxInfo);
	CEllipse();
	//CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	void Save(ofstream& OutFile);
	void Load(ifstream&);
	virtual bool PointInShape(int x, int y) const;
	bool Resize(float factor, GUI* pGUI);
};

#endif