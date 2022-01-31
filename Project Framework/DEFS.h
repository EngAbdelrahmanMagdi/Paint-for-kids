#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_SQUARE,	//Draw a Square

	DRAW_ELPS,		//Draw an Ellipse
	DRAW_HEX,		//Draw a Hexagon
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	CHG_FIG_FILL_COLOR,  //changes the selectesd fig fill color
	CHG_FIG_DRAW_COLOR,  //changes the selected fig draw color
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application
	SELECT,
	DRAWING_AREA,//A click on the drawing area
	PLAYING_AREA,
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	QUARTERED_RESIZE,
	HALFED_RESIZE,
	DOUBLED_RESIZE,
	QUADRUPLE_RESIZED,
	P_H_TYPE,
	P_H_FILL,
	P_H_BOTH,
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY			//Switch interface to Play mode

	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

struct HexagonStruct {

	Point P1;
	Point P2;
	int radius; 
	int XS[6];
	int YS[6];
	bool fitInBoundary;
};

#endif