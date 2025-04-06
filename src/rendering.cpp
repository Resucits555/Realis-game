#include "general.h"

struct position;
struct cell;
//sf::Font calibri("../data/calibri.ttf");


static void DrawUI(UIObject UI) {
    if (UI.active) window.draw(UI.sprite);
}


void Render() {
    for (int y = 0; y < cellsY; y++) {
        for (int x = 0; x < cellsX; x++) {
            static const sf::RectangleShape stdCell({ cellSize, cellSize });
            if (!cells[y][x].element)
                continue;

            cell& thisCell = cells[y][x];
            sf::RectangleShape displayCell = stdCell;
            
            displayCell.setFillColor(elements[thisCell.element].color);
            displayCell.setPosition(sf::Vector2f(cellSize*x, cellSize*y));

            window.draw(displayCell);
        }
    }

    DrawUI(bottom);
    DrawUI(bigWindow);

    window.display();
}