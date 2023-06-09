#pragma once

#include <glm/glm.hpp>
#include "Texture.h"

class Sprite
{
public:
	Sprite() : m_position(glm::vec2()), m_velocity(glm::vec2()), m_size(glm::vec2()), m_rotation(0.0f), m_texture(nullptr) { }
	Sprite(glm::vec2 position, Texture* texture) : m_position(position), m_velocity(glm::vec2()), m_size(glm::vec2(texture->getWidth(), texture->getHeight())), m_rotation(0.0f), m_texture(texture) { }

	inline const glm::vec2& getPosition() const { return m_position; }
	inline void setPosition(const glm::vec2& position) { m_position = position; }

	inline const glm::vec2& getVelocity() const { return m_velocity; }
	inline void setVelocity(const glm::vec2& velocity) { m_velocity = velocity; }

	inline const glm::vec2& getSize() const { return m_size; }
	inline void setSize(const glm::vec2& size) { m_size = size; }

	inline float getWidth() const { return m_size.x; }
	inline void setWidth(float width) { m_size.x = width; }

	inline float getHeight() const { return m_size.y; }
	inline void setHeight(float height) { m_size.y = height; }

	inline float getRotation() const { return m_rotation; }
	inline void setRotation(float rotation) { m_rotation = rotation; }

	inline Texture* getTexture() const { return m_texture; }
	inline void setTexture(Texture* texture) { m_texture = texture; }

protected:
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	glm::vec2 m_size;
	float m_rotation;
	Texture* m_texture;
};
