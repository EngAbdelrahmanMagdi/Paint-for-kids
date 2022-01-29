#include "CFigure.h"

CFigure::CFigure()
{
	Selected = false;
	PlayHidden = false;
}


CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	PlayHidden = false;
	if (UI.filled_OR_not) {

		FigGfxInfo.isFilled = true;

	}
	else {
		FigGfxInfo.isFilled = false;

	}
	
}


void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}

string CFigure::ColorString(color ClrObj) const  //Convert from Color Type to String Type
{
	if (ClrObj == BLACK) return "BLACK";
	else if (ClrObj == WHITE) return "WHITE";
	else if (ClrObj == RED) return "RED";
	else if (ClrObj == GREEN) return "GREEN";
	else if (ClrObj == BLUE) return "BLUE";
	else if (ClrObj == PINK) return "PINK";
	else if (ClrObj == PURPLE) return "PRUPLE";
	else return "BLUE";
}

color CFigure::ColorObject(string ClrStr) const  //Convert from string to color object
{
	if (ClrStr == "BLACK") return BLACK;
	else if (ClrStr == "WHITE") return WHITE;
	else if (ClrStr == "RED") return RED;
	else if (ClrStr == "GREEN") return GREEN;
	else if (ClrStr == "BLUE") return BLUE;
	else if (ClrStr == "PINK") return PINK;
	else if (ClrStr == "PURPLE") return PURPLE;
	return BLUE;
}
//Hides Figures
void CFigure::Hide()
{
	PlayHidden = true;
}
//Shows Figures
void CFigure::Show()
{
	PlayHidden = false;
}
//Gives Current Status
bool CFigure::HiddenStatus()
{
	return PlayHidden;
}
GfxInfo CFigure::GetGfxInfo() const
{
	return FigGfxInfo;
}
