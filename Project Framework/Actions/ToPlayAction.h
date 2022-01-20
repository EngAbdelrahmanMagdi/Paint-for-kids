#ifndef TO_PLAY_ACTION_H
#define TO_PLAY_ACTION_H
#include "Action.h"


class ActionToPlay: public Action
{
public:
	ActionToPlay(ApplicationManager* pApp);
	void Execute();

};
#endif