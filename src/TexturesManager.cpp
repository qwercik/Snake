#include <Snake/TexturesManager.hpp>

namespace Snake
{
	TexturesManager::TexturesManager()
	{

	}

	TexturesManager::~TexturesManager()
	{

	}

	bool TexturesManager::loadTexture(const std::string& name, const std::string& path)
	{
		if (textureExist(name))
		{
			if (!textures[name]->loadFromFile(path))
				return false;
		}
		else
		{
			std::unique_ptr<sf::Texture> texture(new sf::Texture());
			if (!texture->loadFromFile(path))
				return false;

			textures[name] = std::move(texture);
		}

		return true;
	}

	void TexturesManager::unloadTexture(const std::string& name)
	{
		if (textureExist(name))
			textures.erase(textures.find(name));
	}

	sf::Texture* TexturesManager::getTexture(const std::string& name)
	{
		if (textureExist(name))
			return textures[name].get();
		
		return nullptr;
	}

	bool TexturesManager::textureExist(const std::string& name)
	{
		return textures.find(name) != textures.end(); 
	}

};
