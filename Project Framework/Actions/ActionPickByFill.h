#pragma once
#ifndef PICK_BY_FILL_H
#define PICK_BY_FILL_H
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#endif

class PickByFill :
	public Action
{
	CFigure* Fig = NULL;
	int  no_colors, rand_fig_no, picked_color_no, wrgSel, rigSel;
	int clrs[7];
	Point P;
	color AssignColor(CFigure*);
	void PrntScore(int);
public:
	PickByFill(ApplicationManager*);
	~PickByFill();
	void ReadActionParameters();
	void Execute();

};

