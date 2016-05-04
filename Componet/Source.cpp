#include <iostream>
#include "Component.h"
#include "Label.h"
#include "CheckList.h"
#include "ComponentObserver.h"
#include "RadioList.h"
#include "TextBox.h"
#include "ComboBox.h"
using namespace std;


int main()
{
	vector <string> data;
	data.push_back("option A");
	data.push_back("option B");
	data.push_back("option C");
	data.push_back("option D");
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	// *component = new Label(COORD{ 3,2 }, 0, 0, h, "hellew nice to meet you go home..");
	//component->draw();
	
	//Component *component2 = new Label(COORD{ 10,10 }, 0, 0, h, "hellew nice to meet you go home..");
	//component2->draw();
	ComponentObserver observer;
	DWORD textColor = FOREGROUND_GREEN;
	//DWORD wAttr2 = BACKGROUND_BLUE;
	Component *comp3 = new CheckList(COORD{20,20 }, textColor, BACKGROUND_BLUE, h, data, 10, 20);

	//Component *comp3 = new ComboBox(COORD{ 2,3 }, textColor, BACKGROUND_BLUE,h, "hello", data);
	//ComboBox(COORD coord, DWORD backgroundColor, DWORD textColor, HANDLE handle, string text, vector <string> data)
	//
	//Component *comp3 = new TextBox(COORD{ 2,3 }, textColor, BACKGROUND_RED, h, 20);
//	Component *comp4 = new RadioList(COORD{ 15,15 }, textColor, BACKGROUND_BLUE, h, data, 10, 20);
	
	comp3->draw();
	//comp3->hide();
	//comp4->draw();
	observer.addObserver(comp3);
//	observer.addObserver(comp4);

	observer.listen();
}