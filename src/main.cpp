#include "general.h"


static void ProcessObjects() {
    for (int i = 0; i < objects.size(); i++) {
        object& thisObject = objects[i];

        if (thisObject.linVelocity.y < 127)
            thisObject.linVelocity.y += 1;
    }
}


std::vector<element> elements{ { "none" },
    { "elem", sf::Color::Yellow, POWDER } }; //[testing element]
unsigned char formSelected = 0;


int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({ 1920u, 980u }), "CMake SFML Project");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);


    while (window.isOpen())
    {
        window.clear(sf::Color::Black);

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            /*else if (const auto* input = event->getIf<sf::Event::TextEntered>()) { //Use for text input
                const char typed = static_cast<char>(input->unicode);

            }*/
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                switch (keyPressed->scancode) {
                    case sf::Keyboard::Scancode::C:
                        if (formSelected < 2)
                            formSelected++;
                        else
                            formSelected = 0;
                        break;
                }
            }
            else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left ||
                    mousePressed->button == sf::Mouse::Button::Right)
                    Draw(window, 1);
            }
            else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonReleased>()) {
                if (mousePressed->button == sf::Mouse::Button::Left)
                    Draw(window, 2);
                else if (mousePressed->button == sf::Mouse::Button::Right)
                    Draw(window, 3);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || 
            sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (mousePosition.x > 0 && mousePosition.y > 0)
                Draw(window, 0);
        }

        ProcessObjects();
        ProcessCells();
        Render(window);
    }
}