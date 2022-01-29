#include "changeFigFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


changeFigFillColor::changeFigFillColor(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void changeFigFillColor::Execute()
{
	Point P1;
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	CFigure* selectedFig;
	selectedFig = pManager->getSelected();

	
	int ClickedItemOrder;
	
	//Get the coordinates of the user click
	if (selectedFig == NULL) {
		pGUI->PrintMessage("Please select a figure first");
		

	}
	else {
		pGUI->ClearToolBarArea();

		pGUI->CreateColorToolBar();
		pGUI->PrintMessage("Choose a filling color");
		pGUI->GetPointClicked(P1.x, P1.y);
		if (P1.y >= 0 && P1.y < UI.ToolBarHeight)
		{

			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			ClickedItemOrder = (P1.x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_BLACK: selectedFig->ChngFillClr(BLACK);	pGUI->PrintMessage("Black");	break;
			case ITM_WHITE:	selectedFig->ChngFillClr(WHITE);	pGUI->PrintMessage("White");	break;
			case ITM_RED:	selectedFig->ChngFillClr(RED);	pGUI->PrintMessage("Red");		break;
			case ITM_GREEN:	selectedFig->ChngFillClr(GREEN);	pGUI->PrintMessage("Green");	break;
			case ITM_BLUE:	selectedFig->ChngFillClr(BLUE);	pGUI->PrintMessage("Blue");		break;
			case ITM_PINK:	selectedFig->ChngFillClr(PINK);	pGUI->PrintMessage("Pink");		break;
			case ITM_PURPLE:selectedFig->ChngFillClr(PURPLE);	pGUI->PrintMessage("Purple");	break;
			};
		}
		pGUI->CreateDrawToolBar();
	}
}
