#include "Shader.h"

enum class ShaderType
{
	NONE = -1,
	VERTEX = 0,
	FRAGMENT = 1
};

void Shader::load(const std::string& path)
{
	m_path = path;
	parseShader();
	compileShader();
}

void Shader::dispose()
{
	glDeleteShader(m_ID);
}

void Shader::bind() const
{
	glUseProgram(m_ID);
}

void Shader::unbind() const
{
	glUseProgram(0);
}

void Shader::setBool(const std::string& name, bool value)
{
	glUniform1i(getUniformLocation(name), value);
}

void Shader::setInt(const std::string& name, int value)
{
	glUniform1i(getUniformLocation(name), value);
}

void Shader::setFloat(const std::string& name, float value)
{
	glUniform1f(getUniformLocation(name), value);
}

void Shader::setVec2(const std::string& name, float x, float y)
{
	glUniform2f(getUniformLocation(name), x, y);
}

void Shader::setVec2(const std::string& name, const glm::vec2& value)
{
	glUniform2fv(getUniformLocation(name), 1, &value[0]);
}

void Shader::setVec3(const std::string& name, float x, float y, float z)
{
	glUniform3f(getUniformLocation(name), x, y, z);
}

void Shader::setVec3(const std::string& name, const glm::vec3& value)
{
	glUniform3fv(getUniformLocation(name), 1, &value[0]);
}

void Shader::setVec4(const std::string& name, float x, float y, float z, float w)
{
	glUniform4f(getUniformLocation(name), x, y, z, w);
}

void Shader::setVec4(const std::string& name, const glm::vec4& value)
{
	glUniform4fv(getUniformLocation(name), 1, &value[0]);
}

void Shader::setMat2(const std::string& name, const glm::mat2& value)
{
	glUniformMatrix2fv(getUniformLocation(name), 1, GL_FALSE, &value[0][0]);
}

void Shader::setMat3(const std::string& name, const glm::mat3& value)
{
	glUniformMatrix3fv(getUniformLocation(name), 1, GL_FALSE, &value[0][0]);
}

void Shader::setMat4(const std::string& name, const glm::mat4& value)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &value[0][0]);
}

void Shader::parseShader()
{
	std::fstream shader_file;
	std::stringstream vertex_stream;
	std::stringstream fragment_stream;
	ShaderType type = ShaderType::NONE;

	shader_file.open(m_path, std::ios::in);
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

		m_source.vertex = vertex_stream.str();
		m_source.fragment = fragment_stream.str();
	}
	else
	{
		std::cout << "ERROR: Could not open file at path: " << m_path << std::endl;
	}
	shader_file.close();
}

void Shader::compileShader()
{
	const char* vertex_source = m_source.vertex.c_str();
	const char* fragment_source = m_source.fragment.c_str();
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
		std::cout << "ERROR: Vertex shader compilation failed at path: " << m_path << "\n" << infoLog << std::endl;
	}

	// Fragment shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fragment_source, NULL);
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR: Fragment shader compilation failed at path: " << m_path << "\n" << infoLog << std::endl;
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
		std::cout << "ERROR: Shader program linking failed at path: " << m_path << "\n" << infoLog << std::endl;
	}

	// Delete shaders after use
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

int Shader::getUniformLocation(const std::string& name)
{
	int location = glGetUniformLocation(m_ID, name.c_str());

	if (location == -1)
		std::cout << "WARNING: Uniform \"" << name << "\" does not exist for shader at path: " << m_path << std::endl;

	return location;
}
