#include "general.h"


cell* thisCellGlobal = nullptr;
const short displacementMax = 3600;
const vector2s gravity = { 0, 15 };
const constexpr float drag = 0.05f;
static constexpr float Drag(short x) { return x * drag; }
static constexpr float InvDrag(short x) { return x * (1 - drag); }


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
            vector2s& vel = thisCell.linVelocity;
            vector2s goal = { (short)((displ.x / displacementMax) + x),
                              (short)((displ.y / displacementMax) + y) };

            if (&cells[goal.y][goal.x] == &thisCell)
                continue;

            if (goal.x >= cellsX || goal.x < 0) { 
                thisCell.linVelocity.x = 0;
                thisCell.displacement.x = 0;
                continue; }
            if (goal.y >= cellsY || goal.y < 0) {
                thisCell.linVelocity.y = 0;
                thisCell.displacement.y = 0;
                continue; }
            

            cell* goalCell = &cells[goal.y][goal.x];

            if (!goalCell->element) {
                *goalCell = thisCell;
                thisCell = {};
                goalCell->displacement.x -= (goal.x - x) * displacementMax;
                goalCell->displacement.y -= (goal.y - y) * displacementMax;
            }
            else {
                cell& cellx = cells[y][goal.x];
                cell& celly = cells[goal.y][x];

                if (&cellx != &thisCell)
                    if (cellx.element) {
                        cellx.linVelocity.x = (celly.element) ? InvDrag(vel.x) : vel.x;
                        vel.x = 0;
                        displ.x = displacementMax;

                        cellx.linVelocity.y = Drag(vel.y);
                    }

                if (&celly != &thisCell)
                    if (celly.element) {
                        celly.linVelocity.y = (cellx.element) ? InvDrag(vel.y) : vel.y;
                        vel.y = 0;
                        displ.y = displacementMax;

                        celly.linVelocity.x = Drag(vel.x);
                    }
            }
        }
    }
}