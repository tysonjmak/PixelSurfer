#pragma once

#include "Scene.h"

class SandboxScene : public Scene
{
public:
	void init(InputManager* input_manager, SceneManager* scene_manager);
	void dispose();

	void pause();
	void resume();

	void processInput(float dt);
	void update(float dt);
	void render();

	static SandboxScene* instance()
	{
		return &m_sandbox_scene;
	}

protected:
	SandboxScene() {}

private:
	static SandboxScene m_sandbox_scene;
};
