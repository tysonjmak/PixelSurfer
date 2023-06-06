#pragma once

#include <string>

class Resource
{
public:
	virtual ~Resource() { }

	virtual void load(const std::string& path) = 0;
	virtual void dispose() = 0;

	inline std::string getPath() const
	{
		return m_path;
	}

protected:
	std::string m_path;
};
