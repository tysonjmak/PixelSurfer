#pragma once

#include "SceneManager.h"

class Scene
{
public:
	virtual void init()= 0;
	virtual void dispose() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void processInput(InputManager* input, SceneManager* scene, float dt) = 0;
	virtual void update(float dt) = 0;
	virtual void render() = 0;

protected:
	Scene() {}
};
