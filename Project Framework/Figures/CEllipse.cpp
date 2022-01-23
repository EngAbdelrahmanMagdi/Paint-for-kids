#include "CEllipse.h"
#include <iostream>
#include <fstream>

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

bool CEllipse::Resize(float factor, GUI* pGUI) {
	int centerOfX = (bottomRight.x + topLeft.x) / 2;
	int centerOfY = (bottomRight.y + topLeft.y) / 2;
	int HorizontalSpace = bottomRight.x - topLeft.x;
	int VerticalSpace = bottomRight.y - topLeft.y;
	HorizontalSpace *= factor;
	VerticalSpace *= factor;
	int resizedBottomRightX = centerOfX + (HorizontalSpace / 2);
	int resizedBottomRightY = centerOfY + (VerticalSpace / 2); 
	int resizedTopLeftX = centerOfX - (HorizontalSpace / 2); 
	int resizedTopLeftY = centerOfY - (VerticalSpace / 2);

	

	if (resizedTopLeftX > 0 && resizedTopLeftX < UI.width && resizedTopLeftY > UI.ToolBarHeight && resizedTopLeftY < UI.height - UI.StatusBarHeight
		&& resizedBottomRightX > 0 && resizedBottomRightX < UI.width && resizedBottomRightY > UI.ToolBarHeight && resizedBottomRightY < UI.height - UI.StatusBarHeight) {
		
		topLeft.x = resizedTopLeftX;
		topLeft.y = resizedTopLeftY;
		bottomRight.x = resizedBottomRightX;
		bottomRight.y = resizedBottomRightY;
		return true;
	}
	return false; 

}

bool CEllipse::PointInShape(int x, int y) const {
	return (x >= topLeft.x && x <= bottomRight.x)
		&& (y >= topLeft.y && y <= bottomRight.y);
}