#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
	Camera();
	Camera(glm::vec2 position);
	Camera(float width, float height);
	Camera(float width, float height, glm::vec2 position);

	const glm::vec2& getPosition() const { return m_position; }
	void setPosition(const glm::vec2& position) { m_position = position; }

	float getRotation() const { return m_rotation; }
	void setRotation(float rotation) { m_rotation = rotation; }

	float getZoom() const { return m_zoom; }
	void setZoom(float zoom) { m_zoom = zoom; }

	const glm::mat4& getProjectionMatrix() const { return m_projection_matrix; }
	const glm::mat4& getViewMatrix() const { return m_view_matrix; }
	const glm::mat4& getCombined() const { return m_combined; }

	void update();

private:
	glm::mat4 m_projection_matrix;
	glm::mat4 m_view_matrix;
	glm::mat4 m_combined;

	glm::vec2 m_position;
	float m_width;
	float m_height;
	float m_rotation;
	float m_zoom;
};
