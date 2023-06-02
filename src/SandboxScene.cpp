#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <stb/stb_image.h>
#include <iostream>

#include "SandboxScene.h"
#include "Shader.h"

// Singleton instance
SandboxScene SandboxScene::m_sandbox_scene;

Shader* shader;
unsigned int VAO;
unsigned int texture;

void SandboxScene::init(InputManager* input_manager, SceneManager* scene_manager)
{
	// Set local managers before any code
	input = input_manager;
	scene = scene_manager;

	shader = new Shader("res/shaders/Shader.glsl");
	shader->bind();

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

	// Load and create texture
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Set texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Load image data
	int width, height, nrChannels;
	unsigned char* data = stbi_load("res/textures/container.jpg", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "ERROR: Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
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

	shader->bind();
	glm::mat4 projection = glm::ortho(-scene->getWidth() / 2.0f, scene->getWidth() / 2.0f, -scene->getHeight() / 2.0f, scene->getHeight() / 2.0f, 0.0f, 1.0f);
	shader->setMat4("projection", projection);

	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
