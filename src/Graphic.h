#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

using namespace sf;
using namespace std;

class Graphic{

	shared_ptr <RenderWindow> window;

	Texture texture;

public:

	shared_ptr <Shape> graphic;

	public:

	Graphic(shared_ptr <RenderWindow> &window1, shared_ptr <Shape> graphic1);

	void setSize(shared_ptr <RectangleShape>& shape, Vector2f sizes);
	void setSize(shared_ptr <CircleShape>& shape, float size);

	Vector2f getSize(shared_ptr <RectangleShape> shape);
	float getSize(shared_ptr <CircleShape> shape);

	void setPosition(Vector2f positions);
	void setFillColor(Color color);

	shared_ptr <Shape> &returnGraphic() { return graphic; }

	void update();

};

