#pragma once

#include <Snake/ResourceManagement/ResourceManagerException.hpp>
#include <Snake/ResourceManagement/ResourceManagerCouldNotLoadResourceException.hpp>
#include <string>
#include <map>
 
namespace Snake
{
	template <class T>
	class ResourceManager
	{
	public:
		ResourceManager();
		
		T& getResource(const std::string& path);
		void freeResource(const std::string& path);
		bool resourceLoaded(const std::string& path);

	private:
		std::map<std::string, T> resources;

	};
}
