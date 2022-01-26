#include "changeFigDrawColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


changeFigDrawColor::changeFigDrawColor(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void changeFigDrawColor::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	CFigure* selectedFig;
	selectedFig = pManager->getSelected();

	Point P1;
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
			case ITM_BLACK: selectedFig->ChngDrawClr(BLACK);	pGUI->PrintMessage("Black");	break;
			case ITM_WHITE:	selectedFig->ChngDrawClr(WHITE);	pGUI->PrintMessage("White");	break;
			case ITM_RED:	selectedFig->ChngDrawClr(RED);	pGUI->PrintMessage("Red");		break;
			case ITM_GREEN:	selectedFig->ChngDrawClr(GREEN);	pGUI->PrintMessage("Green");	break;
			case ITM_BLUE:	selectedFig->ChngDrawClr(BLUE);	pGUI->PrintMessage("Blue");		break;
			case ITM_PINK:	selectedFig->ChngDrawClr(PINK);	pGUI->PrintMessage("Pink");		break;
			case ITM_PURPLE:selectedFig->ChngDrawClr(PURPLE);	pGUI->PrintMessage("Purple");	break;
			};
		}
		pGUI->CreateDrawToolBar();
	}
}
