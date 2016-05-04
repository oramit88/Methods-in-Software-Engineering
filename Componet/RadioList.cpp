
#include "RadioList.h"



void RadioList::printOption() {
	
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
void RadioList::chooseOption() {
	try {

		if (isDataChoosen.at(coordtemp.Y - _position.getStartCord().Y - 1) == false) {
			int size = isDataChoosen.size();
			for (int i = 0; i < size; i++) {
				isDataChoosen[i] = false;
			}
			COORD temp = coordtemp;
			CheckList::draw();
			SetConsoleCursorPosition(_handle, temp);
			////////////////////////////////////////////////////////////////or amit
			DWORD selectedTextBcgColor = BACKGROUND_INTENSITY;
			SetConsoleTextAttribute(_handle, selectedTextBcgColor);
			coordtemp.X--;
			SetConsoleCursorPosition(_handle, coordtemp);
			cout << _data[coordtemp.Y - _position.getStartCord().Y - 1];
			
			SetConsoleCursorPosition(_handle, coordtemp);
			coordtemp.X++;
			SetConsoleCursorPosition(_handle, coordtemp);
			printf("x");

			//SetConsoleCursorPosition(_handle, coordtemp);
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





void RadioList::firstMouseButtonPressed(MOUSE_EVENT_RECORD mouseEvent) {
	//printf("right button press \n");
	COORD mouseCoord = mouseEvent.dwMousePosition;
	//onlt move in Y axis
	int yMousePositionIsOk = _position.getStartCord().X + 2;

	if (mouseCoord.X == yMousePositionIsOk) {
		//cout << "test";
		//HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(_handle, mouseCoord);

		try {

			if (isDataChoosen.at(mouseCoord.Y - _position.getStartCord().Y - 1) == false) {
				draw();
							int size = isDataChoosen.size();
			for (int i = 0; i < size; i++) {
				isDataChoosen[i] = false;
			}
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
				//	DWORD selectedTextBcgColor = _textColor;
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

RadioList::~RadioList()
{
}
