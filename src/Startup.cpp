#include <SFML/Graphics.hpp>
#include "general.h"
#include "configuration.h"


ushort cellsY = 0;
float cellSize = 6;

cell** cells = nullptr;

std::vector<element> elements{ { "none" },
    { "sand", sf::Color::Yellow, 200, POWDER },
    { "test", sf::Color::Blue, 200, POWDER } };

unsigned char formSelected = 0;

sf::RenderWindow window;

void Startup() {
    window = sf::RenderWindow(sf::VideoMode({ resolution.x, resolution.y }), "Reagen");
    window.setFramerateLimit(fpsLimit);
    window.setKeyRepeatEnabled(false);

    cellSize = (resolution.x - 100.f) / cellsX;
    cellsY = cellsX / 2.1f;
    std::cout << "cellsY: " << cellsY << '\n';

    cells = new cell* [cellsY];
    for (ushort y = 0; y < cellsY; y++)
        cells[y] = new cell[cellsX];

    for (ushort y = 0; y < cellsY; y++)
    {
        for (ushort x = 0; x < cellsX; x++)
        {
            cells[y][x] = {};
        }
    }

    bottom.sprite.setScale({ 3.f, 3.f });
    bottom.sprite.setPosition({ 5, 910 });
    bottom.sprite.setTextureRect(sf::IntRect({ 0, 0 }, { 637, 21 }));

    bigWindow.sprite.setScale({ 6.f, 6.f });
    bigWindow.sprite.setPosition({ 78, 78 });
    bigWindow.sprite.setTextureRect(sf::IntRect({ 0, 20 }, { 292, 129 }));
}