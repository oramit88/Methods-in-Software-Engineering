#pragma once
#include "Component.h"
#include <iostream>
using namespace std;
class Label : public Component
{
protected:
	string _text;
public:

	virtual void keyEvent(KEY_EVENT_RECORD keyEvent);
	virtual void mouseEvent(MOUSE_EVENT_RECORD mouseEvent);
	virtual void draw();
	virtual void hide();
	vector<string>  getChoosenData() {
		vector<string> v;
		v.push_back(_text);
		return v;
	}
	Label(COORD coord, DWORD backgroundColor, DWORD textColor, HANDLE handle, string text)
		:Component(coord, backgroundColor, textColor, handle), _text(text) {}
	~Label();
};

