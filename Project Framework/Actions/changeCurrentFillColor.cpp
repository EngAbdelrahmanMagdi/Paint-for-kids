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
		case ITM_BLACK:
			pGUI->setCrntFillColor(BLACK);
			break;
		case ITM_WHITE:
			pGUI->setCrntFillColor(WHITE);

			break;
		case ITM_RED:
			pGUI->setCrntFillColor(RED);

			break;
		case ITM_GREEN:
			pGUI->setCrntFillColor(GREEN);

			break;
		case ITM_BLUE:
			pGUI->setCrntFillColor(BLUE);

			break;
		case ITM_PINK:
			pGUI->setCrntFillColor(PINK);

			break;
		case ITM_PURPLE:
			pGUI->setCrntFillColor(PURPLE);

			break;

		}


	}
	pGUI->CreateDrawToolBar();
	pGUI->ClearStatusBar();

}
