#include <iostream>

#include "ResourceManager.h"

std::unordered_map<std::string, std::weak_ptr<Resource>> ResourceManager::m_resources;

void ResourceManager::dispose()
{
	std::cout << "INFO: Disposing ResourceManager:" << std::endl;

	for (auto const& resource : m_resources)
	{
		auto value = resource.second.lock();
		if (value)
		{
			std::string path = value->getPath();
			value->dispose();

			std::cout << "    Unloaded resource: " << path << std::endl;
		}
	}
}
