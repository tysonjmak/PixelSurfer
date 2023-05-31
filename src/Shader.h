#pragma once

#include <GL/glew.h>
#include <string>

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

	void parseShader();
	void compileShader();

public:
	Shader(const char* file_path);

	void bind() const;
	void unbind() const;
};
