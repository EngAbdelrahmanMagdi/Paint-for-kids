#ifndef GUI_H
#define GUI_H

#include <fstream>
#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"


//This class is responsible for Grphical User Interface handling
//All user input and program outputs MUST be done through this class
//No other class is allowed to perform direct i/o
class GUI
{
public:
	window* pWind;	//Pointer to the Graphics Window
public:
	GUI();
	~GUI();
	window* CreateWind(int, int, int, int) const; //creates the application window

	/////////// Input Functoinality  /////////////////
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	ActionType MapInputToActionType() const; //Read the user click and map to an action


	/////////// Output Functoinality  ////////////////
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateColorToolBar() const;
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a Square
	void DrawEllipse(Point P1, Point P2, GfxInfo ElpsGfxInfo, bool selected = false) const; //Draw an Ellipse 
	void DrawHexagon(Point P1, Point P2, GfxInfo HexGfxInfo, bool selected) ;  //Draw a Hexagon
	void getHexagonPoints(Point P1, Point P2, Point* vertics); //get hexagon points
	bool allPointsInDrawingArea(Point* point, int count) const;
	bool isPointInDrawingArea(int x, int y) const;
	///TODO: Make similar functions for drawing all other figures.

	void PrintMessage(string msg) const;	//Print a message on Status bar
	void ClearToolBarArea() const;
	color getCrntDrawColor() const;	//get current drwawing color
	void setCrntDrawColor(color c) const;
	color getCrntFillColor() const;	//get current filling color
	void setCrntFillColor(color c) const;
	void setBgColor(color c) const;
	int getCrntPenWidth() const;		//get current pen width


};


#endif