#include <SFML/Graphics.hpp>
#include <memory>
#include <map>

using namespace sf;
using namespace std;

class Button {

    protected:

    enum buttonState { withoutActivity = 0, buttonPressed, buttonHovered };

    RectangleShape rect;

    Font font;

    Text text;

    int actualState;

    shared_ptr <RenderWindow> window;

public:

    Button(shared_ptr <RenderWindow> window1, float x, float y, float width, float height, string fontSource, string message);

    template <class T>
    void drawShape(T graphic);

    void pushFont(string fontSource, string message);

    bool isButtonPressed();

    bool isButtonHovered();

    void resetButton();

    FloatRect getGlobalBounds();

    string getText();

    void update();

    void events(Event event);
};
