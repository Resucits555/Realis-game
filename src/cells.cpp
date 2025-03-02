#include "general.h"

void ProcessCells() {
	for (int y = 0; y < cellsX; y++) {
		for (int x = 0; x < cellsY; x++) {
			cell& thisCell = cells[y][x];
			if (!thisCell.type)
				continue;

			//TODO: Make cells work
		}
	}
}