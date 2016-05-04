#pragma once
#include "Component.h"

class ComponentObserver
{
	vector<Component*> observers;
	DWORD fdwSaveOldMode, fdwMode, cNumRead;
	HANDLE hStdin;
	VOID ErrorExit(LPSTR);
	void notifiyObserversKeyEvent(KEY_EVENT_RECORD keyEvent);
	void notifiyObserversMouseEvent(MOUSE_EVENT_RECORD mouseEvent);
public:
	void addObserver(Component *component) { observers.push_back(component); }
	//void removeObserver(Component &component));
	void listen();
	ComponentObserver();
	~ComponentObserver();
};

