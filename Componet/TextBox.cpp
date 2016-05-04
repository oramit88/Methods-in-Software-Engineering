#include "TextBox.h"

void TextBox::keyEvent(KEY_EVENT_RECORD keyEvent) {
	static int counter = 0;
	counter++;
	if (counter % 2 == 0) {
		return;
	}

	char c = keyEvent.uChar.AsciiChar;
	if (c == 'p') {
		SetConsoleCursorPosition(_handle, COORD{ 10,10 });
		cout << _text << endl;
		SetConsoleCursorPosition(_handle, position);
	}

	if (textSize < maxSize) {
		if (c >= ' ' && c <= '~' ) {
		cout << c;
		_text+=c;
		position.X++;
		textSize++;
		}
	}
	switch (keyEvent.wVirtualKeyCode) {
	case VK_RIGHT: {
		if (position.X < maxSize+2) {
			position.X++;
			SetConsoleCursorPosition(_handle, position);
		}
		break;
	}
	case VK_LEFT: {
		COORD startCord = _position.getStartCord();
		startCord.X++;
		if (position.X > startCord.X) {
			position.X--;
			SetConsoleCursorPosition(_handle, position);
		}
		break;
	}
	case VK_BACK: {
		COORD startCord = _position.getStartCord();
		startCord.X++;
		if (position.X > startCord.X) {
			_text.pop_back();
			position.X--;
			SetConsoleCursorPosition(_handle, position);
			cout << " ";
			SetConsoleCursorPosition(_handle, position);
		}
		break;
	}
	}
}

//void TextBox::mouseEvent(MOUSE_EVENT_RECORD mouseEvent) {

//}
vector<string> TextBox::getChoosenData() {
	vector<string> v;
	v.push_back(_text);
	return v;
}

void TextBox::draw() {
	//SetConsoleTextAttribute(_handle, _textColor | _backgroundColor);
	Component::draw();
	cout << _text << endl;
	//position.Y++;
	position.X += _text.size();
	SetConsoleCursorPosition(_handle, position);

}

void TextBox::mouseEvent(MOUSE_EVENT_RECORD mouseEvent){

#ifndef MOUSE_HWHEELED
#define MOUSE_HWHEELED 0x0008
#endif

	switch (mouseEvent.dwEventFlags)
	{
	case 0:

		if (mouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			COORD mouseCoord = mouseEvent.dwMousePosition;
			int myPosi = _position.getStartCord().X + 1;
			if (mouseCoord.X - myPosi >-1 & maxSize - mouseCoord.X>-3) {
				SetConsoleCursorPosition(_handle, mouseCoord);
			}
		}
		else if (mouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
		{
			
		}
		else
		{

		}
		break;
	case DOUBLE_CLICK:
		
		break;
	case MOUSE_HWHEELED:
		
		break;
	case MOUSE_MOVED:
		
		break;
	case MOUSE_WHEELED:
		
		break;
	default:
		
		break;
	}
}

void TextBox::hide() {

}




TextBox::~TextBox()
{
}
