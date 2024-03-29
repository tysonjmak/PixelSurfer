#pragma once

#include <glm/glm.hpp>

#include "Resource.h"

struct ShaderSource
{
	std::string vertex;
	std::string fragment;
};

class Shader : public Resource
{
public:
	// Inherited via Resource
	virtual void load(const std::string& path) override;
	virtual void dispose() override;

	// Bind shader to state machine
	void bind() const;

	// Unbind shader from state machine
	void unbind() const;

	/**
	 *
	 * Sets the value of a boolean uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param value - Boolean value to set
	 */
	void setBool(const std::string& name, bool value);

	/**
	 *
	 * Sets the value of an integer uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param value - Integer value to set
	 */
	void setInt(const std::string& name, int value);

	/**
	 *
	 * Sets the value of a floating point uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param value - Floating point value to set
	 */
	void setFloat(const std::string& name, float value);

	/**
	 *
	 * Sets the value of a two dimensional vector uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param x, y - Components of the vector to set
	 */
	void setVec2(const std::string& name, float x, float y);

	/**
	 *
	 * Sets the value of a two dimensional vector uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param value - Vector value to set
	 */
	void setVec2(const std::string& name, const glm::vec2& value);

	/**
	 *
	 * Sets the value of a three dimensional vector uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param x, y, z - Components of the vector to set
	 */
	void setVec3(const std::string& name, float x, float y, float z);

	/**
	 *
	 * Sets the value of a three dimensional vector uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param value - Vector value to set
	 */
	void setVec3(const std::string& name, const glm::vec3& value);

	/**
	 *
	 * Sets the value of a three dimensional vector uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param x, y, z, w - Components of the vector to set
	 */
	void setVec4(const std::string& name, float x, float y, float z, float w);

	/**
	 *
	 * Sets the value of a four dimensional vector uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param value - Vector value to set
	 */
	void setVec4(const std::string& name, const glm::vec4& value);

	/**
	 *
	 * Sets the value of a 2x2 matrix uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param value - Matrix value to set
	 */
	void setMat2(const std::string& name, const glm::mat2& value);

	/**
	 *
	 * Sets the value of a 3x3 matrix uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param value - Matrix value to set
	 */
	void setMat3(const std::string& name, const glm::mat3& value);

	/**
	 *
	 * Sets the value of a 4x4 matrix uniform given the uniform name
	 *
	 * @param name - Name of uniform to set
	 * @param value - Matrix value to set
	 */
	void setMat4(const std::string& name, const glm::mat4& value);

private:
	// OpenGL shader program ID
	unsigned int m_ID;

	// Shader source strings
	ShaderSource m_source;

	// Splits shader file into vertex and fragment strings
	void parseShader();

	// Compiles the shader program
	void compileShader();

	int getUniformLocation(const std::string& name);
};
