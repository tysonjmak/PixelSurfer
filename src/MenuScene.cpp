#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <stb/stb_image.h>
#include <iostream>

#include "InputManager.h"
#include "ResourceManager.h"
#include "SceneManager.h"

#include "SandboxScene.h"
#include "MenuScene.h"

void MenuScene::init()
{
	shader = ResourceManager::load<Shader>("res/shaders/Shader.glsl");
	shader->bind();
	shader->unbind();
}

void MenuScene::dispose()
{
}

void MenuScene::pause()
{
}

void MenuScene::resume()
{
}

void MenuScene::processInput(float dt)
{
	if (InputManager::isKeyPressed(GLFW_KEY_ESCAPE))
		SceneManager::quit();

	if (InputManager::isKeyPressed(GLFW_KEY_ENTER))
		SceneManager::change(std::make_unique<SandboxScene>("Sandbox"));
}

void MenuScene::update(float dt)
{
}

void MenuScene::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void MenuScene::resize(float width, float height)
{
}
