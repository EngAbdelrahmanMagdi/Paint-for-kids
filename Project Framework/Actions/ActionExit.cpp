#include "ActionExit.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionExit::ActionExit(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionExit::Execute()
{
	

	
	GUI* pGUI = pManager->GetGUI();


	
}
bool ActionExit:: willExit() {
	//when you need to save a graph return false like ...
	return false ; 
	//	if all graph saved return true... 
}