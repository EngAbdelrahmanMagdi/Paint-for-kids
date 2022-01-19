#include "Select.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

Select::Select(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void Select::Execute()
{
	Point P1;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	


	

	pGUI->PrintMessage("Click Select: Click to select a figure");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	

	pGUI->ClearStatusBar();


	
	CFigure* Selected = pManager->GetFigure(P1.x, P1.y);
	if (Selected != NULL) {
		Selected->SetSelected(!Selected->IsSelected());
	}
}
