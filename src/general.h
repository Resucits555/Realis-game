#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

extern void ProcessCells();

extern void Render(sf::RenderWindow&);

extern void Draw(sf::RenderWindow&, unsigned char);
extern unsigned char formSelected;
extern unsigned char elementSelected;


struct position {
	unsigned short x;
	unsigned short y;
};

struct velocity {
	signed char x;
	signed char y;
};



struct element {
	char name[8];
	sf::Color color;

	//unsigned char mass;
	//unsigned char elasticity;
	//unsigned char hardness;
};

extern std::vector<element> elements;



struct cell {
	position origin;
	unsigned char type;
	unsigned char myobject;
};

const unsigned short cellsX = 60, cellsY = 20;
extern cell cells[cellsY][cellsX];
const float cellSize = 50.0f;



struct object {
	velocity linVelocity;
};

extern std::vector<object> objects;