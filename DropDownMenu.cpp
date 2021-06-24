#include "DropDownMenu.h"

DropDownMenu::DropDownMenu(shared_ptr <RenderWindow> window1, shared_ptr <Event> event1, Vector2f positions, 
    Vector2f sizes, string title): window(window1), event(event1){

    activeButton = make_shared <Button>(window, positions.x, positions.y,
                                        sizes.x, sizes.y, "OpenSans-Regular.ttf", title);

    topDiffrence = positions.y;

    actualState = nonActive;

    clickedButton = nullptr;
}

void DropDownMenu::addButton(string title) {

    FloatRect activeButtonGlobalBounds = activeButton->getGlobalBounds();

    buttons[title] = make_shared <Button>(window, activeButtonGlobalBounds.left + activeButtonGlobalBounds.width, topDiffrence,
        activeButtonGlobalBounds.width, activeButtonGlobalBounds.height, "OpenSans-Regular.ttf", title);

    topDiffrence = topDiffrence + activeButtonGlobalBounds.height;
}

map <string, shared_ptr <Button>> & DropDownMenu::returnButtons(){

    return buttons;
}

bool DropDownMenu::doDropDownMenuOpened() {

    if (actualState == firstButtonActived) {

        return true;
    }

    return false;
}

void DropDownMenu::events(Event event){

    if (activeButton->isButtonPressed()) {

        actualState = firstButtonActived;

        activeButton->resetButton();
    }
    else {

        activeButton->events(event);
    }

    if (actualState == firstButtonActived) {

        if (!activeButton->isButtonPressed()) {

            map <string, shared_ptr <Button>>::iterator it;

            for (it = buttons.begin(); it != buttons.end(); it++) {

                it->second->events(event);

                if (it->second->isButtonPressed()) {

                    clickedButton = it->second;

                    break;
                }
            }
        }
        else {

            actualState = nonActive;

            activeButton->resetButton();
        }
    }
}

void DropDownMenu::resetClickedButton() {

    clickedButton->resetButton();

    clickedButton = nullptr;
}

shared_ptr <Button> DropDownMenu::getClickedButton() {

    return clickedButton;
}

void DropDownMenu::close() {

    clickedButton = nullptr;

    actualState = nonActive;
}

void DropDownMenu::update(){

    activeButton->update();

    if (actualState == firstButtonActived) {

        map <string, shared_ptr <Button>>::iterator it;

        for (it = buttons.begin(); it != buttons.end(); it++) {

            it->second->update();
        }
    }
}


