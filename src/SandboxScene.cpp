#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "SandboxScene.h"
#include "Shader.h"

// Singleton instance
SandboxScene SandboxScene::m_sandbox_scene;

Shader* shader;
unsigned int VAO;

void SandboxScene::init()
{
	shader = new Shader("shaders/Shader.glsl");

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	unsigned int VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	// Bind buffers
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Copy data and set attribute layout
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

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

void SandboxScene::processInput(InputManager* input, SceneManager* scene, float dt)
{
	
}

void SandboxScene::update(float dt)
{
	
}

void SandboxScene::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	shader->bind();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
