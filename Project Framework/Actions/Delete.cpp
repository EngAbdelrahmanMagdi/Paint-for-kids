#include "Delete.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{

}

void Delete::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	if (pManager->getSelected() != NULL)

	{

		int figNumber = pManager->DeleteFigure();
		pManager->shiftFigList(figNumber);
		pGUI->ClearDrawArea();
		//pManager->UpdateInterface();
		pGUI->PrintMessage("Deleted Successfully");
	}
	else {
		pGUI->PrintMessage("Select a shape before you can perform this action");
	}
}