#ifndef SEND_BACK_H
#define SEND_BACK_H
#include "Action.h"

#pragma once
class ActionSendBack : public Action
{
public:
	ActionSendBack(ApplicationManager* pApp);
	void Execute();

};


#endif