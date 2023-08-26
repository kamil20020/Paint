#include "Kit.h"

Kit::Kit(shared_ptr <RenderWindow>& window, shared_ptr <Event> event, shared_ptr <Canvas> canvas1,
	Vector2f positions, Vector2f sizes, Color backgroundColor) :
	Container(window, event, positions, sizes, backgroundColor), canvas(canvas1) {

	createColorDropDownMenu();

	Vector2f putPositions(positions.x, 0);
	Vector2f putSizes(100, 50);

	buttons["Clear"] = make_shared <Button>(window, putPositions.x, putPositions.y, putSizes.x, putSizes.y,
		"OpenSans-Regular.ttf", "Clear");

	Vector2f putPositions1(positions.x + 100, 0);
	Vector2f putSizes1(100, 50);

	buttons["Save"] = make_shared <Button>(window, putPositions1.x, putPositions1.y, putSizes.x, putSizes.y,
		"OpenSans-Regular.ttf", "Save");
}

void Kit::eventsInEventLoopEvents() {

	map <string, shared_ptr <Button>>::iterator it;

	for (it = buttons.begin(); it != buttons.end(); it++) {

		it->second->events(*event);
	}
}

void Kit::eventsOutEventLoopEvents() {


}

void Kit::createColorDropDownMenu() {

	Vector2f positions(0, 0);
	Vector2f sizes(100, 50);

	//dropDownMenus["Kolory"] = make_shared <DropDownMenu>(window, event, positions, sizes, "Kolory");

	//shared_ptr <DropDownMenu> dropdownmenu = dropDownMenus["Kolory"];
}

void Kit::update() {

	window->draw(background);

	map <string, shared_ptr <Button>>::iterator it;

	for (it = buttons.begin(); it != buttons.end(); it++) {

		it->second->update();

		if (it->second->isButtonPressed()) {

			if (it->first == "Clear") {

				canvas->returnGraphics().clear();

				it->second->resetButton();
			}
			else if (it->first == "Save") {

				RenderTexture renderTexture;

				renderTexture.create(canvas->returnBackground().getSize().x, canvas->returnBackground().getSize().y);

				View view;
				view.setSize(canvas->returnBackground().getSize().x, canvas->returnBackground().getSize().y);
				view.setCenter(canvas->returnBackground().getPosition().x + canvas->returnBackground().getSize().x / 2, 
					canvas->returnBackground().getPosition().y + canvas->returnBackground().getSize().y / 2);

				renderTexture.setView(view);

				renderTexture.clear(canvas->returnBackground().getFillColor());

				renderTexture.draw(canvas->returnBackground());

				for (int i = 0; i < canvas->returnGraphics().size(); i++) {

					renderTexture.draw(*canvas->returnGraphics().at(i)->returnGraphic());
				}

				renderTexture.display();

				renderTexture.getTexture().copyToImage().saveToFile("test.png");
			}
		}
	}
}
