#ifndef SELECT_H
#define SELECT_H
#include "Action.h"
#pragma once
class Select : public Action
{
public:
	Select(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();
};

#endif