#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

#include "SandboxScene.h"
#include "Shader.h"

// Singleton instance
SandboxScene SandboxScene::m_sandbox_scene;

Shader* shader;
unsigned int VAO;

void SandboxScene::init(InputManager* input_manager, SceneManager* scene_manager)
{
	// Set local managers before any code
	input = input_manager;
	scene = scene_manager;

	shader = new Shader("res/shaders/Shader.glsl");
	shader->bind();

	float vertices[] = {
		 // Positions             // Colors
		-256.0f, -256.0f, 0.0f,   1.0f, 0.0f, 0.0f,
		 256.0f, -256.0f, 0.0f,   0.0f, 1.0f, 0.0f,
		 0.0f,    256.0f, 0.0f,   0.0f, 0.0f, 1.0f
	};

	unsigned int VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	// Bind buffers
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Copy data and set attribute layout
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Unbind buffers for later use
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void SandboxScene::dispose()
{
	delete shader;
	
}

void SandboxScene::pause()
{

}

void SandboxScene::resume()
{

}

void SandboxScene::processInput(float dt)
{
	if (input->isKeyPressed(GLFW_KEY_ESCAPE))
		scene->quit();
}

void SandboxScene::update(float dt)
{

}

void SandboxScene::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glm::mat4 projection = glm::ortho(-scene->getWidth() / 2.0f, scene->getWidth() / 2.0f, -scene->getHeight() / 2.0f, scene->getHeight() / 2.0f, 0.0f, 1.0f);
	shader->setMat4("projection", projection);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
