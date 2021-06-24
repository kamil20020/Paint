#include "SelectBox.h"

SelectBox::SelectBox(shared_ptr <RenderWindow>& window, shared_ptr <Event> event, shared_ptr <Canvas> canvas1,
	Vector2f positions, Vector2f sizes, Color backgroundColor) :
	Container(window, event, positions, sizes, backgroundColor), canvas(canvas1) {

	createColorDropDownMenu();
	createBrushStyles();
	createBrushSizes();
}

void SelectBox::createColorDropDownMenu() {

	Vector2f positions(0, 200);
	Vector2f sizes(100, 50);

	dropDownMenus["Kolory"] = make_shared <DropDownMenu>(window, event, positions, sizes, "Kolory");

	shared_ptr <DropDownMenu> dropdownmenu = dropDownMenus["Kolory"];

	dropdownmenu->addButton("Green");
	dropdownmenu->addButton("Red");
	dropdownmenu->addButton("Yellow");
	dropdownmenu->addButton("Black");
	dropdownmenu->addButton("White");
	dropdownmenu->addButton("Blue");
}

void SelectBox::setColor(string color) {

	if (color == "Green") {

		canvas->returnCrosshair()->setFillColor(Color::Green);
	}
	else if (color == "Red") {

		canvas->returnCrosshair()->setFillColor(Color::Red);
	}
	else if (color == "Yellow") {

		canvas->returnCrosshair()->setFillColor(Color::Yellow);
	}
	else if (color == "Black") {

		canvas->returnCrosshair()->setFillColor(Color::Black);
	}
	else if (color == "White") {

		canvas->returnCrosshair()->setFillColor(Color::White);
	}
	else if (color == "Blue") {

		canvas->returnCrosshair()->setFillColor(Color::Blue);
	}
}

void SelectBox::createBrushStyles() {

	Vector2f positions(0, 300);
	Vector2f sizes(100, 50);

	dropDownMenus["StylePedzla"] = make_shared <DropDownMenu>(window, event, positions, sizes, "Pedzel");

	shared_ptr <DropDownMenu> dropdownmenu = dropDownMenus["StylePedzla"];

	dropdownmenu->addButton("Circle");
	dropdownmenu->addButton("Rectangle");
}

void SelectBox::setBrushStyle(string brushStyle) {

	shared_ptr <Shape> shape;

	if (brushStyle == "Circle") {

		shape = make_shared <CircleShape>();
		dynamic_pointer_cast <CircleShape> (shape)->setRadius(10);
		dynamic_pointer_cast <CircleShape> (shape)->setFillColor(Color::Green);

		canvas->setCoursor(shape);
	}
	else if (brushStyle == "Rectangle") {

		shape = make_shared <RectangleShape>();
		dynamic_pointer_cast <RectangleShape> (shape)->setSize(Vector2f(20, 20));
		dynamic_pointer_cast <RectangleShape> (shape)->setFillColor(Color::Green);

		canvas->setCoursor(shape);
	}
}

void SelectBox::createBrushSizes() {

	Vector2f positions(0, 400);
	Vector2f sizes(100, 50);

	dropDownMenus["RozmiaryPedzla"] = make_shared <DropDownMenu>(window, event, positions, sizes, "Rozmiary");

	shared_ptr <DropDownMenu> dropdownmenu = dropDownMenus["RozmiaryPedzla"];

	dropdownmenu->addButton("Bigger");
	dropdownmenu->addButton("Smaller");
}

void SelectBox::changeBrushSize(float changeValue) {

	shared_ptr <CircleShape> circleCast = dynamic_pointer_cast <CircleShape> (canvas->returnCrosshair());
	shared_ptr <RectangleShape> rectCast = dynamic_pointer_cast <RectangleShape> (canvas->returnCrosshair());

	if (circleCast != nullptr) {

		circleCast->setRadius(circleCast->getRadius() + changeValue);
	}
	else if (rectCast != nullptr) {

		rectCast->setSize(Vector2f(rectCast->getSize().x + changeValue, rectCast->getSize().y + changeValue));
	}
}

void SelectBox::logicForBrushSize(string brushSizeChangeType) {

	if (brushSizeChangeType == "Bigger") {

		changeBrushSize(5);
	}
	else if (brushSizeChangeType == "Smaller") {

		changeBrushSize(-5);
	}
}

void SelectBox::eventsInEventLoopEvents() {

	map <string, shared_ptr <Button>>::iterator it;

	for (it = buttons.begin(); it != buttons.end(); it++) {

		it->second->events(*event);
	}

	map <string, shared_ptr <DropDownMenu>>::iterator it1;

	for (it1 = dropDownMenus.begin(); it1 != dropDownMenus.end(); it1++) {

		it1->second->events(*event);

		if (it1->second->doDropDownMenuOpened() && clickedDropDownMenu != it1->second) {

			if (clickedDropDownMenu != nullptr) {

				clickedDropDownMenu->close();
			}

			clickedDropDownMenu = it1->second;
		}
	}
}

void SelectBox::update() {

	window->draw(background);

	map <string, shared_ptr <DropDownMenu>>::iterator it;

	for (it = dropDownMenus.begin(); it != dropDownMenus.end(); it++) {

		it->second->update();

		if (it->second->getClickedButton() != nullptr) {

			if (it->first == "Kolory") {

				setColor(it->second->getClickedButton()->getText());

				it->second->resetClickedButton();
			}
			else if (it->first == "StylePedzla") {

				setBrushStyle(it->second->getClickedButton()->getText());

				it->second->resetClickedButton();
			}
			else if (it->first == "RozmiaryPedzla") {

				logicForBrushSize(it->second->getClickedButton()->getText());

				it->second->resetClickedButton();
			}
		}
	}
}