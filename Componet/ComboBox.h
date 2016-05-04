#pragma once
#include "Component.h"
#include "RadioList.h"
#include "Label.h"
#include <iostream>

class ComboBox : public Label
{
	vector <string> _data;
	vector <string> output;
	RadioList *list;

public:
	ComboBox(COORD coord, DWORD backgroundColor, DWORD textColor, HANDLE handle, string text, vector <string> data)
		:Label(coord, backgroundColor, textColor, handle, text) {
	//	output = new vector<string>(10);
		int size = data.size();
		int maxLen = 0;
		for (int i = 0; i < size; i++) {
			if (data[i].size() > maxLen) {
				maxLen = data[i].size();
			}
		}
		COORD cordRadio = { coord.X,coord.Y + 2 };
		list = new RadioList(cordRadio, backgroundColor, textColor, handle, data, data.size() + 2, maxLen + 6);
	}
	virtual void keyEvent(KEY_EVENT_RECORD keyEvent);
	virtual void mouseEvent(MOUSE_EVENT_RECORD mouseEvent);
	//	virtual void draw();
	virtual void hide();
	vector<string>  getChoosenData() { return output; }
	~ComboBox();
};




