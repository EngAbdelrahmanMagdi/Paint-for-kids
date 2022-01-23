#include "CSquare.h"


CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = ++sqrID;
	TopLeftCorner = P1;
	length = len;
}
CSquare::CSquare() {}; //default constructor

int CSquare::sqrID = 0;

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
}

void CSquare::Save(ofstream& OutFile) {

		OutFile << "CSquare\t"
		<< this->ID << "\t" 
		<< this->TopLeftCorner.x << "\t" 
		<< this->TopLeftCorner.y << "\t"
		<< this->length << "\t"

		<< this->ColorString(this->FigGfxInfo.DrawClr) << "\t";

	if (this->FigGfxInfo.isFilled)
		OutFile << this->ColorString(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NO_FILL\n";
}

void CSquare::Load(ifstream& Infile) {

	string s;
	Infile >> ID >> TopLeftCorner.x >> TopLeftCorner.y >> length;

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
	this->FigGfxInfo.BorderWdth = 3; //pass 3 as default value for borderWidth
	this->SetSelected(false);

}

bool CSquare::Resize(float factor, GUI* pGUI) {
	int centerOfX = TopLeftCorner.x + (length / 2);
	int centerOfY = (TopLeftCorner.y + (length / 2));
	
	int resizedLength = length * factor;
	int resizedTopLeftX = centerOfX - (resizedLength/2);
	int resizedTopLeftY = centerOfY - (resizedLength / 2);
	int resizedBottomRightX = resizedLength + resizedTopLeftX;
	int resizedBottomRightY = resizedLength + resizedTopLeftY;
	//x > 0 && x < UI.width
		//&& y > UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight;


	if (resizedTopLeftX > 0 && resizedTopLeftX < UI.width
		&& resizedTopLeftY > UI.ToolBarHeight && resizedTopLeftY < UI.height - UI.StatusBarHeight
		&& resizedBottomRightX > 0 && resizedBottomRightX < UI.width
		&& resizedBottomRightY > UI.ToolBarHeight && resizedBottomRightY < UI.height - UI.StatusBarHeight) {
		length = resizedLength;
		TopLeftCorner.x = resizedTopLeftX;
		TopLeftCorner.y = resizedTopLeftY;
		
		return true;
	}
	return false;

}

bool CSquare::PointInShape(int x, int y) const {
	return (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length)
		&& (y >= TopLeftCorner.y && y <= TopLeftCorner.y + length);
}