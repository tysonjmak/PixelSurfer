#pragma once

#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>

class Shader
{
private:
	// File path to shader source
	const char* m_file_path;

	// OpenGL shader program ID
	unsigned int m_ID;

	// Shader source strings
	std::string m_vertex_string;
	std::string m_fragment_string;

	// Splits shader file into vertex and fragment strings
	void parseShader();

	// Compiles the shader program
	void compileShader();

	int getUniformLocation(const std::string& name);

public:
	/**
	 *
	 * Creates a shader program from the specified file path.
	 * All shaders are combined into one file to parse.
	 *
	 * @param file_path - Path to shader from project directory
	 */
	Shader(const char* file_path);

	// Bind shader to state machine
	void bind() const;

	// Unbind shader from state machine
	void unbind() const;

	// Uniform utilities

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

};
