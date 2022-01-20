#ifndef TO_DRAW_ACTION_H
#define TO_DRAW_ACTION_H
#include "Action.h"


class ActionToDraw : public Action
{
public:
	ActionToDraw(ApplicationManager* pApp);
	void Execute();

};
#endif