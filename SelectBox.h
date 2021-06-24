#pragma once

#include <vector>
#include <memory>
#include <map>
#include <iostream>

#include "Container.h"
#include "Canvas.h"

using namespace sf;
using namespace std;

class SelectBox: public Container{

	shared_ptr <Canvas> canvas;

	shared_ptr <DropDownMenu> clickedDropDownMenu = nullptr;

	public:

	SelectBox(shared_ptr <RenderWindow>& window, shared_ptr <Event> event, shared_ptr <Canvas> canvas, 
		Vector2f positions, Vector2f sizes, Color backgroundColor);

	void createBrushStyles();
	void setBrushStyle(string brushStyle);

	void createColorDropDownMenu();
	void setColor(string color);

	void createBrushSizes();
	void changeBrushSize(float changeValue);
	void logicForBrushSize(string brushSizeChangeTypebool);

	void eventsInEventLoopEvents();

	void update();
};

