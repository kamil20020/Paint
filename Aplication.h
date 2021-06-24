#pragma once

#include <vector>
#include <memory>
#include <map>
#include <iostream>

#include "Container.h"
#include "Canvas.h"

using namespace sf;
using namespace std;

class Aplication{

	shared_ptr <RenderWindow> window;
	shared_ptr <Event> event;

	shared_ptr <Canvas> canvas;

	vector <shared_ptr <Container>> containers;

	public:

	Aplication();

	void createCointainers();

	void eventsInEventLoopEvents();

	void eventsOutEventLoopEvents();

	void aplicationLoop();

	void update();

};

