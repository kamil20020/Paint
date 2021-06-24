#include <iostream>

#include "Button.h"

Button::Button(shared_ptr <RenderWindow> window1, float x, float y, float width, float height, string fontSource, string message) {

    window = window1;

    rect.setSize(Vector2f(width, height));
    rect.setPosition(x, y);
    rect.setFillColor(Color::White);

    pushFont(fontSource, message);

    actualState = withoutActivity;
}

template <class T>
void Button::drawShape(T graphic) {

    window->draw(graphic);
}

void Button::pushFont(string fontSource, string message) {

    font.loadFromFile(fontSource);

    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(22);
    text.setFillColor(Color::Black);
    text.setPosition(rect.getPosition().x + rect.getSize().x / 2 - text.getGlobalBounds().width / 2 - 1, 
        rect.getPosition().y + rect.getSize().y / 2 - text.getGlobalBounds().height / 2 - 5);
}

string Button::getText() {

    return text.getString();
}

void Button::update() {

    drawShape(rect);
    drawShape(text);
}

void Button::events(Event event) {

    if (rect.getGlobalBounds().contains(Mouse::getPosition(*window).x, Mouse::getPosition(*window).y) == true) {

        actualState = buttonHovered;

        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

            actualState = buttonPressed;

            cout << 1;
        }
    }
    else {

        actualState = withoutActivity;
    }
}

FloatRect Button::getGlobalBounds() {

    return rect.getGlobalBounds();
}

void Button::resetButton() {

    actualState = withoutActivity;
}

bool Button::isButtonPressed() {

    if (actualState == buttonPressed) {

        return true;
    }

    return false;
}

bool Button::isButtonHovered() {

    if (actualState == buttonHovered) {

        return true;
    }

    return false;
}
