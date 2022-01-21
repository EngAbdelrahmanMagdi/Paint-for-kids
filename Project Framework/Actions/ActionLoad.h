#ifndef ACTION_LOAD_H
#define ACTION_LOAD_H
#include "Action.h"

class ActionLoad : public Action
{
private:
	string FileName;
	int FigCnt;
public:
	ActionLoad(ApplicationManager* pApp, int FigCount);

	virtual void ReadActionParameters();

	color ActionLoad::getColorObject(string name)const;

	virtual void Execute();

	//void LoadPlayMode();
};

#endif