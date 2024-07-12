#include <iostream>
#include "maze_generator.h"

int maze_dim = 240;
int cellsize = 4;
int cellspace = 4;

int num_cells = floor(maze_dim / (cellspace + cellsize));

// Grid
std::vector<std::vector<int>> grid(num_cells, std::vector<int>(num_cells, 0));


int main() {
	srand(time(0));

	Maze_generator maze_generator{num_cells, grid};

	maze_generator.maze_setup();
}
