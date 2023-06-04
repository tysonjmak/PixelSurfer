#include <iostream>

#include "ResourceManager.h"

std::unordered_map<std::string, Resource*> ResourceManager::m_resources;

void ResourceManager::load(Resource* resource, const std::string& path, const std::string& name)
{
	resource->load(path);
	m_resources.emplace(name, resource);
	std::cout << "INFO: Loaded resource \"" << name << "\" at path: " << path << std::endl;
}

void ResourceManager::dispose()
{
	std::cout << "INFO: Disposing ResourceManager:" << std::endl;

	for (auto const& resource : m_resources)
	{
		std::string name = resource.first;
		std::string path = resource.second->getPath();

		resource.second->dispose();
		delete resource.second;

		std::cout << "    Unloaded resource \"" << name << "\" at path: " << path << std::endl;
	}
}
