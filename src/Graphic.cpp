#include "Graphic.h"

Graphic::Graphic(shared_ptr <RenderWindow> &window1, shared_ptr <Shape> graphic1):
	window(window1){

	Vector2f positions(graphic1->getGlobalBounds().left, graphic1->getGlobalBounds().top);

	if (shared_ptr <Shape> (graphic1) == dynamic_pointer_cast<CircleShape>(graphic1)) {

		Vector2f positions(graphic1->getPosition().x, graphic1->getPosition().y);

		graphic = make_shared <CircleShape>();

		graphic->setPosition(positions);

		dynamic_pointer_cast <CircleShape> (graphic)->setRadius(dynamic_pointer_cast <CircleShape> (graphic1)->getRadius());

		graphic->setFillColor(graphic1->getFillColor());
	}
	else if(shared_ptr <Shape>(graphic1) == dynamic_pointer_cast<RectangleShape>(graphic1)) {

		graphic = make_shared <RectangleShape>();

		graphic->setPosition(positions);
		dynamic_pointer_cast <RectangleShape> (graphic)->setSize(dynamic_pointer_cast <RectangleShape> (graphic1)->getSize());
		graphic->setFillColor(graphic1->getFillColor());
	}
}

void Graphic::setSize(shared_ptr <RectangleShape>& shape, Vector2f sizes) {

	shape->setSize(sizes);
}

void Graphic::setSize(shared_ptr <CircleShape>& shape, float size) {

	shape->setRadius(size);
}

Vector2f Graphic::getSize(shared_ptr <RectangleShape> shape) {

	return shape->getSize();
}

float Graphic::getSize(shared_ptr <CircleShape> shape) {

	return shape->getRadius();
}

void Graphic::setPosition(Vector2f positions) {

	graphic->setPosition(positions);
}

void Graphic::setFillColor(Color color) {

	graphic->setFillColor(color);
}

void Graphic::update() {

	window->draw(*graphic);
}
