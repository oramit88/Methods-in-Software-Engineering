#include "CheckList.h"

CheckList::~CheckList()
{
}

void CheckList::draw() {
	Component::draw();
	CONSOLE_CURSOR_INFO cci = { 100, TRUE };
	SetConsoleCursorInfo(_handle, &cci);
	int vector_size = _data.size();
	COORD temp = _position.getStartCord();
	temp.X++;
	temp.Y++;
	SetConsoleCursorPosition(_handle, temp);

	for (int i = 0; i < vector_size;i++){
		if (i == 0) {
	
			DWORD wAttr;
			if (needFirstYellow) {
				 wAttr = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
				SetConsoleTextAttribute(_handle, wAttr);
				needFirstYellow = false;
			}
			cout << _data[i]<<endl;
			wAttr = _textColor | _backgroundColor;
			SetConsoleTextAttribute(_handle, wAttr);
			temp.Y++;
			
		}
		else {//next 
			SetConsoleCursorPosition(_handle, temp);
			cout << _data[i] << endl;
			temp.Y++;
		}
	}
}

void CheckList::hide(){
Component::hide();
}




void CheckList::keyEvent(KEY_EVENT_RECORD keyEvent) {
	if (_isComponetVisible == true) {
		static int counter = 0;
		counter++;
		if (counter % 2 == 0) {
			return;
		}

		char c = keyEvent.uChar.AsciiChar;
		//move down
		DWORD textColor = _textColor | _backgroundColor; //green
		DWORD textColorSelect = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;

		switch (keyEvent.wVirtualKeyCode)
		{
		case VK_ESCAPE:
			cout << "esc";
			break;

		case VK_RETURN:
			chooseOption();
			break;
		case VK_UP:
			if (coordtemp.Y - _position.getStartCord().Y > 1) {
				//print the priviuse to green
				SetConsoleTextAttribute(_handle, textColor);
				coordtemp.X--;
				SetConsoleCursorPosition(_handle, coordtemp);
				printOption();
				coordtemp.X++;
				SetConsoleCursorPosition(_handle, coordtemp);
				//going up
				coordtemp.Y--;
				SetConsoleCursorPosition(_handle, coordtemp);
				//setting to yellow
				SetConsoleTextAttribute(_handle, textColorSelect);
				//print the current
				coordtemp.X--;
				SetConsoleCursorPosition(_handle, coordtemp);
				printOption();
				coordtemp.X++;
				SetConsoleCursorPosition(_handle, coordtemp);
			}
			else {//first line
				 //print the priviuse to green
				 DWORD wAttr = FOREGROUND_GREEN;//v
				SetConsoleTextAttribute(_handle, textColor);//v
				coordtemp.X--;
				SetConsoleCursorPosition(_handle, coordtemp);
				printOption();
				//return one right
				coordtemp.X++;
				SetConsoleCursorPosition(_handle, coordtemp);
				//going to last row
				coordtemp.Y = _position.getStartCord().Y + _data.size() ;//going to last
				SetConsoleCursorPosition(_handle, coordtemp);
				//setting to yellow
				SetConsoleTextAttribute(_handle, textColorSelect);
				//print the current
				coordtemp.X--;
				SetConsoleCursorPosition(_handle, coordtemp);
				printOption();
				coordtemp.X++;
				SetConsoleCursorPosition(_handle, coordtemp);

			}
			//printf("x\n");
			SetConsoleCursorPosition(_handle, coordtemp);
			break;

		case VK_DOWN:
			if (coordtemp.Y - _position.getStartCord().Y < _data.size()) {
				//color the previous line from yellow to green		
				SetConsoleTextAttribute(_handle, textColor);
				//move 1 place left
				coordtemp.X--;
				SetConsoleCursorPosition(_handle, coordtemp);
				//print the priviouse line
				printOption();
				//changing to yellow
				SetConsoleTextAttribute(_handle, textColorSelect);
				//going to next line
				coordtemp.Y = coordtemp.Y + 1;
				SetConsoleCursorPosition(_handle, coordtemp);
				//print the new current line
				printOption();
				//move back one place right
				coordtemp.X++;
				SetConsoleCursorPosition(_handle, coordtemp);
			}
			else { //coord2.Y == 4 ==last line

				//color the last line from yellow to green
				SetConsoleTextAttribute(_handle, textColor);
				//move one place left
				coordtemp.X--;
				SetConsoleCursorPosition(_handle, coordtemp);
				//print the priviouse line
				printOption();
				//return one place right
				coordtemp.X++;
				SetConsoleCursorPosition(_handle, coordtemp);
				//color first LINE TO YELLOW
				SetConsoleTextAttribute(_handle, textColorSelect);
				//going to first line		
				coordtemp.Y = _position.getStartCord().Y + 1;
				//go one left
				coordtemp.X--;
				SetConsoleCursorPosition(_handle, coordtemp);
				printOption();
				//go beck one rigt
				coordtemp.X++;
				SetConsoleCursorPosition(_handle, coordtemp);
			}
			break;

		}
		if (c == 'f') { //finish- return chosing values
			vector <string> v = getChoosenData();
			SetConsoleCursorPosition(_handle, COORD{ 30,40 });
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << endl;
			}
		}
	}
}

void CheckList::mouseEvent(MOUSE_EVENT_RECORD mouseEvent) {
	if (_isComponetVisible == true) {	
			#ifndef MOUSE_HWHEELED
			#define MOUSE_HWHEELED 0x0008
			#endif

			if (!isPressOnMe(mouseEvent.dwMousePosition)) {
				return;
			}
			else {
				//printf("Mouse event: ");
				switch (mouseEvent.dwEventFlags)
				{
				case 0:
					if (mouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
					{
						firstMouseButtonPressed(mouseEvent);
					}
					else if (mouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
					{

						COORD mouseCoord = mouseEvent.dwMousePosition;


					}
					else
					{
						//printf("button press\n");
					}
					break;
				case DOUBLE_CLICK:
					//printf("double click\n");
					break;
				case MOUSE_HWHEELED:
					//printf("horizontal mouse wheel\n");
					break;
				case MOUSE_MOVED:
					//	printf("mouse moved\n");
					break;
				case MOUSE_WHEELED:
					//printf("vertical mouse wheel\n");
					break;
				default:
					//	printf("unknown\n");
					break;
				}

			}
	}
}

vector<string>  CheckList::getChoosenData() {
	int size = _data.size();
	vector<string> v;
	for (int i = 0; i < size; i++) {
		if (isDataChoosen[i]) {
			v.push_back(_data[i]);
		}
	}
	 size = v.size();
	for (int i = 0; i < size; i++) {
		v[i] = v[i].substr(4);
	}
	return v;
}
void CheckList::chooseOption(){
	try {

		if (isDataChoosen.at(coordtemp.Y - _position.getStartCord().Y - 1) == false) {
			DWORD selectedTextBcgColor = BACKGROUND_INTENSITY;
			SetConsoleTextAttribute(_handle, selectedTextBcgColor);
			coordtemp.X--;
			SetConsoleCursorPosition(_handle, coordtemp);
			cout << _data[coordtemp.Y - _position.getStartCord().Y - 1];
			SetConsoleCursorPosition(_handle, coordtemp);
			coordtemp.X++;
			SetConsoleCursorPosition(_handle, coordtemp);
			printf("x");
			SetConsoleCursorPosition(_handle, coordtemp);
			isDataChoosen[coordtemp.Y - _position.getStartCord().Y - 1] = true;
		}
		else {
			isDataChoosen.at(coordtemp.Y - _position.getStartCord().Y - 1) = false;
			printf(" ");
			SetConsoleCursorPosition(_handle, coordtemp);
		}
	}
	catch (out_of_range& oor) {
		//	cout << (mouseCoord.Y - _position.getStartCord().Y) << endl;
	}
}
void CheckList::printOption() {
	if (isDataChoosen[coordtemp.Y - _position.getStartCord().Y - 1]) {
		DWORD selectedTextBcgColor = BACKGROUND_INTENSITY;
		SetConsoleTextAttribute(_handle, selectedTextBcgColor);
	}
	cout << _data[coordtemp.Y - _position.getStartCord().Y - 1];
	//~check if there is X on priviouse line 
	if (isDataChoosen[coordtemp.Y - _position.getStartCord().Y - 1]) {
		coordtemp.X++;
		SetConsoleCursorPosition(_handle, coordtemp);
		cout << "x";
		coordtemp.X--;
		SetConsoleCursorPosition(_handle, coordtemp);
	}

}

void CheckList::firstMouseButtonPressed(MOUSE_EVENT_RECORD mouseEvent){
	//printf("right button press \n");
	COORD mouseCoord = mouseEvent.dwMousePosition;
	//onlt move in Y axis
	int yMousePositionIsOk = _position.getStartCord().X + 2;

	if (mouseCoord.X == yMousePositionIsOk) {

		//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(_handle, mouseCoord);

		try {

			if (isDataChoosen.at(mouseCoord.Y - _position.getStartCord().Y - 1) == false) {
				coordtemp.X = mouseCoord.X--;

				DWORD selectedTextBcgColor = BACKGROUND_INTENSITY;
				SetConsoleTextAttribute(_handle, selectedTextBcgColor);
				COORD tempCoord = mouseCoord;
				SetConsoleCursorPosition(_handle, tempCoord);
				cout << _data[mouseCoord.Y - _position.getStartCord().Y - 1];
				tempCoord.X++;
				SetConsoleCursorPosition(_handle, tempCoord);
				cout << ("x");
				isDataChoosen[mouseCoord.Y - _position.getStartCord().Y - 1] = true;


			}
			else {
				isDataChoosen.at(mouseCoord.Y - _position.getStartCord().Y - 1) = false;
				coordtemp.X = mouseCoord.X--;
				SetConsoleTextAttribute(_handle, _backgroundColor);
				COORD tempCoord = mouseCoord;
				SetConsoleCursorPosition(_handle, tempCoord);
				cout << _data[mouseCoord.Y - _position.getStartCord().Y - 1];
				tempCoord.X++;
				SetConsoleCursorPosition(_handle, tempCoord);
				cout << (" ");
			}
		}
		catch (out_of_range& oor) {
			//	cout << (mouseCoord.Y - _position.getStartCord().Y) << endl;
		}
		SetConsoleCursorPosition(_handle, mouseCoord);
	}

}

