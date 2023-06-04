#pragma once

#include "Scene.h"

class SandboxScene : public Scene
{
public:
	SandboxScene(const char* scene_ID) : Scene(scene_ID) { }

	// Inherited via Scene
	virtual void init() override;
	virtual void dispose() override;
	virtual void pause() override;
	virtual void resume() override;
	virtual void processInput(float dt) override;
	virtual void update(float dt) override;
	virtual void render() override;
};
