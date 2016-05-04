#pragma once
#include <windows.h>
#include <vector>
class Position
{
	COORD _startCord;
	int _width;
	int _height;
public:
	COORD getStartCord() {return _startCord;}
	 void setStartCord(COORD startCord) {_startCord = startCord;}
	 int getWidth() {	return _width;}
	 void setWidth(int width) {_width = width;}
	 int getHeight() {return _height;}
	void setHeight(int height) {_height = height;}
	Position(COORD startCord, int width,int height):_startCord(startCord), _width(width), _height(height){}
	~Position() {};
};

