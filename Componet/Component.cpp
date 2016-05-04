#include "Component.h"



void Component::draw() {
	_isComponetVisible = true;
	SetConsoleTextAttribute(_handle, _textColor | _backgroundColor);
	int width, high;
	width = _position.getWidth();
	high = _position.getHeight();
	COORD c = _position.getStartCord();
	SetConsoleCursorPosition(_handle, c);

	for (int rows = 0; rows <high; rows++) {
		for (int col = 0; col < width; col++) {
			if (col == 0 || col == (width - 1) || rows == 0 || (rows == high - 1)) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
		c.Y++;
		SetConsoleCursorPosition(_handle, c);
	}
	COORD startCoordinate = _position.getStartCord();
	startCoordinate.Y++;
	startCoordinate.X++;
	SetConsoleCursorPosition(_handle, startCoordinate);
}



void Component::hide() {
	_isComponetVisible = false;
	DWORD terminalBcgColor = COLOR_BACKGROUND;//black
	SetConsoleTextAttribute(_handle, terminalBcgColor);
	
	int width, high;
	width = _position.getWidth();
	high = _position.getHeight();
	COORD c = _position.getStartCord();
	SetConsoleCursorPosition(_handle, c);

	for (int rows = 0; rows <high; rows++) {
		for (int col = 0; col < width; col++) {
			printf(" ");
		}
		printf("\n");
		c.Y++;
		SetConsoleCursorPosition(_handle, c);
	}
	COORD startCoordinate = _position.getStartCord();
	startCoordinate.Y++;
	startCoordinate.X++;
	SetConsoleCursorPosition(_handle, startCoordinate);
}


bool Component::isPressOnMe(COORD coord) {
	/*
	cout << "my start coord X is:" << _position.getStartCord().X<<endl;
	cout << "my start coord Y is:" << _position.getStartCord().Y << endl;
	cout << "my WIDTH:" << _position.getWidth() << endl;
	cout << "my Hight:" << _position.getHeight() << endl;
	cout << "my press: (" << coord.X <<","<<coord.Y<<")"<<endl;
	*/
		 
	if (_position.getHeight() == -1 || _position.getWidth()==-1) {
		return false;
	}
	else if ((_position.getStartCord().X + _position.getWidth() > coord.X) && (coord.X>_position.getStartCord().X)&&(_position.getStartCord().Y + _position.getHeight() > coord.Y)&&(coord.Y>_position.getStartCord().Y)) {
		
		
		return true;
	}
	else return false;
}


