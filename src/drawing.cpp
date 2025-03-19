#include "general.h"
#include "math.h"


static sf::Vector2f start;

static void DrawRect(ubyte elem, sf::Vector2f& max, sf::Vector2f& min) {
    for (ushort y = min.y; y < max.y; y++) {
        for (ushort x = min.x; x < max.x; x++) {
            cell& thisCell = cells[y][x];
            thisCell.element = elem;
            thisCell.origin = { x, y };
            thisCell.state = elements[elem].spawnState;
        }
    }
}



ubyte elemSelected = 1;

void Draw(ubyte mouseEvent) {
    sf::Vector2f mouseCellPos = {sf::Mouse::getPosition(window).x / cellSize,
                                 sf::Mouse::getPosition(window).y / cellSize };

    sf::Vector2f max = { std::max(start.x, mouseCellPos.x), std::max(start.y, mouseCellPos.y) };
    sf::Vector2f min = { std::min(start.x, mouseCellPos.x), std::min(start.y, mouseCellPos.y) };
    if (max.x > cellsX)
        max.x = cellsX;
    if (max.y > cellsY)
        max.y = cellsY;

    switch (mouseEvent) {
        case 0:
            switch (formSelected) {
                case 0:
                    //TODO: Make this work better
                    sf::RectangleShape mark({std::ceil(max.x - min.x) * cellSize,
                                             std::ceil(max.y - min.y) * cellSize});
                    mark.setPosition({ std::floor(min.x) * cellSize, std::floor(min.y) * cellSize });
                    window.draw(mark);
                    break;
            }
            break;

        case 1:
            start = mouseCellPos;
            break;

        case 2:
            DrawRect(elemSelected, max, min);
            break;
        case 3:
            DrawRect(0, max, min);
            break;
    }
}