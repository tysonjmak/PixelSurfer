#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <stb/stb_image.h>
#include <iostream>

#include "InputManager.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "SpriteRenderer.h"
#include "SandboxScene.h"
#include "MenuScene.h"

void SandboxScene::init()
{
	camera = new Camera(SceneManager::getWidth(), SceneManager::getHeight());

	sprite1 = new Sprite(glm::vec2(0.0f), ResourceManager::get<Texture>("res/textures/awesomeface.png"));
	sprite1->setSize(glm::vec2(128.0f, 128.0f));

	sprite2 = new Sprite(glm::vec2(0.0f), ResourceManager::get<Texture>("res/textures/container.jpg"));
	sprite2->setSize(glm::vec2(128.0f, 128.0f));
}

void SandboxScene::dispose()
{
	delete camera;
	delete sprite1;
	delete sprite2;
}

void SandboxScene::pause()
{

}

void SandboxScene::resume()
{

}


void SandboxScene::processInput(float dt)
{
	if (InputManager::isKeyPressed(GLFW_KEY_ESCAPE))
		SceneManager::quit();
	if (InputManager::isKeyPressed(GLFW_KEY_ENTER))
		SceneManager::change(std::make_unique<MenuScene>("Menu"));
}

void SandboxScene::update(float dt)
{
	camera->update();
}

void SandboxScene::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	SpriteRenderer::setProjectionMatrix(camera->getCombined());
	SpriteRenderer::draw(*sprite2);
	SpriteRenderer::draw(*sprite1);
}

void SandboxScene::resize(float width, float height)
{

}
