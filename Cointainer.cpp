#include "Container.h"

Container::Container(shared_ptr <RenderWindow> &window1, shared_ptr <Event> event1, 
	Vector2f positions, Vector2f sizes, Color backgroundColor): window(window1), event(event1){

	background.setPosition(positions.x, positions.y);
	background.setSize(Vector2f(sizes.x, sizes.y));
	background.setFillColor(backgroundColor);
}

void Container::eventsInEventLoopEvents() {

	map <string, shared_ptr <Button>>::iterator it;

	for (it = buttons.begin(); it != buttons.end(); it++) {

		it->second->events(*event);
	}

	map <string, shared_ptr <DropDownMenu>>::iterator it1;

	for (it1 = dropDownMenus.begin(); it1 != dropDownMenus.end(); it1++) {

		it1->second->events(*event);
	}
}

void Container::update() {

	map <string, shared_ptr <Button>>::iterator it;

	for (it = buttons.begin(); it != buttons.end(); it++) {

		it->second->update();
	}

	map <string, shared_ptr <DropDownMenu>>::iterator it1;

	for (it1 = dropDownMenus.begin(); it1 != dropDownMenus.end(); it1++) {

		it1->second->update();
	}
}