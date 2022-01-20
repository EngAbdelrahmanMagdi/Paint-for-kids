#include "ToPlayAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"

ActionToPlay::ActionToPlay(ApplicationManager* pApp) :Action(pApp)
{

}

void ActionToPlay::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->CreatePlayToolBar();
	pGUI->PrintMessage("Switched to Play Mode! Let's Play!");
}