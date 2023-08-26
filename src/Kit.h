#pragma once

#include <vector>
#include <memory>
#include <map>
#include <iostream>

#include "Container.h"
#include "Canvas.h"

using namespace sf;
using namespace std;

class Kit: public Container{

	shared_ptr <Canvas> canvas;

	map <string, shared_ptr <Button>> buttons;

public:

	Kit(shared_ptr <RenderWindow>& window, shared_ptr <Event> event, shared_ptr <Canvas> canvas,
		Vector2f positions, Vector2f sizes, Color backgroundColor);

	void eventsInEventLoopEvents();

	void eventsOutEventLoopEvents();

	void createColorDropDownMenu();

	void update();
};

