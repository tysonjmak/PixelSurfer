#pragma once

#include <unordered_map>

#include "Shader.h"

class ResourceManager
{
public:
	template <typename T>
	static std::shared_ptr<T> load(const std::string& path)
	{
		static_assert(std::is_base_of<Resource, T>::value, "ERROR: T must inherit type \"Resource\"");

		auto resource = m_resources[path].lock();
		if (!resource)
		{
			m_resources[path] = resource = std::make_shared<T>();
			resource->load(path);

			std::cout << "INFO: Loaded resource: " << path << std::endl;
		}

		auto return_value = std::dynamic_pointer_cast<T>(resource);
		if (!return_value)
		{
			throw std::runtime_error("ERROR: Resource \"" + path + "\" is already loaded as another type.");
		}

		return return_value;
	}

	static void dispose();

//private:
	static std::unordered_map<std::string, std::weak_ptr<Resource>> m_resources;
};
