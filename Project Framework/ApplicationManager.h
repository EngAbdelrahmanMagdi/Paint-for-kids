#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	//Pointers to Input and Output classes
	GUI* pGUI;


public:
	ApplicationManager();
	~ApplicationManager();

	void Run();		//to run the application

	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&); //Execute an action
	int DisplayMessageBox(); 

	//--Actions-Related-To-Save-And-Load
	string colorString(color) const;
	color ColorObject(string) const;
	void SaveAll(ofstream& Out);

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure

	// -- Interface Management Functions	
	GUI* GetGUI() const; //Return pointer to the interface
	void ClearFigList();
	void UpdateInterface() const;	//Redraws all the drawing window	
	int getSelectedFigure();// Return selected Figure
	//CFigure* getFigureAt(int index);
	void SendToBack(int selectedIndex); // Action Send to back 
	void BringToFront(int selectedIndex);// Action Bring to Forward 
	int DeleteFigure(); //// Action Delete Figures  
	void shiftFigList(int _figCount); // After delete figure shift elements and delete null
	CFigure* DrawnFigs(int i) const;
	int getFigCount() const;
	CFigure* getSelected();
};

#endif