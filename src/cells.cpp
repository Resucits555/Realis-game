#include <ctime>
#include "general.h"

const unsigned char moveThreshold = 255; //the smaller the faster

//static void Liquid(int& x, int& y, short& posx) {
//	std::srand(std::time({}));
//	posx += (std::rand() + RAND_MAX) / RAND_MAX -1;
//}


void ProcessCells() {
	for (int y = 0; y < cellsY; y++) {
		for (int x = 0; x < cellsX; x++) {
			cell& thisCell = cells[y][x];
			if (!thisCell.type)
				continue;

			vector2s& pos = thisCell.pos;

			if (y < cellsY-1) {
				thisCell.linVelocity.y++;
				pos.y += thisCell.linVelocity.y;
			}
			else
				thisCell.linVelocity.y = 0;

			if (x < cellsX-1)
				pos.x += thisCell.linVelocity.x;
			else
				thisCell.linVelocity.x = 0;

			/*switch (thisCell.state) {
				case LIQUID:
					Liquid(x, y, pos.x);
					break;
			}*/

			//TODO: Increase max speed over 1

			if (pos.x >= 1 || pos.x <= -1) {
				cell& moveCell = cells[y][x + pos.x];
				if (moveCell.type)
					moveCell.linVelocity.x += thisCell.linVelocity.x;
				else {
					moveCell = thisCell;
					moveCell.pos.x = 0;
					thisCell = {};
				}
			}

			if (pos.y >= moveThreshold || pos.y <= -moveThreshold) {
				cell& moveCell = cells[y + 1/*(pos.y / moveThreshold)*/][x];
				if (moveCell.type)
					moveCell.linVelocity.y += thisCell.linVelocity.y;
				else {
					moveCell = thisCell;
					moveCell.pos.y = 0;
					thisCell = {};
				}
			}
		}
	}
}