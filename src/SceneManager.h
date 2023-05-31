#pragma once

#include <vector>
#include "InputManager.h"

class Scene;

class SceneManager
{
public:
	void init(InputManager* input);
	void dispose();

	void changeScene(Scene* scene);
	void pushScene(Scene* scene);
	void popScene();

	void processInput(float dt);
	void update(float dt);
	void render();

	bool isRunning() { return m_running; }
	void start() { m_running = true; }
	void quit() { m_running = false; }

private:
	InputManager* input;
	std::vector<Scene*> scenes;
	bool m_running = false;
};
