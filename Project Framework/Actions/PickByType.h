#ifndef PICK_BY_TYPE_H
#define PICK_BY_TYPE_H
#include "Action.h"
#include "..\Figures\CFigure.h"
class PickByType :
	public Action
{
	CFigure* Fig;
	Point P;
	int  no_figs, rand_fig_no, picked_fig_no, wrgSel, rigSel;
	int figs[4];
	void PrntScore(int);

public:
	PickByType(ApplicationManager*);
	~PickByType();
	void ReadActionParameters();
	void Execute();
};
#endif