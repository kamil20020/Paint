#pragma once

#include <vector>
#include <memory>
#include <map>
#include <iostream>

#include "DropDownMenu.h"

using namespace sf;
using namespace std;

class Container{

	protected:

	shared_ptr <RenderWindow> window;
	shared_ptr <Event> event;

	RectangleShape background;

	FloatRect importantPlace;

	map <string, shared_ptr <Button>> buttons;

	map <string, shared_ptr <DropDownMenu>> dropDownMenus;

	public:

	Container(shared_ptr <RenderWindow>& window1, shared_ptr <Event> event1, Vector2f positions, Vector2f sizes, Color backgroundColor);

	virtual void eventsInEventLoopEvents();

	virtual void eventsOutEventLoopEvents() {};

	virtual void update();
};

