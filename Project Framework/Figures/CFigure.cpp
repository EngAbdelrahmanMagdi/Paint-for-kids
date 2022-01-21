#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	if (UI.filled_OR_not) {

		FigGfxInfo.isFilled = true;

	}
	else {
		FigGfxInfo.isFilled = false;

	}
}
CFigure::CFigure() {};

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
	else if (ClrObj == BLUE) return "BLUE";
	else if (ClrObj == RED) return "RED";
	else if (ClrObj == YELLOW) return "YELLOW";
	else if (ClrObj == GREEN) return "GREEN";
	else if (ClrObj == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
	else if (ClrObj == MAGENTA) return "MAGENTA";
	else if (ClrObj == TURQUOISE) return "TURQUOISE";
	return "Blue";
}

color CFigure::ColorObject(string ClrStr) const  //Convert from string to color object
{
	if (ClrStr == "BLACK") return BLACK;
	else if (ClrStr == "WHITE") return WHITE;
	else if (ClrStr == "BLUE") return BLUE;
	else if (ClrStr == "RED") return RED;
	else if (ClrStr == "YELLOW") return YELLOW;
	else if (ClrStr == "GREEN") return GREEN;
	else if (ClrStr == "LIGHTGOLDENRODYELLOW") return LIGHTGOLDENRODYELLOW;
	else if (ClrStr == "MAGENTA") return MAGENTA;
	else if (ClrStr == "TURQUOISE") return TURQUOISE;
	return LIGHTGOLDENRODYELLOW;
}