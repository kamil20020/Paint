#include "Canvas.h"

Canvas::Canvas(shared_ptr <RenderWindow>& window1, shared_ptr <Event> event1, Vector2f positions, Vector2f sizes, Color backgroundColor) :
	window(window1), event(event1) {

	background.setPosition(positions.x, positions.y);
	background.setSize(Vector2f(sizes.x, sizes.y));
	background.setFillColor(backgroundColor);

	crosshair = make_shared <CircleShape>();
	dynamic_pointer_cast <CircleShape> (crosshair)->setRadius(10);
	dynamic_pointer_cast <CircleShape> (crosshair)->setFillColor(Color::Green);

	helpingCrosshair = make_shared <CircleShape>();
	dynamic_pointer_cast <CircleShape> (helpingCrosshair)->setRadius(5);
	dynamic_pointer_cast <CircleShape> (helpingCrosshair)->setFillColor(Color::Black);

	showCrosshair = true;
}

void Canvas::eventsInEventLoopEvents() {

}

void Canvas::eventsOutEventLoopEvents() {

	if (event->type == Event::MouseMoved) {

		if (background.getGlobalBounds().contains(window->mapPixelToCoords(Mouse::getPosition(*window)))) {

			window->setMouseCursorVisible(false);

			showCrosshair = true;

			Vector2f mousePosition = window->mapPixelToCoords(Mouse::getPosition(*window));

			crosshair->setPosition(mousePosition.x - crosshair->getGlobalBounds().width / 2,
				mousePosition.y - crosshair->getGlobalBounds().height / 2);

			helpingCrosshair->setPosition(crosshair->getPosition().x + crosshair->getGlobalBounds().width / 2 - helpingCrosshair->getGlobalBounds().width / 2,
				crosshair->getPosition().y + crosshair->getGlobalBounds().height / 2 - helpingCrosshair->getGlobalBounds().height / 2);

			if (Mouse::isButtonPressed(Mouse::Left)) {

				createGraphic();

				//graphics.back()->setPosition(window->mapPixelToCoords(Mouse::getPosition(*window)));
			}
		}
		else {

			window->setMouseCursorVisible(true);

			showCrosshair = false;
		}
	}
}

void Canvas::createGraphic() {

    graphics.push_back(make_shared <Graphic>(window, crosshair));
}

shared_ptr <Shape> &Canvas::returnCrosshair() {

	return crosshair;
}

void Canvas::setCoursor(shared_ptr <Shape> shape) {

	crosshair = shape;
}

void Canvas::update() {

	window->draw(background);

	for (int i = 0; i < graphics.size(); i++) {

		graphics[i]->update();
	}

	if (showCrosshair == true) {

		window->draw(*crosshair);
		window->draw(*helpingCrosshair);
	}
}
