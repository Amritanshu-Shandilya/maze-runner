#include <math.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <utility>
#include <string>


class Maze_generator {

	private:

		std::vector<std::pair<int, int>> directions = { {0,1}, {1,0}, {0,-1}, {-1,0} };
		/* {0,1} - Right, {0,-1} - Left, {1,0} - Down, {-1,0} - Up */

		// Path
		std::vector<std::pair<int, int>> path;

		// The ENTRY point of the maze
		std::vector<int> start_pos = { 0,7 };

		// The EXIT point of the maze
		std::vector<int> ending_pos = { 29,5 };

	public:

		int num_cells, remaining_cells;
		
		// Grid
		std::vector<std::vector<int>> grid;
		
		Maze_generator(int, std::vector<std::vector<int>>); // Constructor

		int display_grid();
		int random_index_picker();
		std::pair<int, int> randomDirection();
		int wilson_algorithm();
		bool InBounds(int, int);
		int maze_setup();
		
		std::unordered_set<int> inMaze;
	
};

Maze_generator::Maze_generator(int cells, std::vector<std::vector<int>> grid) {

	Maze_generator::num_cells = cells;
	Maze_generator::grid = grid;
	Maze_generator::remaining_cells = (num_cells * num_cells) / 2; //This will ensure that only half of the cells will be used to create the maze

}

int Maze_generator::display_grid() {

	//This function displays the grid on the command line

	int i, j;
	for (i = 0; i < num_cells; i++) {
		for (j = 0; j < num_cells; j++) {
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

int Maze_generator::random_index_picker() {

	//This function returns a random index

	int high = num_cells;
	int low = 0;
	return (rand() % ((high - low) + 1) + low);

}

std::pair<int, int> Maze_generator::randomDirection() {

	// Picks a random direction

	return directions[rand() % 4];
}

bool Maze_generator::InBounds(int x, int y) {

	// This function checks whether the values x & y lie inside the grid 
	
	return x > 0 && x < (num_cells - 1) && y > 0 && y < (num_cells - 1);
}


int Maze_generator::wilson_algorithm() {
	// This algortithm generates a uniform spanning tree
	while (inMaze.size() < remaining_cells)
	{
		int x, y; //For storing randomly generated coordinates of the cells
		do
		{

			/* This do while loop implements the first random walk.
			As per the algorithm :
				We need to do a random walk untill we visit a cell that is already a part of the maze.
				When we encounter a cell that is the part of the loop, we terminate the loop */

			x = random_index_picker();
			y = random_index_picker();

		}
		// Here we check if the linearized value of (x,y) already exists in the unordered set 
		while (inMaze.count(x * num_cells + y) > 0);

		// Adds (x,y) to the path
		if (InBounds(x, y)) {
			path.push_back({ x,y });
		}

		// Loop erased random walk
		while (inMaze.count(path.back().first * num_cells + path.back().second) == 0)
		{
			// The conditions checks if the element of path vector is unvisited

			int x, y; // Stores the coordinates of the last element of path
			int nextX, nextY; // Stores the coordinates of the last element of the path

			x = path.back().first;
			y = path.back().second;

			std::pair<int, int> dir = randomDirection();

			// Finding the coordinates of the next cell in the path
			nextX = x + dir.first;
			nextY = y + dir.second;

			if (InBounds(nextX, nextY)) {
				// If the next path cell lies inside the grid, add it to the path
				path.push_back({ nextX, nextY });
			}

			for (const auto& cell : path)
			{

				/* This range based for loop is used to iterate over path vector making its elements
				   a part of maze and changing its value to 1*/

				inMaze.insert(cell.first * num_cells + cell.second);
				grid[cell.first][cell.second] = 1;
			}

		}


	}
	return 0;
}

int Maze_generator::maze_setup()
{
	/* This function initiates the maze creation */

	// Specifying the entry and exit points of the maze
	grid[start_pos[0]][start_pos[1]] = 1;
	grid[ending_pos[0]][ending_pos[1]] = 1;

	// Inserting these coordinates into the unordered set using linearization
	inMaze.insert(start_pos[0] * num_cells + start_pos[1]);
	inMaze.insert(ending_pos[0] * num_cells + ending_pos[1]);

	// select one more random cell
	int rand_index = random_index_picker();
	grid[rand_index][rand_index] = 1;

	wilson_algorithm();

	//display_grid();

	return 0;
}