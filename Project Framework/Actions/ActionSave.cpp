#include "ActionSave.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CFigure.h"
#include "..\GUI\GUI.h"
#include<fstream>

ActionSave::ActionSave(ApplicationManager* pApp, int FigCount,bool exit=false) : Action(pApp)
{
	FileName = "temp_name";
	//FigCnt = FigCount;    //figure number to write it on the file
	FigCnt = FigCount;
	fireExit = exit;
}

void ActionSave::ReadActionParameters()
{
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Enter File Name");
	FileName = pGUI->GetSrting();  //read the file name
}

void ActionSave::Execute()
{
	ReadActionParameters();     //get the parameters
	GUI* pGUI = pManager->GetGUI();

	ofstream OutFile;   //object of ofstream to write on the disk
	OutFile.open("SavedFiles\\" + FileName + ".txt");  // create a file with FileName and .txt exetention

	//adding UI info to the output
	OutFile << pManager->colorString(UI.DrawColor)
		<< "\t" << pManager->colorString(UI.FillColor) 
		<< "\t" << pManager->colorString(UI.BkGrndColor) << "\n";
		OutFile << FigCnt << "\n";


	pManager->SaveAll(OutFile);  //Now Start Saving each figure proccess 
	OutFile.close();
	pGUI->PrintMessage("File Saved!");

	if (fireExit)
		exit(0);
	
}
