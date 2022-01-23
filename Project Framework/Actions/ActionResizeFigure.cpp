#include "ActionResizeFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


ActionResizeFigure::ActionResizeFigure(ApplicationManager* pApp, float factor): Action(pApp)
{
	factorOfResize = factor;
}

void ActionResizeFigure::Execute() {
	GUI* pGUI = pManager->GetGUI();
	CFigure* figure = pManager->getSelected();

	if (figure == NULL) {
		pGUI->PrintMessage("Select the shape you want to reisze");
		Point point; 
		pGUI->GetPointClicked(point.x, point.y);
		figure = pManager->GetFigure(point.x, point.y);
	}


	if (figure != NULL) {
		bool ableToResize = figure->Resize(factorOfResize, pGUI);
		if (ableToResize) {
			pManager->UpdateInterface();
			pGUI->PrintMessage("Shaped is resized");
		}
		else {
			pGUI->PrintMessage("We can't resize the shape outside boundaries");
		}
	}
}