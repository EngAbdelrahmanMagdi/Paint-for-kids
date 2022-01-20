#include "CHexagon.h"

CHexagon::CHexagon(Point _P1, Point _P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	ID = ++HexID;
	P1 = _P1;
	P2 = _P2;
	P2.x = (P1.x + P2.x) * 0.5; 
	radius = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2)) *0.5;
}

int CHexagon::HexID = 0;

void CHexagon::Save(ofstream& OutFile) {


	OutFile << "CHexagon\t"
		<< this->ID << "\t"
		<< "XS" << "\t"
		<< "YS" << "\t"
		<< 6 << "\t"

		<< this->ColorString(this->FigGfxInfo.DrawClr) << "\t";

	if (this->FigGfxInfo.isFilled)
		OutFile << this->ColorString(this->FigGfxInfo.FillClr) << "\n";
	else
		OutFile << "NO_FILL\n";
}

void CHexagon::DrawMe(GUI* pGUI) const
{
	pGUI->DrawHexagon(P1, P2, FigGfxInfo, Selected);
}

bool CHexagon::PointInShape(int x, int y) const {
	int length = sqrt(pow(P1.x - x, 2) + pow(P1.y - y, 2)); 
	return length <= radius; 
}