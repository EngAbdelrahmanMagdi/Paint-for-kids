#include "PickByBoth.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CSquare.h"
#include "..\GUI\GUI.h"
#include "..\Actions\Delete.h"




void PickByBoth::PrntScore(int S)
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
	

}

PickByBoth::PickByBoth(ApplicationManager* pApp) :Action(pApp)
{
	no_combs = 0;
	wrgSel = 0;
	rigSel = 0;
	for (int i = 0; i < 24; i++)
		combinations[i] = 0;
}


PickByBoth::~PickByBoth()
{

}

void PickByBoth::ReadActionParameters()
{
	for (int i = 0; i < pManager->getFigCount(); i++) {
		Fig = pManager->DrawnFigs(i);
		if ((Fig->GetGfxInfo().isFilled) ) //counts combinations occurance.
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CSquare*>(Fig))
					combinations[0]++;
				else if (dynamic_cast<CEllipse*>(Fig))
					combinations[1]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[2]++;
			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				if (dynamic_cast<CSquare*>(Fig))
					combinations[3]++;
				else if (dynamic_cast<CEllipse*>(Fig))
					combinations[4]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[5]++;
			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CSquare*>(Fig))
					combinations[6]++;
				else if (dynamic_cast<CEllipse*>(Fig))
					combinations[7]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[8]++;
			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				if (dynamic_cast<CSquare*>(Fig))
					combinations[9]++;
				else if (dynamic_cast<CEllipse*>(Fig))
					combinations[10]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[11]++;
			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				if (dynamic_cast<CSquare*>(Fig))
					combinations[12]++;
				else if (dynamic_cast<CEllipse*>(Fig))
					combinations[13]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[14]++;
			}
			else if (Fig->GetGfxInfo().FillClr == PINK)
			{
				if (dynamic_cast<CSquare*>(Fig))
					combinations[15]++;
				else if (dynamic_cast<CEllipse*>(Fig))
					combinations[16]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[17]++;
			}
			else if (Fig->GetGfxInfo().FillClr == PURPLE)
			{
				if (dynamic_cast<CSquare*>(Fig))
					combinations[18]++;
				else if (dynamic_cast<CEllipse*>(Fig))
					combinations[19]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[20]++;
			}
		}
		else {
			if (dynamic_cast<CSquare*>(Fig))
				combinations[21]++;
			else if (dynamic_cast<CEllipse*>(Fig))
				combinations[22]++;
			else if (dynamic_cast<CHexagon*>(Fig))
				combinations[23]++;
			
		}
	}

	for (int i = 0; i < 24; i++)
		if (combinations[i] != 0)
			no_combs++;


}

void PickByBoth::Execute()
{

	GUI* pGUI = pManager->GetGUI();
	ReadActionParameters();

	if (no_combs > 1)
	{
		//Figure to be hidden
		CFigure* clickedFig;
		//Randomize
		rand_fig_no = rand() % pManager->getFigCount();
		//Counting the the color instances.
		Fig = pManager->DrawnFigs(rand_fig_no);
		if ((Fig->GetGfxInfo().isFilled))
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[0];
					pGUI->PrintMessage("Pick up all the black Squares!");

				}
				else if (dynamic_cast<CEllipse*>(Fig))
				{
					picked_comb_no = combinations[1];
					pGUI->PrintMessage("Pick up all the black Elipses!");

				}
				else if (dynamic_cast<CHexagon*>(Fig))
				{
					picked_comb_no = combinations[2];
					pGUI->PrintMessage("Pick up all the black Hexagonss!");

				}

			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[3];
					pGUI->PrintMessage("Pick up all the white Squares!");

				}
				else if (dynamic_cast<CEllipse*>(Fig))
				{
					picked_comb_no = combinations[4];
					pGUI->PrintMessage("Pick up all the white Elipses!");

				}
				else if (dynamic_cast<CHexagon*>(Fig))
				{
					picked_comb_no = combinations[5];
					pGUI->PrintMessage("Pick up all the white Hexagons!");

				}

			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[6];
					pGUI->PrintMessage("Pick up all the Blue Squares!");

				}
				else if (dynamic_cast<CEllipse*>(Fig))
				{
					picked_comb_no = combinations[7];
					pGUI->PrintMessage("Pick up all the Blue Elipses!");

				}
				else if (dynamic_cast<CHexagon*>(Fig))
				{
					picked_comb_no = combinations[8];
					pGUI->PrintMessage("Pick up all the Blue Hexagons!");

				}


			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[9];
					pGUI->PrintMessage("Pick up all the Green Squares!");

				}
				else if (dynamic_cast<CEllipse*>(Fig))
				{
					picked_comb_no = combinations[10];
					pGUI->PrintMessage("Pick up all the Green Elipses!");

				}
				else if (dynamic_cast<CHexagon*>(Fig))
				{
					picked_comb_no = combinations[11];
					pGUI->PrintMessage("Pick up all the Green Hexagons!");

				}

			}

			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[12];
					pGUI->PrintMessage("Pick up all the red  Squares !");

				}
				else if (dynamic_cast<CEllipse*>(Fig))
				{
					picked_comb_no = combinations[13];
					pGUI->PrintMessage("Pick up all the red Ellipses!");

				}
				else if (dynamic_cast<CHexagon*>(Fig))
				{
					picked_comb_no = combinations[14];
					pGUI->PrintMessage("Pick up all the red Hexagons!");

				}

			}
		}
		
			else if (Fig->GetGfxInfo().FillClr == PINK)
			{
				if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[15];
					pGUI->PrintMessage("Pick up all the Pink  Squares !");

				}
				else if (dynamic_cast<CEllipse*>(Fig))
				{
					picked_comb_no = combinations[16];
					pGUI->PrintMessage("Pick up all the Pink Ellipses!");

				}
				else if (dynamic_cast<CHexagon*>(Fig))
				{
					picked_comb_no = combinations[17];
					pGUI->PrintMessage("Pick up all the Pink Hexagons!");

				}

			}

			else if (Fig->GetGfxInfo().FillClr == PURPLE)
			{
			if (dynamic_cast<CSquare*>(Fig))
			{
				picked_comb_no = combinations[18];
				pGUI->PrintMessage("Pick up all the Purple  Squares !");

			}
			else if (dynamic_cast<CEllipse*>(Fig))
			{
				picked_comb_no = combinations[19];
				pGUI->PrintMessage("Pick up all the Purple Ellipses!");

			}
			else if (dynamic_cast<CHexagon*>(Fig))
			{
				picked_comb_no = combinations[20];
				pGUI->PrintMessage("Pick up all the Purple Hexagons!");

			}


			}

			
		

		else
		{
			if (dynamic_cast<CSquare*>(Fig))
			{
				picked_comb_no = combinations[21];
				pGUI->PrintMessage("Pick up all the unfilled rectangles!");

			}
			else if (dynamic_cast<CEllipse*>(Fig))
			{
				picked_comb_no = combinations[22];
				pGUI->PrintMessage("Pick up all the unfilled Elipses!");

			}
			else if (dynamic_cast<CHexagon*>(Fig))
			{
				picked_comb_no = combinations[23];
				pGUI->PrintMessage("Pick up all the unfilled Hexagons!");

			}
			
			

		}



		while (picked_comb_no > 0)
		{

			pGUI->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(P.x, P.y);
				if (clickedFig != NULL)
				{

					
					 if (dynamic_cast<CSquare*>(Fig) && dynamic_cast<CSquare*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (dynamic_cast<CEllipse*>(Fig) && dynamic_cast<CEllipse*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (dynamic_cast<CHexagon*>(Fig) && dynamic_cast<CHexagon*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
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
				picked_comb_no = -1;
			}
		}

		
		if (picked_comb_no == 0)
			PrntScore(3);
		if (rigSel > wrgSel) {
			pGUI->PrintMessage("You won!");

		}
		else {
			pGUI->PrintMessage("You lost!");


		}

	}
	else pGUI->PrintMessage("You must have at least two or more combinations to play pick by both!");
	for (int i = 0; i < pManager->getFigCount(); i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();
}