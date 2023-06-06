#pragma once

#include <stack>

#include "Scene.h"

class SceneManager
{
public:
	// Return reference to current scene
	static std::unique_ptr<Scene>& getCurrent();

	// Game status management

	// Returns whether the game loop is running
	static bool isRunning();

	// Begins the game loop
	static void start();

	// Ends the game loop
	static void quit();

	// Game scene management

	// Replace the current scene with a new scene
	static void change(std::unique_ptr<Scene> scene);

	// Push a scene in front of current scene
	static void push(std::unique_ptr<Scene> scene);

	// Pop a pushed scene
	static void pop();

	// Return whether scene stack is empty
	static bool empty();

	// Return width of window
	static float getWidth();

	// Return height of window
	static float getHeight();

	// On window resize event
	static void resize(float width, float height);

	// Dispose all scenes in stack
	static void dispose();

private:
	// Store window dimensions for scene use
	static float m_width, m_height;

	// Controls the game loop 'while' loop
	static bool m_running;

	// Store the scenes in here
	static std::stack<std::unique_ptr<Scene>> m_scenes;
};
