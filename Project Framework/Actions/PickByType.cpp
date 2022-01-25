#include "PickByType.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CSquare.h"
#include "..\GUI\GUI.h"



PickByType::PickByType(ApplicationManager* pApp) :Action(pApp)
{
	no_figs = 0;
	rigSel = 0;
	wrgSel = 0;
	for (int i = 0; i < 4; i++)
		figs[i] = 0;
}
void PickByType::PrntScore(int S)
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

PickByType::~PickByType()
{
}

void PickByType::ReadActionParameters()
{
	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		Fig = pManager->DrawnFigs(i);
		if (dynamic_cast<CSquare*>(Fig))
			figs[0]++;
		else if (dynamic_cast<CEllipse*>(Fig))
			figs[1]++;
		else if (dynamic_cast<CHexagon*>(Fig))
			figs[2]++;
		else figs[3]++;




	}		for (int i = 0; i < 4; i++)
		if (figs[i] != 0)no_figs++;
}

void PickByType::Execute()
{
	GUI* pGUI = pManager->GetGUI();
	ReadActionParameters();
	if (no_figs > 1)
	{
		CFigure* clickedFig;
		//Randomize
		rand_fig_no = rand() % pManager->getFigCount();
		//counting fig instances
		Fig = pManager->DrawnFigs(rand_fig_no);
		if (dynamic_cast<CSquare*>(Fig))
		{
			picked_fig_no = figs[0];
			pGUI->PrintMessage("Pick up all the Squares!");

		}
		else if (dynamic_cast<CEllipse*>(Fig))
		{
			picked_fig_no = figs[1];
			pGUI->PrintMessage("Pick up all the CEllipses!");

		}
		else if (dynamic_cast<CHexagon*>(Fig))
		{
			picked_fig_no = figs[2];
			pGUI->PrintMessage("Pick up all the CHexagones!");

		}
		else {
			pGUI->PrintMessage(" Not figures");
		}
		
		while (picked_fig_no > 0)
		{
			{

				pGUI->GetPointClicked(P.x, P.y);
				if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
				{
					clickedFig = pManager->GetFigure(P.x, P.y);
					if (clickedFig != NULL)
					{

						
						 if ((dynamic_cast<CSquare*>(clickedFig)) && (dynamic_cast<CSquare*>(Fig)))
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_fig_no--;
						}
						else if ((dynamic_cast<CEllipse*>(clickedFig)) && (dynamic_cast<CEllipse*>(Fig)))
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_fig_no--;
						}
						
						else if ((dynamic_cast<CHexagon*>(clickedFig)) && (dynamic_cast<CHexagon*>(Fig)))
						 {
							 PrntScore(1);
							 clickedFig->Hide();
							 pManager->UpdateInterface();
							 picked_fig_no--;
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
					picked_fig_no = -1;
				}


			}
			if (picked_fig_no == 0)
				PrntScore(3);



		}
	}
	else
		pGUI->PrintMessage("You must have at least two or more figures to play to play pick by figure!");
	for (int i = 0; i < pManager->getFigCount(); i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();





}