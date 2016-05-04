
#pragma once
#include "CheckList.h"
class RadioList :
	public CheckList
{
	virtual void printOption();
	virtual void chooseOption();
	virtual void firstMouseButtonPressed(MOUSE_EVENT_RECORD mouseEvent);
public:
	RadioList(COORD coord, DWORD backgroundColor, DWORD textColor, HANDLE handle, vector <string> data, int height, int width)
		:CheckList(coord, backgroundColor, textColor, handle,data, height, width){
	}

	~RadioList();
};

