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

	//GUI* pGUI = pManager->GetGUI();
	//pGUI->ClearStatusBar();
	//pGUI->PrintMessage("Enter File name to load");
	//FileName = pGUI->GetSrting();  //read the file name
}

bool ActionLoad::ReadFileLocation(char szFileName[])
{
	OPENFILENAME ofn;
	const char* FilterSpec = "All\0*.*\0Text\0*.TXT\0";
	const char* Title = "Load a File ..";

	char szFileTitle[MAX_PATH] = "";

	*szFileName = 0;

	/* fill in non-variant fields of OPENFILENAME struct. */
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = GetFocus();
	ofn.lpstrFilter = FilterSpec;
	ofn.lpstrCustomFilter = NULL;
	ofn.nMaxCustFilter = 0;
	ofn.nFilterIndex = 0;
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrInitialDir = "."; // Initial directory.
	ofn.lpstrFileTitle = szFileTitle;
	ofn.nMaxFileTitle = MAX_PATH;
	ofn.lpstrTitle = Title;
	ofn.lpstrDefExt = 0; // I've set to null for demonstration
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

	// false if failed or cancelled
	return GetOpenFileName(&ofn);
}

void ActionLoad::Execute()
{		
	char openedFileName[MAX_PATH];
	//ReadActionParameters();     //get the parameters
	GUI* pGUI = pManager->GetGUI();
	ifstream InputFile;   //object of ofstream to write on the disk
	if (ReadFileLocation(openedFileName))
	{
		InputFile.open(openedFileName);  // openedFileName holds the path of the loaded file
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
	else
	{
		pGUI->PrintMessage("User cancelled the operation");
	}
}