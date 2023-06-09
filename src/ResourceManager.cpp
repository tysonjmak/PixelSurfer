#include <iostream>

#include "ResourceManager.h"

std::unordered_map<std::string, Resource*> ResourceManager::m_resources;

void ResourceManager::dispose()
{
	std::cout << "INFO: Disposing resources:" << std::endl;

	std::unordered_map<std::string, Resource*>::iterator itr;
	for (itr = m_resources.begin(); itr != m_resources.end(); itr++)
	{
		delete itr->second;
		std::cout << "    Unloaded resource: " << itr->first << std::endl;
	}
}
