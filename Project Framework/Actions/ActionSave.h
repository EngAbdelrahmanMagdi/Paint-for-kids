#include "Action.h"

class ActionSave : public Action
{
private:
	string FileName;
	int FigCnt;
	bool fireExit;
public:
	ActionSave(ApplicationManager*, int,bool);
	virtual void ReadActionParameters();
	virtual void Execute();
};