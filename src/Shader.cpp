#include <fstream>
#include <sstream>
#include <iostream>

#include "Shader.h"

enum class ShaderType
{
	NONE = -1,
	VERTEX = 0,
	FRAGMENT = 1
};

Shader::Shader(const char* file_path)
	: m_file_path(file_path), m_ID(0)
{
	parseShader();
	compileShader();
}

void Shader::bind() const
{
	glUseProgram(m_ID);
}

void Shader::unbind() const
{
	glUseProgram(0);
}

void Shader::parseShader()
{
	std::fstream shader_file;
	std::stringstream vertex_stream;
	std::stringstream fragment_stream;
	ShaderType type = ShaderType::NONE;

	shader_file.open(m_file_path, std::ios::in);
	if (shader_file.is_open())
	{
		std::string line;
		
		while (getline(shader_file, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
					type = ShaderType::VERTEX;
				else if (line.find("fragment") != std::string::npos)
					type = ShaderType::FRAGMENT;
			}
			else
			{
				if (type == ShaderType::VERTEX)
					vertex_stream << line << "\n";
				else if (type == ShaderType::FRAGMENT)
					fragment_stream << line << "\n";
			}
		}

		m_vertex_string = vertex_stream.str();
		m_fragment_string = fragment_stream.str();
	}
	else
	{
		std::cout << "ERROR: Could not open file at path: " << m_file_path << std::endl;
	}
	shader_file.close();
}

void Shader::compileShader()
{
	const char* vertex_source = m_vertex_string.c_str();
	const char* fragment_source = m_fragment_string.c_str();
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	// Vertex shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vertex_source, NULL);
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR: Vertex shader compilation failed at path: " << m_file_path << "\n" << infoLog << std::endl;
	}

	// Fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragment_source, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR: Fragment shader compilation failed at path: " << m_file_path << "\n" << infoLog << std::endl;
	}

	// Shader program
	m_ID = glCreateProgram();
	glAttachShader(m_ID, vertex);
	glAttachShader(m_ID, fragment);
	glLinkProgram(m_ID);
	glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(m_ID, 512, NULL, infoLog);
		std::cout << "ERROR: Shader program linking failed at path: " << m_file_path << "\n" << infoLog << std::endl;
	}

	// Delete shaders after use
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}
