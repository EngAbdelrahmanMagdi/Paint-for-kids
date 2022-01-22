#include "changeCurrentFillColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


changeCurrentFillColor::changeCurrentFillColor(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void changeCurrentFillColor::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	Point P1;
	int ClickedItemOrder;
	pGUI->ClearToolBarArea();

	pGUI->CreateColorToolBar();
	//Get the coordinates of the user click

	pGUI->PrintMessage("Choose a filling color");
	pGUI->GetPointClicked(P1.x, P1.y);
	if (P1.y >= 0 && P1.y < UI.ToolBarHeight)
	{

		//Check whick Menu item was clicked
		//==> This assumes that menu items are lined up horizontally <==
		ClickedItemOrder = (P1.x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_BLACK: pGUI->setCrntFillColor(BLACK);	pGUI->PrintMessage("Black");	break;
		case ITM_WHITE:	pGUI->setCrntFillColor(WHITE);	pGUI->PrintMessage("White");	break;
		case ITM_RED:	pGUI->setCrntFillColor(RED);	pGUI->PrintMessage("Red");		break;
		case ITM_GREEN:	pGUI->setCrntFillColor(GREEN);	pGUI->PrintMessage("Green");	break;
		case ITM_BLUE:	pGUI->setCrntFillColor(BLUE);	pGUI->PrintMessage("Blue");		break;
		case ITM_PINK:	pGUI->setCrntFillColor(PINK);	pGUI->PrintMessage("Pink");		break;
		case ITM_PURPLE:pGUI->setCrntFillColor(PURPLE);	pGUI->PrintMessage("Purple");	break;
		};
	}
	pGUI->CreateDrawToolBar();
}
