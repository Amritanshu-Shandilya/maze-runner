#include <math.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <utility>

int maze_dim = 240;
int cellsize = 4;
int cellspace = 4;

int num_cells = floor(maze_dim / (cellspace + cellsize));

int remaining_cells = (num_cells * num_cells) / 2; //This will ensure that only half of the cells will be used to create the maze

bool is_walking = true;

std::unordered_set<int> inMaze;

std::vector<std::pair<int, int>> directions = { {0,1}, {1,0}, {0,-1}, {-1,0} };
/* {0,1} - Right, {0,-1} - Left, {1,0} - Down, {-1,0} - Up */

// Grid
std::vector<std::vector<int>> grid(num_cells, std::vector<int>(num_cells, 0));

// Path
std::vector<std::pair<int, int>> path;


// The ENTRY point of the maze
std::vector<int> start_pos = { 0,7 };

// The EXIT point of the maze
std::vector<int> ending_pos = { 29,5 };


int display_grid() {

	//This function displays the grid on the command line

	int i, j;
	for (i = 0;i < num_cells; i++) {
		for (j = 0; j < num_cells; j++) {
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

int random_index_picker() {

	//This function returns a random index

	int high = num_cells;
	int low = 0;
	return (rand() % ((high - low) + 1) + low);
}

std::pair<int, int> randomDirection() {

	// Picks a random direction

	return directions[rand() % 4];
}

bool InBounds(int x, int y) {
	// This function checks whether the values x & y lie inside the grid 
	return x > 0 && x < num_cells && y>0 && y < num_cells;
}