#include "Action.h"

#include"Action.h"
class ActionSave : public Action
{
private:
	string FileName;
	int FigCnt;
public:
	ActionSave(ApplicationManager* pApp, int FigCount);
	virtual void ReadActionParameters();
	virtual void Execute();
};