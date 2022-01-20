#include "ActionSendFront.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionBringFront::ActionBringFront(ApplicationManager* pApp) :Action(pApp)
{

}

void ActionBringFront::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	int selectedIndex = pManager->getSelectedFigure();
	if (selectedIndex != -1) {
		pManager->BringToFront(selectedIndex);
		pGUI->ClearDrawArea();
	}
	else {
		pGUI->PrintMessage("Select a shape before you can perform this action");
	}
}