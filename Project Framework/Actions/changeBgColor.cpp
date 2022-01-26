#include "changeBgColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

changeBgColor::changeBgColor(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void changeBgColor::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	Point P1;
	int ClickedItemOrder;
	pGUI->ClearToolBarArea();
	pGUI->CreateColorToolBar();
	pGUI->PrintMessage("Choose a background color");
	pGUI->GetPointClicked(P1.x, P1.y);
	if (P1.y >= 0 && P1.y < UI.ToolBarHeight)
	{
		
		ClickedItemOrder = (P1.x / UI.MenuItemWidth);

		switch (ClickedItemOrder)
		{
		case ITM_BLACK:		pGUI->setBgColor(BLACK);	break;
		case ITM_WHITE:		pGUI->setBgColor(WHITE);	break;
		case ITM_RED:		pGUI->setBgColor(RED);		break;
		case ITM_GREEN:		pGUI->setBgColor(GREEN);	break;
		case ITM_BLUE:		pGUI->setBgColor(BLUE);		break;
		case ITM_PINK:		pGUI->setBgColor(PINK);		break;
		case ITM_PURPLE:	pGUI->setBgColor(PURPLE);	break;
		}
	}
	pGUI->CreateDrawToolBar();
}
