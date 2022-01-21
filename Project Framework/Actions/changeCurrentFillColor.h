#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class changeCurrentFillColor : public Action
{
public:
	changeCurrentFillColor(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

