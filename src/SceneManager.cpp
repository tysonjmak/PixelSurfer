#include <iostream>

#include "SceneManager.h"

float SceneManager::m_width = 0.0f;
float SceneManager::m_height = 0.0f;
bool SceneManager::m_running = false;
std::stack<std::unique_ptr<Scene>> SceneManager::m_scenes;

std::unique_ptr<Scene>& SceneManager::getCurrent()
{
	return m_scenes.top();
}

bool SceneManager::isRunning() { return m_running; }

void SceneManager::start() { m_running = true; }

void SceneManager::quit() { m_running = false; }

void SceneManager::change(std::unique_ptr<Scene> scene)
{
	// Cleanup the current scene
	if (!m_scenes.empty())
	{
		m_scenes.top()->dispose();
		std::cout << "INFO: Disposed scene \"" << m_scenes.top()->getSceneID() << "\"" << std::endl;

		m_scenes.pop();
	}

	// Store and initialize the new scene
	m_scenes.push(std::move(scene));

	m_scenes.top()->init();
	std::cout << "INFO: Initialized scene \"" << m_scenes.top()->getSceneID() << "\"" << std::endl;
}

void SceneManager::push(std::unique_ptr<Scene> scene)
{
	// Pause current scene
	if (!m_scenes.empty())
	{
		m_scenes.top()->pause();
		std::cout << "INFO: Paused scene \"" << m_scenes.top()->getSceneID() << "\"" << std::endl;
	}

	// Store and initialize pushed scene
	m_scenes.push(std::move(scene));

	m_scenes.top()->init();
	std::cout << "INFO: Initialized scene \"" << m_scenes.top()->getSceneID() << "\"" << std::endl;
}

void SceneManager::pop()
{
	// Cleanup pushed scene
	if (!m_scenes.empty())
	{
		m_scenes.top()->dispose();
		std::cout << "INFO: Disposed scene \"" << m_scenes.top()->getSceneID() << "\"" << std::endl;

		m_scenes.pop();
	}

	// Resume the previous scene
	if (!m_scenes.empty())
	{
		m_scenes.top()->resume();
		std::cout << "INFO: Resumed scene \"" << m_scenes.top()->getSceneID() << "\"" << std::endl;
	}
}

bool SceneManager::empty()
{
	return m_scenes.empty();
}

float SceneManager::getWidth()
{
	return m_width;
}

float SceneManager::getHeight()
{
	return m_height;
}

void SceneManager::resize(float width, float height)
{
	m_width = width;
	m_height = height;
}

void SceneManager::dispose()
{
	std::cout << "INFO: Disposing SceneManager:" << std::endl;

	while (!m_scenes.empty())
	{
		m_scenes.top()->dispose();
		std::cout << "    Disposed scene \"" << m_scenes.top()->getSceneID() << "\"" << std::endl;

		m_scenes.pop();
	}
}
