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

void SandboxScene::init()
{
	shader = ResourceManager::load<Shader>("res/shaders/Shader.glsl");
	shader->bind();
	projection = glm::ortho(
		-SceneManager::getWidth() / 2.0f,
		SceneManager::getWidth() / 2.0f,
		-SceneManager::getHeight() / 2.0f,
		SceneManager::getHeight() / 2.0f
	);

	texture = ResourceManager::load<Texture>("res/textures/awesomeface.png");

	float vertices[] = {
		// Positions       // Texture coordinates
		128.0f,  128.0f,   1.0f, 1.0f,
		128.0f, -128.0f,   1.0f, 0.0f,
	   -128.0f, -128.0f,   0.0f, 0.0f,
	   -128.0f,  128.0f,   0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	unsigned int VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Copy vertices and indicies to buffers
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Set attributes
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void SandboxScene::dispose()
{

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

}

void SandboxScene::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	shader->setMat4("projection", projection);
	texture->bind();

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void SandboxScene::resize(float width, float height)
{
	projection = glm::ortho(
		-width / 2.0f,
		width / 2.0f,
		-height / 2.0f,
		height / 2.0f
	);
}
