#pragma once

#include <string>

class Resource
{
public:
	virtual void load(const std::string& path) = 0;
	virtual void dispose() = 0;

	std::string getPath() const
	{
		return m_path;
	}

protected:
	std::string m_path;
};
