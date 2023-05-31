#pragma once

#include <vector>
#include "InputManager.h"

class Scene;

class SceneManager
{
public:

	// Set the member input manager
	SceneManager(InputManager* input) : input(input) { }

	// Dispose of all scenes
	void dispose();

	/**
	 * 
	 * Changes the current scene in stack via a pointer to the scene's singleton instance
	 * 
	 * @param Scene* scene - Pointer to the scene to change to
	 */
	void changeScene(Scene* scene);

	/**
	 *
	 * Pushes given scene over current scene via a pointer to the new scene's singleton instance
	 *
	 * @param Scene* scene - Pointer to the scene to change to
	 */
	void pushScene(Scene* scene);

	// Pop the current scene and resume the previous scene
	void popScene();

	/**
	 *
	 * First function call in the game loop. Handles current scene's input
	 *
	 * @param float dt - Change in time between function calls (between frames)
	 */
	void processInput(float dt);

	/**
	 *
	 * Second function call in the game loop. Updates current scene.
	 *
	 * @param float dt - Change in time between functionc alls (between frames)
	 */
	void update(float dt);

	// Final function call in the game loop. Draws current scene.
	void render();

	// Returns whether the game loop is running
	bool isRunning() { return m_running; }

	// Begins the game loop
	void start() { m_running = true; }

	// Ends the game loop
	void quit() { m_running = false; }

private:
	// Input manager instance to pass along to scenes
	InputManager* input;

	// Scene stack to store the displayed scenes
	std::vector<Scene*> scenes;

	// Controls the game loop 'while' loop
	bool m_running = false;
};
