#ifndef ACTION_RESIZE_FIGURE_H
#define ACTION_RESIZE_FIGURE_H

#include "Action.h"

//Add Square Action class
class ActionResizeFigure : public Action
{
private: 
	float factorOfResize;
public:
	ActionResizeFigure(ApplicationManager * pApp, float factor);

	
	virtual void Execute();

};

#endif