#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class changeFigDrawColor : public Action
{
public:
	changeFigDrawColor(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

