#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <memory>

namespace Snake
{
	class TexturesManager
	{
	public:
		TexturesManager();
		~TexturesManager();

		bool loadTexture(const std::string& name, const std::string& path);
		void unloadTexture(const std::string& name);
		sf::Texture* getTexture(const std::string& name);
		bool textureExist(const std::string& name);

	private:
		std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
	};
};
