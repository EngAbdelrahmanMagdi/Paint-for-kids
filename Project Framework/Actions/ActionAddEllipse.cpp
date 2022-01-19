#include "ActionAddEllipse.h"
#include "../Figures/CEllipse.h"
#include "..\Figures\CSquare.h"
#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"


ActionAddEllipse::ActionAddEllipse(ApplicationManager* pApp) :Action(pApp)
{}




//Execute the action
void ActionAddEllipse::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo ElpsGfxInfo;
	ElpsGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	ElpsGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	ElpsGfxInfo.FillClr = pGUI->getCrntFillColor();
	ElpsGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Square data from the user

	pGUI->PrintMessage("New Ellipse: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Ellipse: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare square data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the square


	//Step 3 - Create a Square with the parameters read from the user
	CEllipse* R = new CEllipse(P1, P2, ElpsGfxInfo);

	//Step 4 - Add the Square to the list of figures
	pManager->AddFigure(R);
}
