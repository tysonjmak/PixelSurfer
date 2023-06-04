#pragma once

#include <unordered_map>
#include <memory>

#include "Shader.h"

class ResourceManager
{
public:
	static void load(Resource* resource, const std::string& path, const std::string& name);

	template <typename T>
	static T* get(const std::string& name)
	{
		return dynamic_cast<T*>(m_resources.find(name)->second);
	}

	static void dispose();

//private:
	static std::unordered_map<std::string, Resource*> m_resources;
};
