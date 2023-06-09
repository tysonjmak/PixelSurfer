#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "SpriteRenderer.h"
#include "Texture.h"

Shader* SpriteRenderer::m_shader;
unsigned int SpriteRenderer::m_quad_vao;

void SpriteRenderer::init(Shader* shader)
{
	// Set specified shader
	m_shader = shader;

	float vertices[] = {
		// Positions   // Texture coordinates
		1.0f,  1.0f,   1.0f, 1.0f,
		1.0f, -1.0f,   1.0f, 0.0f,
	   -1.0f, -1.0f,   0.0f, 0.0f,
	   -1.0f,  1.0f,   0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	// Generate buffers
	unsigned int vbo, ebo;
	glGenVertexArrays(1, &m_quad_vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	glBindVertexArray(m_quad_vao);

	// Set buffer data
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Set index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Set attributes
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void SpriteRenderer::draw(Sprite& sprite)
{
	m_shader->bind();

	// Transform sprite
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(sprite.getPosition(), 0.0f));
	model = glm::scale(model, glm::vec3(sprite.getSize(), 0.0f));
	m_shader->setMat4("u_model", model);

	// Render sprite
	sprite.getTexture()->bind();
	glBindVertexArray(m_quad_vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);

	m_shader->unbind();
}

void SpriteRenderer::setProjectionMatrix(const glm::mat4& combined)
{
	m_shader->bind();
	m_shader->setMat4("u_projection", combined);
	m_shader->unbind();
}
