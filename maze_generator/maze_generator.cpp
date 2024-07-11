#include <iostream>
#include "maze_generator.h"

int maze_dim = 240;
int cellsize = 4;
int cellspace = 4;

int num_cells = floor(maze_dim / (cellspace + cellsize));
int remaining_cells = num_cells * num_cells - 1;
bool is_walking = true;

std::unordered_set<int> inMaze;

std::vector<std::pair<int, int>> directions = { {0,1}, {1,0}, {0,-1}, {-1,0} };
/* {0,1} - Right, {0,-1} - Left, {1,0} - Down, {-1,0} - Up */

// Grid
std::vector<std::vector<int>> grid(num_cells, std::vector<int>(num_cells, 0));

// Path
std::vector<std::pair<int, int>> path;


int wilson_algorithm(std::vector<std::vector<int>> grid) {
	// This algortithm generates a uniform spanning tree
	while (remaining_cells > 0)
	{
		
	}
	return 0;
}


int main()
{	
	srand(time(0));

	// Specifying the entry and exit points of the maze
	grid[start_pos[0]][start_pos[1]] = 1;
	grid[ending_pos[0]][ending_pos[1]] = 1;

	// Inserting these coordinates into the unordered set using linearization
	inMaze.insert(start_pos[0] * num_cells + start_pos[1]);
	inMaze.insert(ending_pos[0] * num_cells + ending_pos[1]);

	// select one more random cell
	grid[random_index_picker(num_cells)][random_index_picker(num_cells)] = 1;
	//display_grid(grid, num_cells);
	//wilson_algorithm(grid);
	return 0;
}
