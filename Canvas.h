#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <map>
#include <iostream>

#include "Graphic.h"

using namespace sf;
using namespace std;

class Canvas{

	shared_ptr <RenderWindow> window;
	shared_ptr <Event> event;

	RectangleShape background;

	shared_ptr <Shape> crosshair;
	shared_ptr <Shape> helpingCrosshair;

	Texture texture;

	bool showCrosshair;

	vector <shared_ptr<Graphic> > graphics;

public:

	Canvas(shared_ptr <RenderWindow>& window1, shared_ptr <Event> event1, Vector2f positions, Vector2f sizes, Color backgroundColor);

	void setCoursor(shared_ptr <Shape> shape);

	shared_ptr <Shape> &returnCrosshair();
	vector <shared_ptr<Graphic> > &returnGraphics() { return graphics; }
	RectangleShape returnBackground() { return background; }

	void createGraphic();

	void eventsInEventLoopEvents();
	void eventsOutEventLoopEvents();

	void update();
};

