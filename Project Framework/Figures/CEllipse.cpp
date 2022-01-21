#include "CEllipse.h"

CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = ++ElpsID;
	topLeft = P1;
	bottomRight = P2;

}
CEllipse::CEllipse() {}; //default constructor


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
void CEllipse::Load(ifstream& Infile) {
	string s;
	Infile >> ID 
		>> topLeft.x 
		>> topLeft.y 
		>> bottomRight.x 
		>> bottomRight.y;

	Infile >> s;
	FigGfxInfo.DrawClr = this->ColorObject(s);

	Infile >> s;
	if (s == "NO_FILL")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.FillClr = this->ColorObject(s);
		FigGfxInfo.isFilled = true;
	}
	this->FigGfxInfo.BorderWdth = 3; //pass 3 as a default value for borderWidth
	this->SetSelected(false);
};

bool CEllipse::PointInShape(int x, int y) const {
	return (x >= topLeft.x && x <= bottomRight.x)
		&& (y >= topLeft.y && y <= bottomRight.y);
}