#include "CHexagon.h"
#include <iostream>
#include <string>
#include "../DEFS.h"

using namespace std;

CHexagon::CHexagon(Point _P1, Point _P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = ++HexID;
	P1 = _P1;
	P2 = _P2;
	P2.x = (P1.x + P2.x) * 0.5; 
	radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2)) *0.5;
}
CHexagon::CHexagon() {}; //default constructor

int CHexagon::HexID = 0;

void CHexagon::Save(ofstream& OutFile) {
	OutFile << "CHexagon\t"
		<< this->ID << "\t"
		<< this->P1.x << "\t"
		<< this->P1.y << "\t"
		<< this->P2.x << "\t"
		<< this->P2.y << "\t"

		<< this->ColorString(this->FigGfxInfo.DrawClr) << "\t";

	if (this->FigGfxInfo.isFilled)
		OutFile << this->ColorString(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NO_FILL\n";
}
void CHexagon::Load(ifstream& Infile) {
	string s;
	Infile >> ID
		>> P1.x
		>> P1.y
		>> P2.x
		>> P2.y;

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

	P2.x = (P1.x + P2.x) * 0.5;
	radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2)) * 0.5;
}

void CHexagon::DrawMe(GUI* pGUI) const
{
	pGUI->DrawHexagon(P1, P2, FigGfxInfo, Selected);
}

bool CHexagon::Resize(float factor, GUI* pGUI) {

	HexagonStruct hexagon;
	hexagon.P1 = P1;
	hexagon.P2.x = ((P2.x - P1.x) * factor) + P1.x;
	hexagon.P2.y = P2.y;
	hexagon.radius = radius*factor; 
	hexagon.fitInBoundary = false;

	Point points[6];
	pGUI->getHexagonPoints(hexagon.P1, hexagon.P2, points);
	if (pGUI->allPointsInDrawingArea(points, 6))
	{
		P1 = hexagon.P1;
		P2 = hexagon.P2;
		radius = hexagon.radius;
		return true;
	}
	else {
		pGUI->PrintMessage("can't draw outside drawing area! plz enter suitable points!");
		return false;
	}
}

bool CHexagon::PointInShape(int x, int y) const {
	int length = sqrt(pow(P1.x - x, 2) + pow(P1.y - y, 2)); 
	return length <= radius*2; 
}
