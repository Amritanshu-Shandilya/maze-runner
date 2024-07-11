#include <math.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <utility>

// The ENTRY point of the maze
std::vector<int> start_pos = { 0,7 };

// The EXIT point of the maze
std::vector<int> ending_pos = { 29,5 };


int display_grid(std::vector<std::vector<int>> grid,  int num_cells) {

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

int random_index_picker(int numcells) {

	//This function returns a random index

	int high = numcells;
	int low = 0;
	return (rand() % ((high - low) + 1) + low);
}

std::pair<int, int> randomDirection(std::vector<std::pair<int, int>> directions) {

	// Picks a random direction

	return directions[rand() % 4];
}
