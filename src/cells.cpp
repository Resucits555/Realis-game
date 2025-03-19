#include "general.h"


cell* thisCellGlobal;

static int CheckCollision(ushort& x, ushort& y, cell& prevCell) {
    cell& thisCell = *thisCellGlobal;
    if (x >= cellsX || y >= cellsY) {
        cell temp = thisCell;
        thisCell = {};
        prevCell = temp;
        prevCell.displacement = {};
        prevCell.linVelocity = {};
        return 2;
    }

    cell& lineCell = cells[y][x];
    if (lineCell.element) {
        cell temp = thisCell;
        thisCell = {};
        prevCell = temp;
        prevCell.displacement = {};
        //Thinks that lineCell is true when it shouldn't (particle in path already moved)
        prevCell.linVelocity = {};
        return 1;
    }
    else {
        return 0;
    }
}


static void CheckCollisionH(ushort x, ushort y, sf::Vector2i goal) {
    if (x > goal.x) {
        sf::Vector2i temp = goal;
        goal = { x, y };
        x = temp.x;
        y = temp.y;
    }

    sf::Vector2i movement = { goal.x - x, goal.y - y };
    
    std::int8_t direction = (movement.y < 0) ? -1 : 1;
    movement.y *= direction;

    if (movement.x != 0) {
        int der = 2 * movement.y - movement.x;
        cell* prevCell = nullptr;
        int collision = 0;

        for (ushort i = x; i <= goal.x; i++) {
            if (der >= 0) {
                y += direction;
                der -= 2 * movement.x;
            }
            der += 2 * movement.y;

            if (i != x && (collision = CheckCollision(i, y, *prevCell)))
                break;
            prevCell = &cells[y][i];
        }

        if (!collision) {
            *prevCell = *thisCellGlobal;
            prevCell->displacement = { 0, 0 };
            *thisCellGlobal = {};
        }
    }
}


static void CheckCollisionV(ushort x, ushort y, sf::Vector2i goal) {
    if (y > goal.y) {
        sf::Vector2i temp = goal;
        goal = { x, y };
        x = temp.x;
        y = temp.y;
    }

    sf::Vector2i movement = { goal.x - x, goal.y - y };

    std::int8_t direction = (movement.x < 0) ? -1 : 1;
    movement.x *= direction;

    if (movement.y != 0) {
        int der = 2 * movement.x - movement.y;
        cell* prevCell = nullptr;
        int collision = 0;

        for (ushort i = y; i <= goal.y; i++) {
            if (der >= 0) {
                x += direction;
                der -= 2 * movement.y;
            }
            der += 2 * movement.x;

            if (i != y && (collision = CheckCollision(x, i, *prevCell)))
                break;
            prevCell = &cells[i][x];
        }

        if (!collision) {
            *prevCell = *thisCellGlobal;
            prevCell->displacement = { 0, 0 };
            *thisCellGlobal = {};
        }
    }
}



void ProcessCells() {
    for (ushort y = 0; y < cellsY; y++) {
        for (ushort x = 0; x < cellsX; x++) {
            cell& thisCell = cells[y][x];
            thisCellGlobal = &thisCell;

            if (!thisCell.element)
                continue;

            ubyte mass = elements[thisCell.element].density;
            
            if (thisCell.state) thisCell.linVelocity.y++;
            thisCell.displacement.x += thisCell.linVelocity.x;
            thisCell.displacement.y += thisCell.linVelocity.y;

            sf::Vector2i movement = { thisCell.displacement.x / mass, thisCell.displacement.y / mass };

            if (!movement.x && !movement.y)
                continue;

            sf::Vector2i goal = { movement.x + x, movement.y + y };
            if (goal.x < 0 || goal.y < 0) {
                thisCell.linVelocity = {};
                continue;
            }

            if (std::abs(goal.x - x) > std::abs(goal.y - y))
                CheckCollisionH(x, y, goal);
            else
                CheckCollisionV(x, y, goal);
        }
    }
}