#include "Combobox.h"


ComboBox::~ComboBox()
{
}

void ComboBox::hide() {
	Label::hide();
	if (list->isComponetVisible()) {
		list->hide();
	}
}
void ComboBox::keyEvent(KEY_EVENT_RECORD keyEvent) {
		if (list->isComponetVisible()) {
			list->keyEvent(keyEvent);
		}
}
void ComboBox::mouseEvent(MOUSE_EVENT_RECORD mouseEvent) {
	static int counter = 0;
	counter++;
	if (counter % 2 == 0) {
		return;
	}
	if (isPressOnMe(mouseEvent.dwMousePosition)) {
			if (!list->isComponetVisible()) {
				list->draw();
			}
			else {
				output = list->getChoosenData();
				if (output.size() == 1) {
					_text = output[0];

				}
			list->hide();
			hide();
			draw();
		}
	}
	if (list->isPressOnMe(mouseEvent.dwMousePosition)) {
		list->mouseEvent(mouseEvent);
	}
}