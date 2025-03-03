#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

extern void ProcessCells();

extern void Render(sf::RenderWindow&);

extern void Draw(sf::RenderWindow&, unsigned char);
extern unsigned char formSelected;
extern unsigned char typeSelected;


struct position {
	unsigned short x;
	unsigned short y;
};

struct vector2s {
	signed short x;
	signed short y;
	/*vector2s add(vector2s addend) {
		return {(short)(x + addend.x), (short)(y + addend.y)};
	}*/
};


enum states {
	SOLID,
	LIQUID,
	GAS,
	POWDER
};


struct element {
	char name[8];
	sf::Color color;
	unsigned char spawnState;
	unsigned char mass;
	//unsigned char elasticity;
	//unsigned char hardness;
};

extern std::vector<element> elements;



struct cell {
	position origin;
	vector2s pos;
	unsigned char type;
	unsigned char state;
	unsigned short myobject;
	vector2s linVelocity;
};

const unsigned short cellsX = 40, cellsY = 20;
extern cell cells[cellsY][cellsX];
const float cellSize = 40.0f;



struct object {
	vector2s linVelocity;
};

extern std::vector<object> objects;