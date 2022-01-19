#include "CEllipse.h"

CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{

	topLeft = P1;
	bottomRight = P2;


	//int x1 = P1.x;
	//int y1 = P1.y;
	//int x2 = P2.x;
	//int y2 = P2.y;
}


void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawEllipse(topLeft, bottomRight, FigGfxInfo, Selected);

}
bool CEllipse::PointInShape(int x, int y) const {
	return (x >= topLeft.x && x <= bottomRight.x)
		&& (y >= topLeft.y && y <= bottomRight.y);
}