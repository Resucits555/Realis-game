#include "general.h"
#include "math.h"

//TODO: fix mark deleting types

static sf::Vector2f start;

static void DrawRect(unsigned char type, sf::Vector2f& max, sf::Vector2f& min) {
	for (unsigned short y = min.y; y < max.y; y++) {
		for (unsigned short x = min.x; x < max.x; x++) {
			cells[y][x] = { {x, y} , type, (unsigned char)objects.size()};
		}
	}
}



std::vector<object> objects;

void Draw(sf::RenderWindow& window, unsigned char mouseEvent) {
	sf::Vector2f mouseCellPos = {sf::Mouse::getPosition(window).x / cellSize,
						         sf::Mouse::getPosition(window).y / cellSize };

	sf::Vector2f max = { std::max(start.x, mouseCellPos.x), std::max(start.y, mouseCellPos.y) };
	sf::Vector2f min = { std::min(start.x, mouseCellPos.x), std::min(start.y, mouseCellPos.y) };

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
			objects.push_back({ {0, 0} });
			DrawRect(1, max, min);
			break;
	}
}