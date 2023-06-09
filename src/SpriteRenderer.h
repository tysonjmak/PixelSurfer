#pragma once

#include "ResourceManager.h"
#include "Shader.h"
#include "Sprite.h"

class SpriteRenderer
{
public:
	static void init(Shader* shader);
	static void draw(Sprite& sprite);
	static void setProjectionMatrix(const glm::mat4& projection);

private:
	static Shader* m_shader;
	static unsigned int m_quad_vao;
};
