#include "ApplicationManager.h"
#include "Actions\ActionAddSquare.h"
#include "Actions\ActionAddEllipse.h"
#include "Actions\ActionAddHexagon.h"
#include "Actions\ActionExit.h"
#include "Actions\ActionSave.h"
#include "Actions\Select.h"
#include "Actions\ActionSendBack.h"
#include "Actions\ActionSendFront.h"
#include "Actions\Delete.h"
#include "Actions\ToPlayAction.h"
#include "Actions\ToDrawAction.h"
#include "Actions\ActionLoad.h"
#include "GUI\GUI.h"
#include <string.h>
#include "Actions\changeCrntDrawColor.h"
#include "Actions\changeCurrentFillColor.h"
#include "Actions\changeBgColor.h"
#include "Actions\ActionResizeFigure.h"
#include "Actions\PickByType.h"
#include "Actions\PickByBoth.h"
#include "Actions\ActionPickByFill.h"
#include "Actions\changeFigFillColor.h"
#include "Actions\changeFigDrawColor.h"




//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pGUI = new GUI;

	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

void ApplicationManager::Run()
{
	ActionType ActType;
	do
	{
		//1- Read user action
		ActType = pGUI->MapInputToActionType();

		//2- Create the corresponding Action
		Action* pAct = CreateAction(ActType);

		//3- Execute the action
		ExecuteAction(pAct);

		//4- Update the interface
		UpdateInterface();

	} 
	while (true);
	//while (ActType != EXIT);

}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
//Creates an action
Action* ApplicationManager::CreateAction(ActionType ActType)
{
	
	Action* newAct = NULL;
	string answer, answer2;
	CFigure* aa = NULL;
	int selectedIndex = getSelectedFigure();
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_SQUARE:
		newAct = new ActionAddSquare(this);
		break;
	case DRAW_ELPS:
		newAct = new ActionAddEllipse(this);
		break;
  	case DRAW_HEX:
		newAct = new ActionAddHexagon(this);
		break;
	case CHNG_DRAW_CLR:
		newAct = new changeCrntDrawColor(this);
		break;
	case CHNG_FILL_CLR:
		newAct = new changeCurrentFillColor(this);
		break;
	case CHG_FIG_FILL_COLOR:
		newAct = new changeFigFillColor(this);
		break;
	case CHG_FIG_DRAW_COLOR:
		newAct = new changeFigDrawColor(this);
		break;
	case CHNG_BK_CLR:
		newAct = new changeBgColor(this);
		break;
	case SAVE:
		newAct = new ActionSave(this,FigCount,0);
		break;
	case SELECT:
		newAct = new Select(this);
		break;
	case DEL:
		newAct = new Delete(this);
		break;
	case SEND_BACK:	//Send a figure to the back of all figures
		newAct = new ActionSendBack(this);
		break;
	case BRNG_FRNT:
		newAct = new ActionBringFront(this);
		break;
	case TO_PLAY:
		newAct = new ActionToPlay(this);
	break;
	case TO_DRAW:
		newAct = new ActionToDraw(this);
		break;
	case QUARTERED_RESIZE:
		newAct = new ActionResizeFigure(this, 0.25);
		break;
	case HALFED_RESIZE:
		newAct = new ActionResizeFigure(this, 0.5);
		break;
	case DOUBLED_RESIZE:
		newAct = new ActionResizeFigure(this, 2);
		break;
	case QUADRUPLE_RESIZED:
		newAct = new ActionResizeFigure(this, 4);
		break;
	case LOAD:		
		newAct = new ActionLoad(this, FigCount);
		break;
		//Play Mode Actions//
	case P_H_TYPE:
		newAct = new PickByType(this);
		break;

	case P_H_FILL:
		newAct = new PickByFill(this);
		break;
	case P_H_BOTH:
		newAct = new PickByBoth(this);
		break;
	case EXIT:	
		DisplayMessageBox();	
		break;
	case STATUS:	
		return NULL;				
		break; //a click on the status bar ==> no action
		/*m
		* 
		* //this is the old implementation of the exit button
		pGUI->PrintMessage("Are you sure? if you want to save your grapth write y");
		answer = pGUI->GetSrting();
		if (answer == "Y" || answer == "y")
			newAct = new ActionSave(this, FigCount,true);
		else { pGUI->PrintMessage("See you soon!"); Sleep(1000); exit(0); }
		break;
		*/
	}
	return newAct;
}
//////////////////////////////////////////////////////////////////////
//Executes the created Action
void ApplicationManager::ExecuteAction(Action*& pAct)
{
	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i] != NULL) {
			if (FigList[i]->PointInShape(x, y)) {
				return FigList[i];
			}

		}

	}

	///Add your code here to search for a figure given a point x,y	

	return NULL;
}
//==================================================================================//
//							Save And load Functions									//
//==================================================================================//

//Convert from color object to string to save
string ApplicationManager::colorString(color ClrObj) const
{
	if (ClrObj == BLACK) return "BLACK";
	else if (ClrObj == WHITE) return "WHITE";
	else if (ClrObj == RED) return "RED";
	else if (ClrObj == GREEN) return "GREEN";
	else if (ClrObj == BLUE) return "BLUE";
	else if (ClrObj == PINK) return "PINK";
	else if (ClrObj == PURPLE) return "PRUPLE";
	else return "BLUE";
}
//Convert from string to color object to load
color ApplicationManager::ColorObject(string ClrStr) const
{
	if (ClrStr == "BLACK") return BLACK;
	else if (ClrStr == "WHITE") return WHITE;
	else if (ClrStr == "RED") return RED;
	else if (ClrStr == "GREEN") return GREEN;
	else if (ClrStr == "BLUE") return BLUE;
	else if (ClrStr == "PINK") return PINK;
	else if (ClrStr == "PURPLE") return PURPLE;
	return BLUE;
}

void ApplicationManager::SaveAll(ofstream& Out)   //Call the Save function for each Figure
{
	for (int i = 0; i < FigCount; ++i)
		FigList[i]->Save(Out);
}
//Transfer figures in FigList to playmode
CFigure* ApplicationManager::DrawnFigs(int i) const
{
	return FigList[i];
}
////////////////////////////////////////////////////////////////////////////////////
//Transfer FigCount to playmode to avoid unnessecary loops
int ApplicationManager::getFigCount() const
{
	return FigCount;
}
////////////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pGUI->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->HiddenStatus() == false)
			FigList[i]->DrawMe(pGUI);		//Call Draw function (virtual member fn)
	}		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the interface
GUI* ApplicationManager::GetGUI() const
{
	return pGUI;
}

void ApplicationManager::ClearFigList()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}


CFigure* ApplicationManager::getSelected()
{
	int index = getSelectedFigure();
	if (index >= 0 && index < FigCount)
		return FigList[index];
	return NULL;
}
// Return index of selected figure 
int ApplicationManager::getSelectedFigure()
{

	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsSelected())
			return i;
	return -1;
}

//CFigure* ApplicationManager::getFigureAt(int index)
//{
//	if (index >= 0 && index < FigCount)
//		return FigList[index];
//	else
//		return NULL;
//}

// -- For  Figure Deleted 
int ApplicationManager::DeleteFigure()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
		{
			delete FigList[i];
			FigList[i] = NULL;
			FigCount--;
			return i;
		}
	}

}
// After delete figure shift elements and delete null
void ApplicationManager::shiftFigList(int _figCount)
{
	for (int j = _figCount; j < FigCount; j++)
	{
		FigList[j] = FigList[j + 1];
	}
}


//==================================================================================//
//							Send To Back											//
//==================================================================================//

void ApplicationManager::SendToBack(int selectedIndex)
{
	if (selectedIndex != 0)
	{
		CFigure* spare = FigList[0];
		FigList[0] = FigList[selectedIndex];
		FigList[selectedIndex] = spare;
	}
}

//==================================================================================//
//							Bring To Front											//
//==================================================================================//

void ApplicationManager::BringToFront(int selectedIndex)
{
	if (selectedIndex != FigCount - 1)
	{
		CFigure* tmp = FigList[FigCount - 1];
		FigList[FigCount - 1] = FigList[selectedIndex];
		FigList[selectedIndex] = tmp;
	}
}



////////////////////////////////////////////////////////////////////////////////////
//Destructor


ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
		delete pGUI;
}


//==================================================================================//
//							------EXIT WINDOW----------      						//
//==================================================================================//

int ApplicationManager::DisplayMessageBox()
{
	int msgboxID = MessageBox(
		NULL,
		"You didn't save the drawing\nClick cancel to save\nOk to exit",
		"Exit",
		MB_OKCANCEL | MB_DEFBUTTON2 | MB_ICONWARNING
	);

	switch (msgboxID)
	{
	case IDCANCEL:
				break;
	case IDOK:
		exit(0);
		break;
	}
	//thia will execute the save and then exit immediatelly
	Action* newAct = new ActionSave(this, FigCount, true);
	ExecuteAction(newAct);

	
	return msgboxID;
}