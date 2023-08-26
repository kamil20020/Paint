#include <vector>
#include <memory>
#include <map>
#include <iostream>

#include "Button.h"

using namespace sf;
using namespace std;

class DropDownMenu {

    enum DropDownMenuStates { nonActive = 0, firstButtonActived, secondButtonActived };

    shared_ptr <Button> activeButton;

    map <string, shared_ptr <Button>> buttons;

    int actualState;

    float topDiffrence;

    shared_ptr <RenderWindow> window;

    shared_ptr <Event> event;

    shared_ptr <Button> clickedButton;

    public:

    DropDownMenu(shared_ptr <RenderWindow> window1, shared_ptr <Event> event1, Vector2f positions, Vector2f sizes, string title);

    void addButton(string title);

    map <string, shared_ptr <Button>> &returnButtons();

    shared_ptr <Button> getClickedButton();

    bool doDropDownMenuOpened();
    void close();

    void resetClickedButton();

    void update();

    void events(Event event);
};


