#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "SceneManager.h"
#include "SandboxScene.h"

// GLFW callback functions
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void window_close_callback(GLFWwindow* window);

// Window settings
const char* SCR_TITLE = "PixelSurfer";
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;
const bool WINDOW_RESIZABLE = false;
const bool WINDOW_FULLSCREEN = false;
const bool WINDOW_VSYNC_ENABLED = true;

// Managers
InputManager input;
SceneManager scene;

int main()
{
	// Get all initialization done first
	// ---------------------------------

	// Initialize GLFW and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, WINDOW_RESIZABLE);

	// Create GLFW window
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, SCR_TITLE, WINDOW_FULLSCREEN ? glfwGetPrimaryMonitor() : NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(WINDOW_VSYNC_ENABLED);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	// Set GLFW callback functions
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetWindowCloseCallback(window, window_close_callback);

	// Initialize GLEW
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		std::cout << "Error:\n" << glewGetErrorString(error) << std::endl;
		return -1;
	}

	// Initialize scene manager and scenes
	scene.init(&input);
	scene.changeScene(SandboxScene::instance());
	scene.start();

	// Begin game loop after initialization
	float current_time;
	float delta_time;
	float last_time = 0.0f;
	while (scene.isRunning())
	{
		// Calculate frame time to pass along to scenes
		current_time = (float)glfwGetTime();
		delta_time = current_time - last_time;
		last_time = current_time;

		// Poll for all input events
		glfwPollEvents();

		// Update and draw scenes
		scene.processInput(delta_time);
		scene.update(delta_time);
		scene.render();

		// Swap buffers
		glfwSwapBuffers(window);
	}

	// Dispose all loaded scenes and terminate GLFW
	scene.dispose();
	glfwTerminate();

	return 0;
}

// Change OpenGL viewport on window (framebuffer) resize
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

// On key event, handle input manager for keys
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key >= 0 && key < NUM_KEYS)
	{
		input.setPrevKeyState(key, input.isKeyDown(key));
		input.setKeyState(key, action);
	}
}

// On window close event, end game loop
void window_close_callback(GLFWwindow* window)
{
	scene.quit();
}
