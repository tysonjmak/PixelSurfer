#pragma once

#include "Scene.h"

class SandboxScene : public Scene
{
	// Inherited via Scene
	virtual void init() override;
	virtual void dispose() override;
	virtual void pause() override;
	virtual void resume() override;
	virtual void processInput(float dt) override;
	virtual void update(float dt) override;
	virtual void render() override;
};
