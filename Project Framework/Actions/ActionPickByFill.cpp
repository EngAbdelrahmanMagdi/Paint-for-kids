#include "ActionPickByFill.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CSquare.h"
#include "..\GUI\GUI.h"


color PickByFill::AssignColor(CFigure* Fig)
{
	
   if (Fig->GetGfxInfo().isFilled)
	{
		if (Fig->GetGfxInfo().FillClr == BLACK)
			return BLACK;
		else if (Fig->GetGfxInfo().FillClr == WHITE)
			return WHITE;
		else if (Fig->GetGfxInfo().FillClr == BLUE)
			return BLUE;
		else if (Fig->GetGfxInfo().FillClr == GREEN)
			return GREEN;
		else if (Fig->GetGfxInfo().FillClr == RED)
			return RED;
		else if (Fig->GetGfxInfo().FillClr == PINK)
			return PINK;
		else if (Fig->GetGfxInfo().FillClr == PURPLE)
			return PURPLE;
	}
}

void PickByFill::PrntScore(int S)
{
	GUI* pGUI = pManager->GetGUI();

	string message;
	if (S == 1)
	{
		rigSel++;
		message = "Right!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	}
	else 	if (S == 2)
	{
		wrgSel++;
		message = "Wrong!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	}
	else
		message = "YOU WIN!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	pGUI->PrintMessage(message);


}

PickByFill::PickByFill(ApplicationManager* pApp) :Action(pApp)
{
	no_colors = 0;
	wrgSel = 0;
	rigSel = 0;
	for (int i = 0; i < 7; i++)
		clrs[i] = 0;
}


PickByFill::~PickByFill()
{
}

void PickByFill::ReadActionParameters()
{

	for (int i = 0; i < pManager->getFigCount(); i++) {
		Fig = pManager->DrawnFigs(i);
		if (Fig->GetGfxInfo().isFilled) //counts color occurance.
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
				clrs[0]++;
			else if (Fig->GetGfxInfo().FillClr == WHITE)
				clrs[1]++;
			else if (Fig->GetGfxInfo().FillClr == BLUE)
				clrs[2]++;
			else if (Fig->GetGfxInfo().FillClr == GREEN)
				clrs[3]++;
			else if (Fig->GetGfxInfo().FillClr == RED)
				clrs[4]++;
			else if (Fig->GetGfxInfo().FillClr == PINK)
				clrs[5]++;
			else if (Fig->GetGfxInfo().FillClr == PURPLE)
				clrs[6]++;
		}
		
	}

	for (int i = 0; i < 7; i++)
		if (clrs[i] != 0)no_colors++;


}


void PickByFill::Execute()
{


	GUI* pGUI = pManager->GetGUI();
	ReadActionParameters();

	if (no_colors > 1)
	{
		//Figure clicked to be hidden
		CFigure* clickedFig;
		//Randomize
		rand_fig_no = rand() % pManager->getFigCount();
		//Counting the the color instances.
		Fig = pManager->DrawnFigs(rand_fig_no);
		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				picked_color_no = clrs[0];
				pGUI->PrintMessage("Pick up figures colored black!");
			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				picked_color_no = clrs[1];
				pGUI->PrintMessage("Pick up figures colored white!");
			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				picked_color_no = clrs[2];
				pGUI->PrintMessage("Pick up figures colored blue!");

			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				picked_color_no = clrs[3];
				pGUI->PrintMessage("Pick up figures colored green!");

			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				picked_color_no = clrs[4];
				pGUI->PrintMessage("Pick up figures colored red!");

			}
			else if (Fig->GetGfxInfo().FillClr == PINK)
			{
				picked_color_no = clrs[5];
				pGUI->PrintMessage("Pick up figures colored pink!");

			}
			else if (Fig->GetGfxInfo().FillClr == PURPLE)
			{
				picked_color_no = clrs[6];
				pGUI->PrintMessage("Pick up figures colored purple!");

			}
		}
		else
		{
			
				if (Fig->GetGfxInfo().DrawClr == BLACK)
				{
					picked_color_no = clrs[0];
					pGUI->PrintMessage("Pick up figures colored black!");
				}
				else if (Fig->GetGfxInfo().DrawClr == WHITE)
				{
					picked_color_no = clrs[1];
					pGUI->PrintMessage("Pick up figures colored white!");
				}
				else if (Fig->GetGfxInfo().DrawClr == BLUE)
				{
					picked_color_no = clrs[2];
					pGUI->PrintMessage("Pick up figures colored blue!");

				}
				else if (Fig->GetGfxInfo().DrawClr == GREEN)
				{
					picked_color_no = clrs[3];
					pGUI->PrintMessage("Pick up figures colored green!");

				}
				else if (Fig->GetGfxInfo().DrawClr == RED)
				{
					picked_color_no = clrs[4];
					pGUI->PrintMessage("Pick up figures colored red!");

				}
				else if (Fig->GetGfxInfo().FillClr == PINK)
				{
					picked_color_no = clrs[5];
					pGUI->PrintMessage("Pick up figures colored pink!");

				}
				else if (Fig->GetGfxInfo().FillClr == PURPLE)
				{
					picked_color_no = clrs[6];
					pGUI->PrintMessage("Pick up figures colored purple!");

				}
			}
			
			

		
		

		while (picked_color_no > 0)
		{

			pGUI->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(P.x, P.y);
				if (clickedFig != NULL)
				{

					if ((!(Fig->GetGfxInfo().isFilled)) && (!(clickedFig->GetGfxInfo().isFilled)))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_color_no--;
					}
					else if (clickedFig->GetGfxInfo().DrawClr == AssignColor(Fig))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_color_no--;
					}
					else if (clickedFig->GetGfxInfo().isFilled && clickedFig->GetGfxInfo().FillClr == AssignColor(Fig))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_color_no--;
					}
					else
					{
						PrntScore(2);
						clickedFig->Hide();
						pManager->UpdateInterface();
					}
				}
			}
			else
			{
				pGUI->PrintMessage("Toolbar clicked, game aborted.");
				picked_color_no = -1;
			}


		}
		if (picked_color_no == 0)
			PrntScore(3);
	}
	else 			pGUI->PrintMessage("You must have at least two or more colors to play pick by color!");
	for (int i = 0; i < pManager->getFigCount(); i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();
}