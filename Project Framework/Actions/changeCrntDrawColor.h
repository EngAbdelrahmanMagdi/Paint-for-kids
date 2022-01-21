#ifndef CHANGE_CRNT_DRAW_COLOR_H
#define CHANGE_CRNT_DRAW_COLOR_H

#include "Action.h"

class changeCrntDrawColor : public Action
{
public:
	changeCrntDrawColor(ApplicationManager* pApp);

	virtual void Execute();

};

#endif