#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "Camera.h"

Camera::Camera() : m_width(2.0f), m_height(2.0f)
{
	m_projection_matrix = glm::ortho(-m_width / 2.0f, m_width / 2.0f, -m_height / 2.0f, m_height / 2.0f, -1.0f, 1.0f);
	m_view_matrix = glm::mat4(1.0f);
	m_combined = m_projection_matrix * m_view_matrix;

	m_position = glm::vec2();
	m_rotation = 0.0f;
	m_zoom = 1.0f;

	update();
}

Camera::Camera(glm::vec2 position) : m_width(2.0f), m_height(2.0f)
{
	m_projection_matrix = glm::ortho(-m_width / 2.0f, m_width / 2.0f, -m_height / 2.0f, m_height / 2.0f, -1.0f, 1.0f);
	m_view_matrix = glm::mat4(1.0f);
	m_combined = m_projection_matrix * m_view_matrix;

	m_position = position;
	m_rotation = 0.0f;
	m_zoom = 1.0f;

	update();
}

Camera::Camera(float width, float height) : m_width(width), m_height(height)
{
	m_projection_matrix = glm::ortho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f, -1.0f, 1.0f);
	m_view_matrix = glm::mat4(1.0f);
	m_combined = m_projection_matrix * m_view_matrix;

	m_position = glm::vec2();
	m_rotation = 0.0f;
	m_zoom = 1.0f;

	update();
}

Camera::Camera(float width, float height, glm::vec2 position) : m_width(width), m_height(height)
{
	m_projection_matrix = glm::ortho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f, -1.0f, 1.0f);
	m_view_matrix = glm::mat4(1.0f);
	m_combined = m_projection_matrix * m_view_matrix;

	m_position = position;
	m_rotation = 0.0f;
	m_zoom = 1.0f;

	update();
}

void Camera::update()
{
	glm::mat4 transform = glm::translate(glm::mat4(1.0f), glm::vec3(m_position, 0.0f)) *
		glm::rotate(glm::mat4(1.0f), m_rotation, glm::vec3(0, 0, 1));

	m_projection_matrix = glm::ortho(
		-m_width / 2.0f / m_zoom,
		 m_width / 2.0f / m_zoom,
		-m_height / 2.0f / m_zoom,
		 m_height / 2.0f / m_zoom,
		-1.0f, 1.0f
	);
	m_view_matrix = glm::inverse(transform);
	m_combined = m_projection_matrix * m_view_matrix;
}
