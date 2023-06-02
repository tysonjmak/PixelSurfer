#include <iostream>

#include "SceneManager.h"
#include "Scene.h"

void SceneManager::dispose()
{
	std::cout << "Disposing all scenes..." << std::endl;

	// Call dispose on all scenes in stack
	while (!m_scenes.empty())
	{
		m_scenes.back()->dispose();
		m_scenes.pop_back();
	}
}

void SceneManager::changeScene(Scene* scene)
{
	// Cleanup current scene
	if (!m_scenes.empty())
	{
		m_scenes.back()->dispose();
		m_scenes.pop_back();
	}

	// Store and initialize new scene
	m_scenes.push_back(scene);
	m_scenes.back()->init(m_input, this);
}

void SceneManager::pushScene(Scene* scene)
{
	// Pause current scene
	if (!m_scenes.empty())
	{
		m_scenes.back()->pause();
	}

	// Store and initialize new state
	m_scenes.push_back(scene);
	m_scenes.back()->init(m_input, this);
}

void SceneManager::popScene()
{
	// Cleanup current scene
	if (!m_scenes.empty())
	{
		m_scenes.back()->dispose();
		m_scenes.pop_back();
	}

	// Resume previous scene
	if (!m_scenes.empty())
	{
		m_scenes.back()->resume();
	}
}

void SceneManager::processInput(float dt)
{
	m_scenes.back()->processInput(dt);
}

void SceneManager::update(float dt)
{
	m_scenes.back()->update(dt);
}

void SceneManager::render()
{
	m_scenes.back()->render();
}

void SceneManager::resize(float width, float height)
{
	m_width = width;
	m_height = height;
}

float SceneManager::getWidth() const
{
	return m_width;
}

float SceneManager::getHeight() const
{
	return m_height;
}
