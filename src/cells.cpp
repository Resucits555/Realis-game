#include <ctime>
#include "general.h"


cell* thisCellGlobal;

static int CheckCollision(int& x, int& y, cell& prevCell) {
    cell& thisCell = *thisCellGlobal;
    if (x >= cellsX || y >= cellsY) {
        prevCell = thisCell;
        prevCell.move = { 0, 0 };
        prevCell.linVelocity = { 0, 0 };
        return 2;
    }

    cell& lineCell = cells[y][x];
    if (lineCell.type) {
        lineCell.linVelocity = thisCell.linVelocity;
        prevCell = thisCell;
        prevCell.move = { 0, 0 };
        prevCell.linVelocity = { 0, 0 };
        return 1;
    }
    else {
        return 0;
    }
}


static void CheckCollisionH(int x, int y, sf::Vector2i goal) {
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
        cell* prevCell = &cells[0][0];
        int collision = 0;

        for (int i = x; i <= goal.x; i++) {
            if (der >= 0) {
                y += direction;
                der -= 2 * movement.x;
            }
            der += 2 * movement.y;
            if (i != x)
                if (collision = CheckCollision(i, y, *prevCell))
                    break;
            prevCell = &cells[y][i];
        }

        if (!collision) {
            *prevCell = *thisCellGlobal;
            *thisCellGlobal = empty;
        }
    }
}


static void CheckCollisionV(int x, int y, sf::Vector2i goal) {
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
        cell* prevCell = &cells[0][0];
        int collision = 0;

        for (int i = y; i <= goal.y; i++) {
            if (der >= 0) {
                x += direction;
                der -= 2 * movement.y;
            }
            der += 2 * movement.x;
            if (i != y)
                if (collision = CheckCollision(x, i, *prevCell))
                    break;
            prevCell = &cells[i][x];
        }

        if (!collision) {
            *prevCell = *thisCellGlobal;
            prevCell->move = { 0, 0 };
            *thisCellGlobal = empty;
        }
    }
}



void ProcessCells() {
    for (int y = 0; y < cellsY; y++) {
        for (int x = 0; x < cellsX; x++) {
            cell& thisCell = cells[y][x];
            thisCellGlobal = &thisCell;
            if (!thisCell.type || thisCell.type == 2)
                continue;
            
            thisCell.linVelocity.y++;
            thisCell.move.x += thisCell.linVelocity.x;
            thisCell.move.y += thisCell.linVelocity.y;

            unsigned char mass = elements[thisCell.type].mass;

            sf::Vector2i movement = { thisCell.move.x / mass, thisCell.move.y / mass };
            if (!movement.x && !movement.y)
                continue;

            sf::Vector2i goal = { movement.x + x, movement.y + y };
            if (std::abs(goal.x - x) > std::abs(goal.y - y))
                CheckCollisionH(x, y, goal);
            else
                CheckCollisionV(x, y, goal);
        }
    }
}