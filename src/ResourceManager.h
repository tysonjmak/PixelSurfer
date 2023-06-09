#pragma once

#include <iostream>
#include <unordered_map>
#include <memory>

#include "Resource.h"

class ResourceManager
{
public:
	template <typename T>
	static void load(const std::string& path)
	{
		static_assert(std::is_base_of<Resource, T>::value, "ERROR: T must inherit type \"Resource\"");

		if (m_resources.find(path) == m_resources.end())
		{
			T* resource = new T;
			resource->load(path);

			m_resources.emplace(path, resource);

			std::cout << "    Loaded resource: " << path << std::endl;
		}
	}

	template <typename T>
	static T* get(const std::string& path)
	{
		return dynamic_cast<T*>(m_resources[path]);
	}

	static void dispose();

//private:
	static std::unordered_map<std::string, Resource*> m_resources;
};
