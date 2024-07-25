#include <GLFW/glfw3.h>
#include "maze_generator.h"


class Graphics_Builder : public Maze_generator
{
public:
	int maze_dim;
	int cellsize;
	int grid_size;


	Graphics_Builder(int, int);
	
	void processInput(GLFWwindow*);
	void drawGrid();

private:
	
};

Graphics_Builder::Graphics_Builder(int dim, int cellsize):Maze_generator(Maze_generator::num_cells, Maze_generator::grid)
{
	grid_size = num_cells;
	maze_dim = dim;
	cellsize = cellsize;
	
}



void Graphics_Builder::processInput(GLFWwindow* window)
{	

	// This function closes the window when ESC key is pressed

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void Graphics_Builder::drawGrid()
{
	// It draws the grid lines on the screen

	// Set the line color to black
	glColor3f(0.0f, 0.0f, 0.0f);

	// Set the line width to 2 pixels
	glLineWidth(2.0f);

	// Draw the filled cells and the grid lines
	for (int i = 0; i < grid_size; ++i) {
		for (int j = 0; j < grid_size; ++j) {
			if (grid[i][j] == 1) { // Path
				glColor3f(1.0f, 1.0f, 1.0f); // White color
				glBegin(GL_QUADS);
				glVertex2f(j * cellsize, i * cellsize);
				glVertex2f((j + 1) * cellsize, i * cellsize);
				glVertex2f((j + 1) * cellsize, (i + 1) * cellsize);
				glVertex2f(j * cellsize, (i + 1) * cellsize);
				glEnd();
			}
		}
	}
}