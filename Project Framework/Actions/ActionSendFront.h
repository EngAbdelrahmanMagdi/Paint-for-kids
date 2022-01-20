#ifndef SEND_FRONT_H
#define SEND_FRONT_H
#include "Action.h"


class ActionBringFront : public Action
{
public:
	ActionBringFront(ApplicationManager* pApp);
	void Execute();

};
#endif