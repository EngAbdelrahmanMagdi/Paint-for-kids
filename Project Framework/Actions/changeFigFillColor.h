#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class changeFigFillColor: public Action
{
public:
	changeFigFillColor (ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

