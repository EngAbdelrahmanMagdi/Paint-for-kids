#include "changeCrntDrawColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


changeCrntDrawColor::changeCrntDrawColor(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void changeCrntDrawColor::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	Point P1;
	int ClickedItemOrder;
	pGUI->ClearToolBarArea();
	pGUI->CreateColorToolBar();
	//Get the coordinates of the user click
	pGUI->PrintMessage("Choose a drawing color");
	pGUI->GetPointClicked(P1.x, P1.y);
	if (P1.y >= 0 && P1.y < UI.ToolBarHeight)
	{
		//Check whick Menu item was clicked
		//==> This assumes that menu items are lined up horizontally <==
		ClickedItemOrder = (P1.x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		{
		case ITM_BLACK: pGUI->setCrntDrawColor(BLACK);	pGUI->PrintMessage("Black");	break;
		case ITM_WHITE:	pGUI->setCrntDrawColor(WHITE);	pGUI->PrintMessage("White");	break;
		case ITM_RED:	pGUI->setCrntDrawColor(RED);	pGUI->PrintMessage("Red");		break;
		case ITM_GREEN:	pGUI->setCrntDrawColor(GREEN);	pGUI->PrintMessage("Green");	break;
		case ITM_BLUE:	pGUI->setCrntDrawColor(BLUE);	pGUI->PrintMessage("Blue");		break;
		case ITM_PINK:	pGUI->setCrntDrawColor(PINK);	pGUI->PrintMessage("Pink");		break;
		case ITM_PURPLE:pGUI->setCrntDrawColor(PURPLE);	pGUI->PrintMessage("Purple");	break;
		};
	}
	pGUI->CreateDrawToolBar();
}
