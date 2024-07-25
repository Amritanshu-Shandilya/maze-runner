#include <iostream>
#include <cmath>
#include "graphics_design.h"

int maze_dim = 720;
int cellsize = 24;

int num_cells = floor(maze_dim / cellsize);

// Grid
std::vector<std::vector<int>> grid(num_cells, std::vector<int>(num_cells, 0));

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);	// Setsup viewport to match entire window dimension
	glMatrixMode(GL_PROJECTION);	// Switches the projection to  projection matrix mode
	glLoadIdentity();	// Resets projection matrix to identitiy matrix

	glOrtho(0.0, width, 0.0, height, -1.0, 1.0);	// Defines Orthographic projection matrix
	glMatrixMode(GL_MODELVIEW);	//Switches the projection to model view matrix mode
	glLoadIdentity();

}

int main() {
	srand(time(0));

	Maze_generator maze_generator{num_cells, grid};
	maze_generator.maze_setup();

	if (!glfwInit()) { // Initialize GLFW
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	Graphics_Builder graphics_builder{maze_dim, cellsize};

	// Create a window
	GLFWwindow* window = glfwCreateWindow(maze_dim, maze_dim, "Maze", NULL, NULL);
	
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glClearColor(0.7f, 0.7f, 0.7f, 0.7f);

	while (!glfwWindowShouldClose(window))
	{

		graphics_builder.processInput(window);

			// Setting up the background color to grey
		glClear(GL_COLOR_BUFFER_BIT);

		graphics_builder.drawGrid();

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

	glfwTerminate();	// Clean up the resources & properly exit the application
	
	return 0;
}
