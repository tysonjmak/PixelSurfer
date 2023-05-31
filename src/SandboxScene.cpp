#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "SandboxScene.h"

// Singleton instance
SandboxScene SandboxScene::m_sandbox_scene;

void SandboxScene::init()
{
	std::cout << "Initializing SandboxScene" << std::endl;
}

void SandboxScene::dispose()
{
	std::cout << "Disposing SandboxScene" << std::endl;
}

void SandboxScene::pause()
{
	std::cout << "Pausing SandboxScene" << std::endl;
}

void SandboxScene::resume()
{
	std::cout << "Resuming SandboxScene" << std::endl;
}

void SandboxScene::processInput(InputManager* input, SceneManager* scene, float dt)
{
	
}

void SandboxScene::update(float dt)
{
	
}

void SandboxScene::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
