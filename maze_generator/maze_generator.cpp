#include <iostream>
#include "maze_generator.h"


int wilson_algorithm() {
	// This algortithm generates a uniform spanning tree
	while (inMaze.size() < remaining_cells)
	{
		int x, y; //For storing randomly generated coordinates of the cells
		do
		{
			
			/* This do while loop implements the first random walk.
			As per the algorithm : 
				We need to do a random walk untill we visit a cell that is already a part of the maze.
				When we encounter a cell that is the part of the loop, we terminate the loop*/
			
			x = random_index_picker();
			y = random_index_picker();

		}
		// Here we check if the linearized value of (x,y) already exists in the unordered set 
		while (inMaze.count(x*num_cells+y)>0);

		// Adds (x,y) to the path
		path.push_back({ x,y });

		// Loop erased random walk
		while (inMaze.count(path.back().first*num_cells+path.back().second)==0)
		{
			// The conditions checks if the element of path vector is unvisited
			
			int u, v; // Stores the coordinates of the last element of path
			u = path.back().first;
			v = path.back().second;

			std::pair<int, int> dir = randomDirection();

		}


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
	int rand_index = random_index_picker();
	grid[rand_index][rand_index] = 1;
	display_grid();
	//wilson_algorithm();
	return 0;
}
