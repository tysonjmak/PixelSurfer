#include <iostream>

#include "SceneManager.h"
#include "Scene.h"

void SceneManager::init(InputManager* input)
{
	this->input = input;
}

void SceneManager::dispose()
{
	std::cout << "Disposing all scenes..." << std::endl;

	// Call dispose on all scenes in stack
	while (!scenes.empty())
	{
		scenes.back()->dispose();
		scenes.pop_back();
	}
}

void SceneManager::changeScene(Scene* scene)
{
	// Cleanup current scene
	if (!scenes.empty())
	{
		scenes.back()->dispose();
		scenes.pop_back();
	}

	// Store and initialize new scene
	scenes.push_back(scene);
	scenes.back()->init();
}

void SceneManager::pushScene(Scene* scene)
{
	// Pause current scene
	if (!scenes.empty())
	{
		scenes.back()->pause();
	}

	// Store and initialize new state
	scenes.push_back(scene);
	scenes.back()->init();
}

void SceneManager::popScene()
{
	// Cleanup current scene
	if (!scenes.empty())
	{
		scenes.back()->dispose();
		scenes.pop_back();
	}

	// Resume previous scene
	if (!scenes.empty())
	{
		scenes.back()->resume();
	}
}

void SceneManager::processInput(float dt)
{
	scenes.back()->processInput(input, this, dt);
}

void SceneManager::update(float dt)
{
	scenes.back()->update(dt);
}

void SceneManager::render()
{
	scenes.back()->render();
}
