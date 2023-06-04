#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "InputManager.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "SandboxScene.h"

// GLFW callback functions
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void window_close_callback(GLFWwindow* window);
void window_size_callback(GLFWwindow* window, int width, int height);

// Initial window parameters
const char* SCR_TITLE = "PixelSurfer";
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

// Window settings
const bool WINDOW_RESIZABLE = true;
const bool WINDOW_FULLSCREEN = false;
const bool WINDOW_VSYNC_ENABLED = false;

int main()
{
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
		std::cout << "ERROR: Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	// Set GLFW callback functions
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetWindowCloseCallback(window, window_close_callback);
	glfwSetWindowSizeCallback(window, window_size_callback);

	// Initialize GLEW
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		std::cout << "ERROR: Failed to initialize GLEW" << std::endl;
		std::cout << "Error string:\n" << glewGetErrorString(error) << std::endl;
		return -1;
	}

	// Set initial scene and set running state
	SceneManager::resize(SCR_WIDTH, SCR_HEIGHT);
	SceneManager::change(std::make_unique<SandboxScene>("Sandbox"));
	SceneManager::start();

	// Begin game loop after initialization
	float current_time;
	float delta_time;
	float last_time = 0.0f;
	while (SceneManager::isRunning())
	{
		// Calculate frame time to pass along to scenes
		current_time = (float)glfwGetTime();
		delta_time = current_time - last_time;
		last_time = current_time;

		// Poll for all input events
		glfwPollEvents();

		// Update and draw scenes
		SceneManager::getCurrent()->processInput(delta_time);
		SceneManager::getCurrent()->update(delta_time);
		SceneManager::getCurrent()->render();

		// Swap buffers
		glfwSwapBuffers(window);
	}

	// Dispose scenes
	SceneManager::dispose();
	ResourceManager::dispose();

	// Dispose all loaded scenes and terminate GLFW
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
		InputManager::setPrevKeyState(key, InputManager::isKeyDown(key));
		InputManager::setKeyState(key, action);
	}
}

// On window close event, end game loop
void window_close_callback(GLFWwindow* window)
{
	SceneManager::quit();
}

// On window resize event, set dimensions in scene manager
void window_size_callback(GLFWwindow* window, int width, int height)
{
	SceneManager::resize((float)width, (float)height);
}
