#include "CEllipse.h"

CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = ++ElpsID;
	topLeft = P1;
	bottomRight = P2;


	//int x1 = P1.x;
	//int y1 = P1.y;
	//int x2 = P2.x;
	//int y2 = P2.y;
}

int CEllipse::ElpsID = 0;

void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawEllipse(topLeft, bottomRight, FigGfxInfo, Selected);

}

void CEllipse::Save(ofstream& OutFile) {

	OutFile << "CEllipse\t" << this->ID << "\t"
		<< this->topLeft.x << "\t" 
		<< this->topLeft.y << "\t"
		<< this->bottomRight.x << "\t"
		<< this->bottomRight.y << "\t"

		<< this->ColorString(this->FigGfxInfo.DrawClr) << "\t";

	if (this->FigGfxInfo.isFilled)
		OutFile << this->ColorString(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NO_FILL\n";
}

bool CEllipse::PointInShape(int x, int y) const {
	return (x >= topLeft.x && x <= bottomRight.x)
		&& (y >= topLeft.y && y <= bottomRight.y);
}