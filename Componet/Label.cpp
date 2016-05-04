#include "Label.h"


void Label::keyEvent(KEY_EVENT_RECORD keyEvent) {

}
void Label::mouseEvent(MOUSE_EVENT_RECORD mouseEvent) {

}
void Label::draw() {
	_position.setHeight(3);
	int strSize = _text.size();
	_position.setWidth(strSize + 2);
	Component::draw();
	//SetConsoleCursorPosition(_handle, _position.getStartCord());

	CONSOLE_CURSOR_INFO cci = { 100, TRUE };
	SetConsoleCursorInfo(_handle, &cci);
	//SetConsoleTextAttribute(_handle, _textColor);
	cout << _text << endl;

}
void Label::hide() {

}

Label::~Label()
{

}
