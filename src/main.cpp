#include "general.h"


static void clearSave() {
    for (int x = 0; x < cellsX; x++) {
        for (int y = 0; y < cellsY; y++) {
            cells[y][x] = {};
        }
    }
}



int main()
{
    Startup();

    while (window.isOpen())
    {
        window.clear();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            /*else if (const auto* input = event->getIf<sf::Event::TextEntered>()) {    Use this for text input
                const char typed = static_cast<char>(input->unicode);

            }*/
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                switch (keyPressed->scancode) {
                    case sf::Keyboard::Scancode::Tab:
                        if (formSelected < 2)
                            formSelected++;
                        else
                            formSelected = 0;
                        break;
                    case sf::Keyboard::Scancode::C:
                        clearSave();
                        goto skipCells;
                    case sf::Keyboard::Scancode::Escape:
                        if (mainWindow.active)
                            mainWindow.active = false;
                        else {
                            window.close();
                            goto skipCells;
                        }
                        break;
                }
            }
            else if (const auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mousePressed->button == sf::Mouse::Button::Left) {
                    Draw(1);
                    sf::Vector2i _ = sf::Mouse::getPosition(window);
                    position mousePos = { (ushort)_.x, (ushort)_.y };
                    ProcessUI(mousePos);
                }
                if (mousePressed->button == sf::Mouse::Button::Right)
                    Draw(1);
            }
            else if (const auto* mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
                if (mouseReleased->button == sf::Mouse::Button::Left)
                    Draw(2);
                else if (mouseReleased->button == sf::Mouse::Button::Right)
                    Draw(3);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || 
            sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (mousePosition.x > 0 && mousePosition.y > 0)
                Draw(0);
        }

        ProcessCells();
        skipCells:
        Render();
    }

    for (ushort y = 0; y < cellsY; y++)
        delete cells[y];
    delete cells;
}