#include <iostream>
#include "Component.h"
#include "Label.h"
#include "CheckList.h"
#include "ComponentObserver.h"
#include "RadioList.h"
#include "TextBox.h"
#include "ComboBox.h"
using namespace std;

/*
Uncoment cases to test the Components!!
*/
int main()
{
	vector <string> data;
	data.push_back("option A");
	data.push_back("option B");
	data.push_back("option C");
	data.push_back("option D");
	ComponentObserver observer;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD backgroudBlue = BACKGROUND_BLUE;
	DWORD backgroudBlack = 0;
	DWORD backgrounRed = BACKGROUND_RED;
	DWORD textColor = FOREGROUND_RED;
	DWORD foregroundGreen = FOREGROUND_GREEN;
	DWORD foregrounBlue = FOREGROUND_BLUE;


	/*
	Uncoment cases to test the Components!!
	*/

	Component *chekList = new CheckList(COORD{ 5,5 }, textColor, 0, h, data, 6, 14);
	chekList->draw();
	observer.addObserver(chekList);
	
	
	
	// case label
	/*
	Component *label = new Label(COORD{ 5,5 }, 0, foregroundGreen, h, "Hello world!");
	label->draw();
	observer.addObserver(label);
	*/

	// case textBoc
	/*
	Component *textBox = new TextBox(COORD{ 5,5 }, backgrounRed, FOREGROUND_BLUE, h, 20);
	textBox->draw();
	observer.addObserver(textBox);
	*/

	

	//case RadioList
	/*
	Component *radioList = new RadioList(COORD{ 5,5 }, textColor, 0, h, data, 6, 14);
	radioList->draw();
	observer.addObserver(radioList);
	*/

	//case  ComboBox
	//press on the combo box in order to see the options list.
	//after you choose the option' press on the comboBox again
	/*
	Component *comboBox = new ComboBox(COORD{ 5,5 }, textColor, 0,h, "hello", data);
	comboBox->draw();
	observer.addObserver(comboBox);
	*/

	observer.listen();


}