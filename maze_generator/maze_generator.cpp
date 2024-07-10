#include <iostream>

#include "maze_generator.h"

int maze_dim = 240;
int cellsize = 4;
int cellspace = 4;

int num_cells = floor(maze_dim / (cellspace + cellsize));
int remaining_cells = num_cells * num_cells - 1;
bool is_walking = true;

int N, S, E, W;

//Grid
std::vector<std::vector<int>> grid(num_cells, std::vector<int>(num_cells, 0));

int maze_generator(std::vector<std::vector<int>> grid) {
	while (remaining_cells > 0)
	{
		// select one more random cell
		grid[random_index_picker(num_cells)][random_index_picker(num_cells)] = 1;
		
	}
	return 0;
}


int main()
{	
	grid[start_pos[0]][start_pos[1]] = 1;
	//grid[ending_pos[0]][ending_pos[1]] = 1;
	//display_grid(grid, num_cells);
	maze_generator(grid);
	return 0;
}
