#pragma once
#include "Component.h"
class CheckList :public Component
{
protected:
	virtual void printOption();
	virtual void chooseOption();
	virtual void firstMouseButtonPressed(MOUSE_EVENT_RECORD mouseEvent);
	vector <string> _data;
	vector <bool> isDataChoosen;
	COORD coordtemp;
	bool needFirstYellow = true;
public:
	
	~CheckList();
	CheckList(COORD coord, DWORD backgroundColor, DWORD textColor, HANDLE handle,vector <string> data,int height, int width)
		:Component(coord, backgroundColor, textColor, handle),_data(data), isDataChoosen(data.size()){
			_position.setHeight(height);
			_position.setWidth(width);
			int size = _data.size();
			for (int i = 0; i < size; i++) {
				_data[i].insert(0,"[ ] ");
			}
			 coordtemp = _position.getStartCord();
			 coordtemp.Y = coordtemp.Y + 1;
			 coordtemp.X = coordtemp.X + 2;
		}


	virtual void keyEvent(KEY_EVENT_RECORD keyEvent);
	virtual void mouseEvent(MOUSE_EVENT_RECORD mouseEvent);
	virtual void draw();
	virtual void hide(); //or amit change
	bool getNeedFirstYellow() { return needFirstYellow; }
	vector<string>  getChoosenData();//tempory


};

