/*#include "ActionExit.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Actions\ActionSave.h"

ActionExit::ActionExit(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action

void ActionExit::Execute()
{

	GUI* pGUI = pManager->GetGUI();

	pGUI->PrintMessage("Are you sure? if you want to save your grapth write Y");
	string answer = pGUI->GetSrting();
	if (answer == "Y" || answer == "y")
	{
		Action* act = new ActionSave(this* &);
		pManager->ExecuteAction(act);
	}
	else
	{
		pGUI->PrintMessage("See you soon!");
	
		exit(0);
	}


	
}
*/