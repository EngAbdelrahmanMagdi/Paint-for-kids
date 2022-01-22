#ifndef CHANGE_Bg_COLOR_H
#define CHANGE_Bg_COLOR_H

#include "Action.h"

class changeBgColor : public Action
{
public:
	changeBgColor(ApplicationManager* pApp);

	virtual void Execute();

};

#endif