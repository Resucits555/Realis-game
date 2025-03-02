#include "general.h"

struct position;
struct cell;
cell cells[cellsY][cellsX];
static const sf::RectangleShape stdCell({cellSize, cellSize});


void Render(sf::RenderWindow& window) {
	for (int y = 0; y < cellsY; y++) {
		for (int x = 0; x < cellsX; x++) {
			if (!cells[y][x].type)
				continue;

			cell& thisCell = cells[y][x];
			sf::RectangleShape displayCell = stdCell;
			
			displayCell.setFillColor(elements[thisCell.type].color);
			displayCell.setPosition(sf::Vector2f(cellSize*x, cellSize*y));

			window.draw(displayCell);
		}
	}

	window.display();
}