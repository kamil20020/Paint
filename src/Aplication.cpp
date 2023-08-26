#include "Aplication.h"

#include "SelectBox.h"
#include "Kit.h"

Aplication::Aplication() {

	window = make_shared <RenderWindow>();
	window->create(VideoMode(1200, 800), "Paint");
	//window->setFramerateLimit(100);

	event = make_shared <Event>();

	Vector2f positions(210, 150);
	Vector2f sizes(880, 600);

	canvas = make_shared <Canvas>(window, event, positions, sizes, Color::White);

	createCointainers();
}

void Aplication::createCointainers() {

	Vector2f positions(0, 0);
	Vector2f sizes(100, window->getSize().y);

	containers.push_back(make_shared <SelectBox>(window, event, canvas, positions, sizes, Color::Red));

	Vector2f positions1(100, 0);
	Vector2f sizes1(window->getSize().x - 100, 100);

	containers.push_back(make_shared <Kit>(window, event, canvas, positions1, sizes1, Color::Blue));
}

void Aplication::eventsInEventLoopEvents() {

	if (event->type == Event::Closed) {

		window->close();
	}

	if (event->type == Event::KeyPressed && event->key.code == Keyboard::Escape) {

		window->close();
	}

	canvas->eventsInEventLoopEvents();

	for (int i = 0; i < containers.size(); i++) {

		containers[i]->eventsInEventLoopEvents();
	}

}

void Aplication::eventsOutEventLoopEvents() {

	canvas->eventsOutEventLoopEvents();

	for (int i = 0; i < containers.size(); i++) {

		containers[i]->eventsOutEventLoopEvents();
	}
}

void Aplication::update() {

	canvas->update();

	for (int i = 0; i < containers.size(); i++) {

		containers[i]->update();
	}
}

void Aplication::aplicationLoop() {

	while (window->isOpen()) {

		while (window->pollEvent(*event)) {

			eventsInEventLoopEvents();
		}

		window->clear();

		eventsOutEventLoopEvents();

		update();

		window->display();
	}
}
