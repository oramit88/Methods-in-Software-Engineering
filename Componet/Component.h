#pragma once
#include <string>
#include "Position.h"
#include <vector>
#include <iostream>
using namespace std;
enum TypeLebel { LABEL,BUTTON,TEXTBOX,NUMERICBOX,COMBOBOX,CHECKLIST,RADIOBOX,PANEL,MESSAGEBOX};
class Component
{
protected:
	Position _position;
	HANDLE _handle;
	DWORD _backgroundColor;
	DWORD _textColor;
	TypeLebel typeLebel; //check
	bool _isComponetVisible;
	bool _isCursorVisible;
	

public:
	bool isPressOnMe(COORD coord);	// need to test more
//	Component(Position position,DWORD backgroundColor,DWORD textColor,HANDLE handle):
	//	_position(position),_backgroundColor(backgroundColor),_textColor(textColor),_handle(handle){}
	Component(COORD coord, DWORD backgroundColor, DWORD textColor, HANDLE handle) :
		_position(coord,-1,-1), _backgroundColor(backgroundColor), _textColor(textColor), _handle(handle) {}
	 ~Component() {};
	virtual void setPosition(Position position) { _position = position; } //changing- need to re-draw the object
	virtual void setCursorVisible(bool flag) { _isCursorVisible = flag; }

	virtual void setBackgroundColor(DWORD backgroundColor) { _backgroundColor = backgroundColor; }
	virtual void setTextColor(DWORD textColor) { _backgroundColor = textColor; }

	virtual Position getPosition() { return _position; }
	virtual bool isComponetVisible() { return _isComponetVisible; }
	virtual bool isCursorVisible() { return _isCursorVisible; }

	virtual DWORD getBackgroundColor() { return _backgroundColor; }
	virtual DWORD getTextColor() { return _textColor; }

	virtual void keyEvent(KEY_EVENT_RECORD keyEvent) = 0;
	virtual void mouseEvent(MOUSE_EVENT_RECORD mouseEvent) = 0;

	//virtual void createFrame() = 0; // replace to draw
	virtual void draw();
	virtual void hide();

	virtual vector<string> getChoosenData() = 0;
	//virtual void setVisible(bool flag) = 0; // replace to draw() and hide()

	

};

