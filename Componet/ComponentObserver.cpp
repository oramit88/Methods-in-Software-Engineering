#include "ComponentObserver.h"



ComponentObserver::ComponentObserver()
{

}


ComponentObserver::~ComponentObserver()
{

}

void ComponentObserver::notifiyObserversKeyEvent(KEY_EVENT_RECORD keyEvent) {
	int size = observers.size();
	for (int i = 0; i < size; i++) {
		observers[i]->keyEvent(keyEvent); // need to change
	}
}
void ComponentObserver::notifiyObserversMouseEvent(MOUSE_EVENT_RECORD mouseEvent) {
	int size = observers.size();
	for (int i = 0; i < size; i++) {
		observers[i]->mouseEvent(mouseEvent);
	}
}
void ComponentObserver::listen() {


	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");

	// Save the current input mode, to be restored on exit. 

	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ErrorExit("GetConsoleMode");

	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(hStdin, fdwMode))
		ErrorExit("SetConsoleMode");

	// Loop to read and handle the next 100 input events. 
	int counter = 0;
	INPUT_RECORD irInBuf[256];

	while (counter++ <= 900)//Change - TO DO
	{
		// Wait for the events. 

		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			256,         // size of read buffer 
			&cNumRead)) // number of records read 
			ErrorExit("ReadConsoleInput");

		// Dispatch the events to the appropriate handler. 

		for (int i = 0; i < cNumRead; i++)
		{

			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
				notifiyObserversKeyEvent(irInBuf[i].Event.KeyEvent);

				break;

			case MOUSE_EVENT: // mouse input 
				if (irInBuf[i].Event.MouseEvent.dwEventFlags == 0) { //if pressing the mouse buttons
					notifiyObserversMouseEvent(irInBuf[i].Event.MouseEvent);
				}
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				//ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
				break;

			case FOCUS_EVENT:  // disregard focus events 

			case MENU_EVENT:   // disregard menu events 
				break;

			default:
				ErrorExit("Unknown event type");
				break;
			}
		}
	}

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

}





VOID ComponentObserver::ErrorExit(LPSTR lpszMessage)
{
	fprintf(stderr, "%s\n", lpszMessage);

	// Restore input mode on exit.

	SetConsoleMode(hStdin, fdwSaveOldMode);

	ExitProcess(0);
}