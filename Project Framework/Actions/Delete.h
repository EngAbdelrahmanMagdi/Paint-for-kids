#ifndef DELETE_H
#define DELETE_H
#include "Action.h"
#pragma once

class Delete : public Action
{
public:
	Delete(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();
};
#endif





