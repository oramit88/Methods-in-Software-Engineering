#pragma once
#include "Component.h"
class TextBox :
	public Component
{
	string _text;
	int textSize;
	int maxSize;
	COORD position;
public:
	virtual void keyEvent(KEY_EVENT_RECORD keyEvent);
	virtual void mouseEvent(MOUSE_EVENT_RECORD mouseEvent);
	virtual vector<string> getChoosenData();
	//virtual void createFrame() = 0; // replace to draw
	virtual void draw();
	virtual void hide();
	TextBox(COORD coord, DWORD backgroundColor, DWORD textColor, HANDLE handle,int width,string text = "") 
		:Component(coord, backgroundColor, textColor, handle){
		_text = text;
		_position.setHeight(3);
		_position.setWidth(width);
		textSize = text.size();
		maxSize = width - 2;
		position = _position.getStartCord();
		position.X++;
		position.Y++;
	}
	~TextBox();
};

