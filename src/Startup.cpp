#include <SFML/Graphics.hpp>
#include "general.h"
#include "configuration.h"


const ushort cellsX = 100;
ushort cellsY = 0; //Do not change

float cellSize = 6;

cell** cells = nullptr;

std::vector<element> elements{ { "none" },
    { "sand", sf::Color::Yellow, (sbyte)255, POWDER },
    { "test", sf::Color::Blue, (sbyte)255, POWDER } };

unsigned char formSelected = 0;


sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({ resolution.x, resolution.y }), "Reagen");

void Startup() {
    window.setFramerateLimit(fpsLimit);
    window.setKeyRepeatEnabled(false);

    cellSize = (resolution.x - 100.f) / cellsX;
    cellsY = cellsX / 2.1f;

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

    mainWindow.sprite.setScale({ 6.f, 6.f });
    mainWindow.sprite.setPosition({ 78, 78 });
    mainWindow.sprite.setTextureRect(sf::IntRect({ 0, 20 }, { 292, 129 }));
}