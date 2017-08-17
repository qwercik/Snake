#include <Snake/ResourceManagement/ResourceManager.hpp>
#include <SFML/Graphics.hpp>

namespace Snake
{
	template <class T>
	ResourceManager<T>::ResourceManager()
	{
	}

	template <class T>
	T& ResourceManager<T>::getResource(const std::string& path)
	{
		if (resources.find(path) == resources.end())
		{
			if (!resources[path].loadFromFile(path))
				throw ResourceManagerCouldNotLoadResourceException("Couldn\'t load resource from file " + path);
		}

		return resources[path];
	}
	
	template <class T>
	void ResourceManager<T>::freeResource(const std::string& path)
	{
		auto iterator = resources.find(path);

		if (iterator != resources.end())
			resources.erase(iterator);
	}

	template <class T>
	bool ResourceManager<T>::resourceLoaded(const std::string& path)
	{
		return resources.find(path) != resources.end();
	}

	template class ResourceManager<sf::Font>;
	template class ResourceManager<sf::Texture>; 
}
