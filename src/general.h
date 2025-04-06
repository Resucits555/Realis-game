#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

typedef unsigned char ubyte;
typedef signed char sbyte;
typedef unsigned short ushort;

extern sf::RenderWindow window;


struct position {
    ushort x;
    ushort y;
};

struct vector2s {
    short x;
    short y;
    vector2s add(vector2s addend) {
        return {(short)(x + addend.x), (short)(y + addend.y)};
    }
};


enum states {
    SOLID,
    LIQUID,
    GAS,
    POWDER,
    ENERGY
};


struct element {
    char name[6];
    sf::Color color;
    ushort density;
    ubyte spawnState;
    ubyte addElement;

    sbyte forceDistribution;

    /*sbyte oxygen;
    sbyte flamablity;
    sbyte oxygenUsage;

    sbyte conduction;

    sbyte expStateLiq;
    sbyte startTempLiq;
    sbyte expStateGas;
    sbyte startTempGas;*/
};

extern std::vector<element> elements;



struct cell {
    ushort temp;
    vector2s linVelocity;
    sbyte energy;
    ubyte element;
    ubyte state;
    sbyte rad;

    position origin;
    vector2s displacement;
};

extern const ushort cellsX;
extern ushort cellsY;
extern cell** cells;
extern float cellSize;



struct UIObject {
    sf::Sprite sprite;
    bool active = true;
};



extern void Startup();

extern void ProcessCells();

extern void Render();

extern void Draw(ubyte);
extern ubyte formSelected;
extern ubyte elemSelected;

extern void ProcessUI(position mousePos);
extern UIObject bottom;
extern UIObject bigWindow;