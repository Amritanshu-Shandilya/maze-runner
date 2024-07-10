#include <math.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

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

bool random_walk(std::vector<std::vector<int>> grid) {
	/*Constraints:
		- It can cross the cells it had already walked as long as they are not already in the maze 
		- Final path cannot have any loops in it.*/

	for (int i = 0; i < ; i++)
	{

	}

}
