#include "general.h"


cell* thisCellGlobal = nullptr;
const short displacementMax = 3600;
const vector2s gravity = { 0, 30 };



void ProcessCells() {
    for (short y = 0; y < cellsY; y++) {
        for (short x = 0; x < cellsX; x++) {
            cell& thisCell = cells[y][x];
            thisCellGlobal = &thisCell;

            if (!thisCell.element)
                continue;

            
            
            if (thisCell.state)
                thisCell.linVelocity = thisCell.linVelocity.add(gravity);
            thisCell.displacement.x += thisCell.linVelocity.x;
            thisCell.displacement.y += thisCell.linVelocity.y;

            vector2s& displ = thisCell.displacement;
            vector2s goal = { (short)((displ.x / displacementMax) + x),
                              (short)((displ.y / displacementMax) + y) };

            if (goal.x >= cellsX || goal.x < 0) { 
                thisCell.linVelocity.x = 0;
                thisCell.displacement.x = 0;
                continue; }
            if (goal.y >= cellsY || goal.y < 0) {
                thisCell.linVelocity.y = 0;
                thisCell.displacement.y = 0;
                continue; }
            

            cell* goalCell = &cells[goal.y][goal.x];
            if (goalCell == &thisCell)
                continue;

            if (!goalCell->element) {
                *goalCell = thisCell;
                thisCell = {};
                goalCell->displacement.x -= (goal.x - x) * displacementMax;
                goalCell->displacement.y -= (goal.y - y) * displacementMax;
            }
            else {
                if (!cells[y][goal.x].element) {
                    thisCell.linVelocity.y = 0;
                    goalCell->linVelocity.y = thisCell.linVelocity.y;
                    cells[y][goal.x] = thisCell;
                    thisCell = {};
                } else if (!cells[goal.y][x].element) {
                    thisCell.linVelocity.x = 0;
                    goalCell->linVelocity.x = thisCell.linVelocity.x;
                    cells[goal.y][x] = thisCell;
                    thisCell = {};
                }
                else {
                    goalCell->linVelocity = thisCell.linVelocity;
                    thisCell.linVelocity = {};
                    thisCell.displacement = {};
                }
            }
        }
    }
}