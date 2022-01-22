#include "ActionLoad.h"
#include "..\ApplicationManager.h"
#include"..\Figures\CSquare.h"
#include"..\Figures\CEllipse.h"
#include"..\Figures\CHexagon.h"
#include "..\GUI\GUI.h"
#include <fstream>
#include "String.h"

ActionLoad::ActionLoad(ApplicationManager* pApp, int FigCount) : Action(pApp)
{
	FileName = "temp";
	FigCnt = FigCount;    //We need the figure number to write it on the file
}

void ActionLoad::ReadActionParameters()
{

	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Enter File name to load");
	FileName = pGUI->GetSrting();  //read the file name
}

void ActionLoad::Execute()
{
	ReadActionParameters();     //get the parameters
	GUI* pGUI = pManager->GetGUI();

	ifstream InputFile;   //object of ofstream to write on the disk
	InputFile.open("SavedFiles\\" + FileName + ".txt");  // create a file with FileName and .txt exetention
	pGUI->ClearDrawArea();

	bool flag = false;
	if (InputFile.fail()) //Check the FileName and loop till be Valid name
	{
		pGUI->PrintMessage("File not found!");
	}
	else
	{
	if (InputFile.is_open())
		{
			//read from the file the current draw clr & fill clr &number of figuers 
			CFigure* pFig = NULL;
			int numberOfFiguers;
			string DrawClr, FillClr, BgClr;
			InputFile >> DrawClr;
			UI.DrawColor = pManager->ColorObject(DrawClr);

			InputFile >> FillClr;
			UI.FillColor = pManager->ColorObject(FillClr);

			InputFile >> BgClr;
			UI.BkGrndColor = pManager->ColorObject(BgClr);

			InputFile >> numberOfFiguers;
			//cleaning the figlist before loading the file
			pManager->ClearFigList();
			// Loop all figures ,identify the type ,then create an obj of the specified type,add to the figlist  after the loading it
			for (int i = 0; i < numberOfFiguers; i++)
			{
				string shapeType;
				InputFile >> shapeType;
				if (shapeType == "CSquare") {
					pFig = new CSquare;
				}
				else if (shapeType == "CEllipse") {
					pFig = new CEllipse;
				}
				else if (shapeType == "CHexagon") {
					pFig = new CHexagon;
				}

				//loading the parameters of each figure 
				pFig->Load(InputFile);
				if (pFig != NULL)
				{
					//seneding it to the application manager to add them
					pManager->AddFigure(pFig);
				}
			}
	};

		pManager->UpdateInterface();     //Draw the figure list

		pGUI->PrintMessage("Graph Loaded Successfully");
		Sleep(1000);
		pGUI->ClearStatusBar();
		InputFile.close();
		//close the file after looping 

	}

}